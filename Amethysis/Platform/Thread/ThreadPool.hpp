// 线程池类，该类不是接口，直接使用
// Created by Loturias on 25-2-14.
//
#pragma once

#include "../../SharedHeaders.hpp"

namespace Amethysis::Platform::Thread {
	enum class ThreadPoolStatus
	{
		UNINITIALIZED, // 未初始化
		INITIALIZED, // 已初始化
		RUNNING, // 运行中
		STOPPED, // 已停止
		DESTROYING, // 正在销毁，用于标识线程池正在销毁中
		DESTROYED // 已销毁
	};

	struct ThreadPool final
	{
	private:
		unsigned int thread_num = 0; // 线程数
		ThreadPoolStatus status = ThreadPoolStatus::UNINITIALIZED; // 线程池状态
		std::queue<std::function<void()>> task_queue{}; // 任务队列
		std::vector<std::thread> workers{}; // 线程列表
		std::mutex queue_mutex{}; // 互斥锁，用于保护任务队列的读写
		std::condition_variable condition{}; // 条件变量，用于线程同步
		bool stop = false; // 标记线程池是否需要停止

		/// 设置线程池状态，该方法仅供内部调用
		/// @param new_status 线程池切换的目标状态
		void set_status(const ThreadPoolStatus new_status) { this->status = new_status; }
	public:
		ThreadPool() = default;
		~ThreadPool() = default;

		/// 获取线程池状态
		/// @return 线程池状态
		[[nodiscard]] ThreadPoolStatus get_status() const { return status; }

		/// 初始化线程池
		void OnInit(unsigned int init_thread_num);

		/// 销毁线程池
		void OnDestroy();

		/// 向线程池提交任务-无参数
		/// @tparam Func 函数模板
		/// @param func 函数对象
		/// @return 返回任务执行结果的future对象
		template<class Func>
		auto SubmitTask(Func&& func) -> std::future<std::invoke_result_t<Func>>
		{
			// 检查线程池状态
			switch (status)
			{
				case ThreadPoolStatus::UNINITIALIZED:
					throw std::runtime_error("ThreadPool is not initialized.");
				case ThreadPoolStatus::DESTROYING:
					throw std::runtime_error("ThreadPool is destroying.");
				case ThreadPoolStatus::DESTROYED:
					throw std::runtime_error("ThreadPool is already destroyed");
				default:
					break;
			}


			// 推导任务返回类型
			using return_type = std::result_of_t<Func()>;
			auto task = std::make_shared<std::packaged_task<return_type()>>(
				std::bind(std::forward<Func>(func))
			);
			std::future<return_type> res = task->get_future();
			{
				std::unique_lock lock(queue_mutex);
				if (stop) {
					throw std::runtime_error("SubmitTask on stopped ThreadPool");
				}
				task_queue.emplace([task] { (*task)(); });
			}
			// 唤醒一个等待的线程
			condition.notify_one();
			return res;
		}

		/// 向线程池提交任务-有参数
		/// @tparam Func 函数模板
		/// @tparam Args 变参模板
		/// @param func 函数对象
		/// @param args 函数参数
		/// @return 返回任务执行结果的future对象
		template<class Func, class... Args>
		auto SubmitTask(Func&& func, Args&&... args) -> std::future<std::invoke_result_t<Func,Args...>>
		{
			// 检查线程池状态
			switch (status)
			{
				case ThreadPoolStatus::UNINITIALIZED:
					throw std::runtime_error("ThreadPool is not initialized.");
				case ThreadPoolStatus::DESTROYING:
					throw std::runtime_error("ThreadPool is destroying.");
				case ThreadPoolStatus::DESTROYED:
					throw std::runtime_error("ThreadPool is already destroyed");
				default:
					break;
			}

			// 推导任务返回类型
			using return_type = std::invoke_result_t<Func,Args...>;
			auto task = std::make_shared<std::packaged_task<return_type()>>(
				std::bind(std::forward<Func>(func), std::forward<Args>(args)...)
			);
			std::future<return_type> res = task->get_future();
			{
				std::unique_lock lock(queue_mutex);
				if (stop) {
					throw std::runtime_error("SubmitTask on stopped ThreadPool");
				}
				task_queue.emplace([task] { (*task)(); });
			}
			// 唤醒一个等待的线程
			condition.notify_one();
			return res;
		}

	};
}

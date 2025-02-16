// 线程池方法实现
// Created by Loturias on 25-2-14.
//

#include "ThreadPool.hpp"

namespace Amethysis::Platform::Thread {
	void ThreadPool::OnInit(const unsigned int init_thread_num)
	{
		if (status != ThreadPoolStatus::UNINITIALIZED)
		{
			throw std::runtime_error("ThreadPool is already initialized.");
		}
		this->thread_num = init_thread_num;
		workers.reserve(init_thread_num);
		for (unsigned int i = 0; i < init_thread_num; ++i)
		{
			workers.emplace_back([this]
				{
					while (true)
					{
						std::function<void()> task;
						{
							std::unique_lock lock(queue_mutex);
							condition.wait(lock, [this] { return stop || !task_queue.empty(); });
							if (stop && task_queue.empty())
							{
								return;
							}
							task = std::move(task_queue.front());
							task_queue.pop();
						}
						set_status(ThreadPoolStatus::RUNNING);
						task();
					}
				});
		}

		set_status(ThreadPoolStatus::INITIALIZED);
		spdlog::info("Thread Pool initialized.Thread num:{}", init_thread_num);
	}

	void ThreadPool::OnDestroy()
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

		// 设置线程池状态
		set_status(ThreadPoolStatus::DESTROYING);

        {
            std::unique_lock lock(queue_mutex);
            stop = true;
        }

		condition.notify_all();

		// 等待所有线程结束
		for (std::thread &worker : workers)
        {
            worker.join();
        }

		set_status(ThreadPoolStatus::DESTROYED);

		spdlog::info("ThreadPool destroyed.");
	}

}


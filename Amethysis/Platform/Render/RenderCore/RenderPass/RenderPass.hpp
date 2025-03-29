// 单次渲染流程结构接口
// Created by Loturias on 25-3-18.
#pragma once
#include "../../Resources/Resource.hpp"

namespace Amethysis::Platform::Render
{
    ///@brief RenderPass抽象定义
    ///@note 纯定义结构，不包括执行实现，最终将由RenderCycle进行驱动
    struct RenderPass
    {
        ///@brief 渲染流程名称
        std::string Name;
        ///@brief 渲染流程类型
        std::string Type;
        ///@brief 顶点着色器
        Shader* VertexS = nullptr;
        ///@brief 曲面细分着色器
        Shader* HullS = nullptr;
        ///@brief 域着色器
        Shader* DomainS = nullptr;
        ///@brief 几何着色器
        Shader* GeometryS = nullptr;
        ///@brief 像素着色器
        Shader* PixelS = nullptr;

        ///@brief 该Pass所引用的RenderTarget列表
        std::unordered_map<std::string,RenderTarget*> RTs{};
        ///@brief Pass的输出RenderTarget
        RenderTarget* OutputRT{};
        ///@brief 作为深度模板缓冲的RenderTarget
        RenderTarget* DS{};

        ///@TODO 定义Pass所需的各种参数，CBV，SRV，UAV等

    };
}

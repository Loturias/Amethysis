// 渲染流程图
// 采用AOV网描述拓扑结构
// Created by Loturias on 25-3-18.
#pragma once
#include "../RenderPass/RenderPass.hpp"

// 需求：动态解析Pass依赖关系，构造拓扑序列，提供给RenderCycle进行调度
// 例如，Pass1和Pass2都需要对同一个RenderTarget进行操作，调度需要保证Pass2必须在Pass1完成之后再启动

namespace Amethysis::Platform::Render
{
    struct RenderGraph
    {

    };
}

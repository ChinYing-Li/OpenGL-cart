#include "renderpass.h"

namespace Cluster
{
RenderPass::
RenderPass(const std::string& passname) :
  m_width(1),
  m_height(1),
  m_pass_name(passname),
  m_capabilities(RenderState::get_default_settings())
{}

void RenderPass::
resize(const unsigned int width, const unsigned int height)
{
  m_width = width;
  m_height = height;
}

void RenderPass::
enable() noexcept
{
  m_enabled = true;
}

void RenderPass::
disable() noexcept
{
  m_enabled = false;
}

bool RenderPass::
is_enabled() const noexcept
{
  return m_enabled;
}

std::string RenderPass::
get_pass_name() const noexcept
{
  return m_pass_name;
}

void RenderPass::
set_render_target(Texture2D* target)
{
  m_render_target = target;
}
}

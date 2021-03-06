#pragma once

#include "glfoundation/shader.h"
#include "renderpass.h"

namespace Cluster
{
class GammaCorrectPass : public RenderPass
{
public:
  GammaCorrectPass();

  void resize(const unsigned int width, const unsigned int height) override {};
  void render(RenderState& r_state, const Scene& scene) override;

  void set_gamma(const float gamma);

  static const std::string m_pass_name;

private:
  float m_gamma;
  Shader m_shader;
};

}

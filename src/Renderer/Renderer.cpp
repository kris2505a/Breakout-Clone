#include "Renderer.h"
#include "RenderAPI.h"

std::unique_ptr <RenderAPI> Renderer::s_renderAPI = nullptr;


void Renderer::init(int width, int height, HWND handle)
{
	s_renderAPI = std::make_unique<RenderAPI>(width, height, handle);
}

void Renderer::cleanup()
{
}

void Renderer::preRender()
{
	s_renderAPI->setRenderTarget();
	s_renderAPI->clearRenderTarget();
	s_renderAPI->setDepthStencilState();
	s_renderAPI->clearDepthStencil();
	s_renderAPI->setViewPort();
	s_renderAPI->setPrimitiveTopology();
}

void Renderer::postRender()
{
	s_renderAPI->swapBuffers();
}

void Renderer::setClearColor(float r, float g, float b, float a)
{
	s_renderAPI->getClearColor() = { r, g, b, a };
}

ID3D11Device* Renderer::getDevice()
{
	return s_renderAPI->getDevice();
}

ID3D11DeviceContext* Renderer::getContext()
{
	return s_renderAPI->getContext();
}

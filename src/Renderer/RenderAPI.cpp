#include "RenderAPI.h"
#include <stdexcept>

RenderAPI::RenderAPI(int renderWidth, int renderHeight, HWND handle) {
    m_renderWidth = renderWidth;
    m_renderHeight = renderHeight;
	p_handle = handle;
	m_clearColor = { 0.0f, 0.0f, 0.0f, 1.0f };
	m_viewPort = {};

	createDeviceSwapChain();
	createRenderTargetView();
	createDepthStencilState();
	createDepthStencilView();
	createViewPort();
	createRasterizerState();
	createSamplerState();
}


void RenderAPI::createDeviceSwapChain() 
{
	DXGI_SWAP_CHAIN_DESC sd = {};
	sd.BufferDesc.Width = 0;
	sd.BufferDesc.Height = 0;
	sd.BufferDesc.RefreshRate.Numerator = 0;
	sd.BufferDesc.RefreshRate.Denominator = 0;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.BufferCount = 2;
	sd.OutputWindow = p_handle;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.Windowed = true;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	unsigned int debugFlags = 0;

#ifdef _DEBUG
	debugFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // _DEBUG

	auto hr = D3D11CreateDeviceAndSwapChain(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		debugFlags,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&sd,
		&m_swapchain,
		&m_device,
		nullptr,
		&m_context
	);

	if (FAILED(hr)) {
		throw std::runtime_error("Failed to create device and swapchain!");
	}
}

void RenderAPI::createRenderTargetView() 
{
	Microsoft::WRL::ComPtr<ID3D11Texture2D> pBackBuffer;
	m_swapchain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
	D3D11_TEXTURE2D_DESC bbDesc;
	pBackBuffer->GetDesc(&bbDesc);
	m_renderWidth = bbDesc.Width;
	m_renderHeight = bbDesc.Height;
	auto hr = m_device->CreateRenderTargetView(pBackBuffer.Get(), nullptr, &m_targetView);

	if (FAILED(hr)) {
		throw std::runtime_error("Failed to create render target view!");
	}
}


void RenderAPI::createViewPort() 
{
	m_viewPort.TopLeftX = 0;
	m_viewPort.TopLeftY = 0;
	m_viewPort.Width = static_cast <float>(m_renderWidth);
	m_viewPort.Height = static_cast <float>(m_renderHeight);
	m_viewPort.MinDepth = 0.0f;
	m_viewPort.MaxDepth = 1.0f;
}

void RenderAPI::createDepthStencilState() 
{
	D3D11_DEPTH_STENCIL_DESC dsd = {};
	dsd.DepthEnable = TRUE;
	dsd.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	dsd.DepthFunc = D3D11_COMPARISON_LESS;
	dsd.StencilEnable = FALSE;

	auto hr = m_device->CreateDepthStencilState(&dsd, &m_stencilState);

	if (FAILED(hr)) {
		throw std::runtime_error("failed to create depth stencil state!");
	}
}

void RenderAPI::createDepthStencilView() 
{
	D3D11_TEXTURE2D_DESC td = {};
	td.Width = m_renderWidth;
	td.Height = m_renderHeight;
	td.MipLevels = 1;
	td.ArraySize = 1;
	td.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	td.SampleDesc.Quality = 0;
	td.SampleDesc.Count = 1;
	td.Usage = D3D11_USAGE_DEFAULT;
	td.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	td.CPUAccessFlags = 0;
	td.MiscFlags = 0;

	Microsoft::WRL::ComPtr <ID3D11Texture2D> depthTexture;
	m_device->CreateTexture2D(&td, nullptr, &depthTexture);

	D3D11_DEPTH_STENCIL_VIEW_DESC dsvd = {};
	dsvd.Format = td.Format;
	dsvd.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	dsvd.Texture2D.MipSlice = 0;

	auto hr = m_device->CreateDepthStencilView(depthTexture.Get(), &dsvd, &m_stencilView);
	if (FAILED(hr)) {
		throw std::runtime_error("failed to create depth stencil view!");
	}
}

void RenderAPI::createRasterizerState() 
{
	D3D11_RASTERIZER_DESC rd{};
	rd.DepthClipEnable = true;
	rd.FrontCounterClockwise = false;
	rd.FillMode = D3D11_FILL_SOLID;
	rd.CullMode = D3D11_CULL_NONE;

	auto hr = m_device->CreateRasterizerState(&rd, m_rasterizerState.GetAddressOf());
	if (FAILED(hr)) {
		throw std::runtime_error("failed to create rasterizer state!");
	}

	m_context->RSSetState(m_rasterizerState.Get());
}

void RenderAPI::createSamplerState() 
{
	D3D11_SAMPLER_DESC sd{};
	sd.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	sd.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	sd.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	sd.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;

	auto hr = m_device->CreateSamplerState(&sd, m_samplerState.GetAddressOf());
	if (FAILED(hr)) {
		throw std::runtime_error("unable to create sampler state!");
	}
	
	m_context->PSSetSamplers(0, 1, m_samplerState.GetAddressOf());
}

ID3D11Device* RenderAPI::getDevice() const
{
	return m_device.Get();
}

ID3D11DeviceContext* RenderAPI::getContext() const
{
	return m_context.Get();
}

std::array<float, 4>& RenderAPI::getClearColor()
{
	return m_clearColor;
}

void RenderAPI::setRenderTarget()
{
	ID3D11RenderTargetView* rtvs[] = { m_targetView.Get() };
	m_context->OMSetRenderTargets(1, rtvs, m_stencilView.Get());
}

void RenderAPI::setDepthStencilState()
{
	m_context->OMSetDepthStencilState(m_stencilState.Get(), 0);
}

void RenderAPI::setViewPort()
{
	m_context->RSSetViewports(1, &m_viewPort);
}

void RenderAPI::setPrimitiveTopology()
{
	m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}

void RenderAPI::clearRenderTarget()
{
	m_context->ClearRenderTargetView(m_targetView.Get(), m_clearColor.data());
}

void RenderAPI::clearDepthStencil()
{
	m_context->ClearDepthStencilView(m_stencilView.Get(), D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void RenderAPI::swapBuffers()
{
	m_swapchain->Present(1, 0);
}

void RenderAPI::drawIndexed(unsigned int count)
{
	m_context->DrawIndexed(count, 0, 0);
}

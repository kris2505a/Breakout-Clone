#pragma once
#include <d3d11.h>
#include <wrl/client.h>
#include <array>

class RenderAPI 
{
public:
    RenderAPI(int renderWidth, int renderHeight, HWND handle);
    ~RenderAPI() = default;
    friend class Renderer;

private:
    void createDeviceSwapChain();
    void createRenderTargetView();
    void createViewPort();
    void createDepthStencilState();
    void createDepthStencilView();
    void createRasterizerState();
    void createSamplerState();
    ID3D11Device* getDevice() const;
    ID3D11DeviceContext* getContext() const;
    std::array<float, 4>& getClearColor();

    void drawIndexed(unsigned int count);
    void setRenderTarget();
    void setDepthStencilState();
    void setViewPort();
    void setPrimitiveTopology();
    void clearRenderTarget();
    void clearDepthStencil();
    void swapBuffers();
    
private:
    Microsoft::WRL::ComPtr <ID3D11DeviceContext>        m_context;
    Microsoft::WRL::ComPtr <ID3D11Device>               m_device;
    Microsoft::WRL::ComPtr <IDXGISwapChain>             m_swapchain;  
    Microsoft::WRL::ComPtr <ID3D11RenderTargetView>     m_targetView;
    Microsoft::WRL::ComPtr <ID3D11DepthStencilView>     m_stencilView;
    Microsoft::WRL::ComPtr <ID3D11DepthStencilState>    m_stencilState;
    Microsoft::WRL::ComPtr <ID3D11RasterizerState>      m_rasterizerState;
    Microsoft::WRL::ComPtr <ID3D11SamplerState>         m_samplerState;
    std::array <float, 4>                               m_clearColor;
    D3D11_VIEWPORT                                      m_viewPort;
    HWND                                                p_handle;
    int                                                 m_renderWidth;
    int                                                 m_renderHeight;
};
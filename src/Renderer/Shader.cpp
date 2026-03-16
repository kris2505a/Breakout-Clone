#include "Shader.h"
#include <iostream>
#include "Renderer.h"
#include <d3dcompiler.h>


Shader::Shader(const std::wstring& vsPath, const std::wstring& psPath) 
{

    D3DReadFileToBlob(vsPath.c_str(), &m_blobs.vsBlob);
    D3DReadFileToBlob(psPath.c_str(), &m_blobs.psBlob);

    Renderer::getDevice()->CreateVertexShader(
		m_blobs.vsBlob->GetBufferPointer(),
		m_blobs.vsBlob->GetBufferSize(),
		nullptr,
		m_vertexShader.GetAddressOf()
	);
	Renderer::getDevice()->CreatePixelShader(
		m_blobs.psBlob->GetBufferPointer(),
		m_blobs.psBlob->GetBufferSize(),
		nullptr,
		m_pixelShader.GetAddressOf()
	);
}

void Shader::bind() const 
{
	Renderer::getContext()->VSSetShader(m_vertexShader.Get(), nullptr, 0);
	Renderer::getContext()->PSSetShader(m_pixelShader.Get(), nullptr, 0);
}

const Blobs* Shader::blobs() const 
{
    return &m_blobs;
}


#include "InputLayout.h"
#include "Renderer.h"


InputLayout::InputLayout(const Blobs* blobs)
	: p_blobs(blobs) {}

void InputLayout::bind() const 
{
	Renderer::getContext()->IASetInputLayout(m_layout.Get());
}

void InputLayout::addLayout(D3D11_INPUT_ELEMENT_DESC desc) 
{
	m_layouts.push_back(std::move(desc));
}

void InputLayout::createLayout() 
{
	Renderer::getDevice()->CreateInputLayout(
		m_layouts.data(),
		m_layouts.size(),
		p_blobs->vsBlob->GetBufferPointer(),
		p_blobs->vsBlob->GetBufferSize(),
		m_layout.GetAddressOf()
	);
}


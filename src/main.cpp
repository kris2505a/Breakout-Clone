#include "Engine/Window.h"
#include "Renderer/Renderer.h"
#include "Renderer/Vertex3.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/IndexBuffer.h"
#include "Renderer/InputLayout.h"
#include "Renderer/Shader.h"
#include "Renderer/ConstantBuffer.h"

#include <vector>

int main() {
	Window window(1600, 900, "Breakout");
	Renderer::init(1600, 900, window.getWindowHandle());
	Renderer::setClearColor(0, 0, 1, 1);

	std::vector <Vertex3> vertices{
		{{-0.5f, -0.5f, 0.0f}},
		{{-0.5f,  0.5f, 0.0f}},
		{{ 0.5f, -0.5f, 0.0f}},
		{{ 0.5f,  0.5f, 0.0f}}
	};

	VertexBuffer vbo(vertices.data(), vertices.size(), sizeof(Vertex3));

	std::vector <uint32_t> indices{
		0, 1, 2,
		1, 3, 2
	};

	IndexBuffer ibo(indices.data(), indices.size());

	Shader shader(L"shaders/DefVS.cso", L"shaders/DefPS.cso");
	InputLayout ilo(shader.blobs());
	ilo.addLayout({
		"POSITION", 
		0, 
		DXGI_FORMAT_R32G32B32_FLOAT, 
		0, 
		0, 
		D3D11_INPUT_PER_VERTEX_DATA, 
		0
	});

	ilo.createLayout();

	vbo.bind();
	ibo.bind();
	shader.bind();
	ilo.bind();

	DirectX::XMMATRIX model, view, proj;
	model = DirectX::XMMatrixIdentity();
	view = DirectX::XMMatrixLookAtLH(
		DirectX::XMVectorSet(0, 0, -5, 1),
		DirectX::XMVectorSet(0, 0, 0, 1),
		DirectX::XMVectorSet(0, 1, 0, 0)
	);

	proj = DirectX::XMMatrixOrthographicLH(2.0f, 2.0f * 9.0f / 16.0f , 0.1f, 10.0f);

	auto mat = DirectX::XMMatrixTranspose(model * view * proj);
	
	ConstantBuffer cbo(&mat, sizeof(mat), ShaderType::VertexShader);
	cbo.bind();

	while (window.isOpen()) {
		Renderer::preRender();

		Renderer::getContext()->DrawIndexed(6, 0, 0);

		Renderer::postRender();
		window.pollEvent();
	}

	Renderer::cleanup();

}

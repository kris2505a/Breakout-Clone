#pragma once
#include <memory>
#include <Windows.h>
#include <d3d11.h>

//class RenderAPI;

class Renderer 
{
	friend class RenderAPI;
public:
	static void init(int width, int height, HWND handle);
	static void cleanup();
	static void preRender();
	static void postRender();
	static void setClearColor(float r, float g, float b, float a);
	static ID3D11Device* getDevice();
	static ID3D11DeviceContext* getContext();


private:
	static std::unique_ptr <RenderAPI> s_renderAPI;
};
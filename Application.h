#pragma once

#include "opencv2/opencv.hpp"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>
#include "ImageProcessing.h"

static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


class Application
{
public:
	Application();
	~Application();
	cv::Mat run(const cv::Mat processedImage);
	void initialize();
	void run();

private:
	const cv::Size WINDOWSIZE = cv::Size(200, 800);
	HWND hwnd;
	LPDIRECT3D9 pD3D;
	WNDCLASSEX wc;

};


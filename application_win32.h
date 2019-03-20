#pragma once


#ifdef _MSC_VER
#include "opencv2/opencv.hpp"
#include "imgui/imgui.h"



#include "imgui/imgui_impl_dx9.h"
#include "imgui/imgui_impl_win32.h"
#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>

#include "application.h"
#include "image_processing.h"

static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


class ApplicationWin32 : public Application
{
public:
	ApplicationWin32();
	~ApplicationWin32();
	void initialize() override;

private:
	const cv::Size WINDOWSIZE = cv::Size(200, 800);
	HWND hwnd;
	LPDIRECT3D9 pD3D;
	WNDCLASSEX wc;
    void pickMethodGui();

};

#endif
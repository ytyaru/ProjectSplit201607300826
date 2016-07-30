#pragma once
#pragma comment(lib, "Rpcrt4.lib")
#include <windows.h>
#include <tchar.h>
#include <string>
#include <vector>
#include "IPartWndProc.h"

namespace ytyaru {
namespace Framework {
namespace MultiWindow {
namespace PartWndProc {
class Window
{
public:
	Window(void);
	~Window(void);
	void Create(HINSTANCE hInstance, std::basic_string<TCHAR> className);
	LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	std::vector<ytyaru::Framework::MultiWindow::PartWndProc::IPartWndProc*> partWndProcs;
protected:
private:
	LPWNDCLASSEX m_lpWndClassEx;
	HWND m_hWnd;
};
}
}
}
}

#pragma once
#include <windows.h>
#include <tchar.h>
#include <string>
#include <map>
#include "WndClassRegister.h"
#include "Window.h"

namespace ytyaru {
namespace Framework {
namespace MultiWindow {
class WndProcMapper
{
public:
	WndProcMapper(void);
	~WndProcMapper(void);
	static void RegistWndClass(HINSTANCE hInstance, ytyaru::Framework::MultiWindow::PartWndProc::Window* pWindow);
	static LRESULT CALLBACK BaseWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
private:
	static std::map<std::basic_string<TCHAR>, ytyaru::Framework::MultiWindow::PartWndProc::Window*> m_mapWindowByClassName;
};
}
}
}

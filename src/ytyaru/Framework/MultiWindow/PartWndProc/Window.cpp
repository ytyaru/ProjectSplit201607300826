#include "Window.h"

namespace ytyaru {
namespace Framework {
namespace MultiWindow {
namespace PartWndProc {

Window::Window(void) {}
Window::~Window(void) {}

void Window::Create(HINSTANCE hInstance, std::basic_string<TCHAR> className)
{
	GetClassInfoEx(hInstance, className.c_str(), this->m_lpWndClassEx);

	this->m_hWnd = CreateWindowEx(
		0,							// 拡張ウィンドウスタイル
		className.c_str(),			// class名
		_T("Window::Createで生成されたWindowです。"),		// タイトル
		WS_OVERLAPPEDWINDOW,		// Style
		CW_USEDEFAULT,				// X
		CW_USEDEFAULT,				// Y
		CW_USEDEFAULT,				// Width
		CW_USEDEFAULT,				// Height
		NULL,						// 親ウィンドウまたはオーナーウィンドウのハンドル
		NULL,						// メニューハンドルまたは子ウィンドウ ID
		hInstance,					// アプリケーションインスタンスのハンドル
		NULL						// ウィンドウ作成データ
	);
	if (NULL == this->m_hWnd) { throw "CreateWindow関数が失敗した。"; }

	ShowWindow(this->m_hWnd, SW_SHOWNORMAL);
	UpdateWindow(this->m_hWnd);
}

LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	BOOL isReturn = false;
	for (unsigned int i = 0; i < this->partWndProcs.size(); i++) {
		LRESULT res = this->partWndProcs[i]->PartWndProc(hWnd, uMsg, wParam, lParam, &isReturn);
		if (isReturn) { return res; }
	}
	if (uMsg == WM_NCDESTROY) { PostQuitMessage(0); }
	return (DefWindowProc(hWnd, uMsg, wParam, lParam));
}

}
}
}
}

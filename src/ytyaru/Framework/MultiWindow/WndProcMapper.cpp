#include "WndProcMapper.h"

namespace ytyaru {
namespace Framework {
namespace MultiWindow {

using std::map;
using std::basic_string;
using ytyaru::Framework::MultiWindow::PartWndProc::Window;

map<basic_string<TCHAR>, Window*> WndProcMapper::m_mapWindowByClassName;

WndProcMapper::WndProcMapper(void) {}
WndProcMapper::~WndProcMapper(void) {}

void WndProcMapper::RegistWndClass(HINSTANCE hInstance, Window* pWindow)
{
	WndClassRegister WndClsReg;
	basic_string<TCHAR> className = WndClsReg.Regist(hInstance);
	m_mapWindowByClassName.insert( map<basic_string<TCHAR>, Window*>::value_type( className, pWindow ) );
	pWindow->Create(hInstance, className);
}

LRESULT CALLBACK WndProcMapper::BaseWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	TCHAR className[1024];
	memset(className, '\0', 1024);
	GetClassName(hWnd, className, 1024);
	LRESULT res = m_mapWindowByClassName[className]->WndProc(hWnd, uMsg, wParam, lParam);
	
	// Windowの×ボタン押下 or Alt+F4
	// →WM_DESTROY
	// →WM_NCDESTROY(130, 0x0082)
	if (uMsg == WM_NCDESTROY) {
		m_mapWindowByClassName.erase(className);
	}

	// プロセス終了（全IWndProc継承クラスがなくなった）
	if(0 == m_mapWindowByClassName.size()) { PostQuitMessage(0); }

	return res;
}

}
}
}
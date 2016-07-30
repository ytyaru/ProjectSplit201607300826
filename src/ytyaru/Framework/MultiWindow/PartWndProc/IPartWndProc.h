#pragma once
#include <windows.h>
#include <tchar.h>
#include <string>

namespace ytyaru {
namespace Framework {
namespace MultiWindow {
namespace PartWndProc {
class IPartWndProc
{
public:
	virtual LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn) = 0;
};
}
}
}
}

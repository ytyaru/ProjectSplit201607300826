#pragma once
#pragma comment(lib, "Rpcrt4.lib")
#include <windows.h>
#include <tchar.h>
#include <string>
#include "WndProcMapper.h"

namespace ytyaru {
namespace Framework {
namespace MultiWindow {
class WndClassRegister
{
public:
	WndClassRegister(void);
	~WndClassRegister(void);
	std::basic_string<TCHAR> Regist(HINSTANCE hInstance);
};
}
}
}

#include "WndClassRegister.h"
#include "Uuid.h"

namespace ytyaru {
namespace Framework {
namespace MultiWindow {

using std::basic_string;

WndClassRegister::WndClassRegister(void) {}
WndClassRegister::~WndClassRegister(void) {}

basic_string<TCHAR> WndClassRegister::Regist(HINSTANCE hInstance)
{
	basic_string<TCHAR> className = ytyaru::Library::Uuid::Get();

	WNDCLASSEX wc;
	wc.cbSize			= sizeof(WNDCLASSEX); 
	wc.style			= CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc		= WndProcMapper::BaseWndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance		= hInstance;
	wc.hIcon			= NULL;
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= className.c_str();
	wc.hIconSm			= LoadIcon(NULL, IDI_APPLICATION);
	if (!RegisterClassEx(&wc)) { throw "RegisterClassExä÷êîÇ™é∏îsÇµÇΩÅB"; }

	return className;
}

}
}
}

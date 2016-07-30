#include "Window1.h"

Window1::Window1(void)
{
	{
	using namespace ytyaru::Framework::MultiWindow::PartWndProc;
	partWndProcs.push_back((IPartWndProc*)&m_InitializeWndProc);
	partWndProcs.push_back((IPartWndProc*)&m_KeyboardWndProc);
	}
}

Window1::~Window1(void)
{
}





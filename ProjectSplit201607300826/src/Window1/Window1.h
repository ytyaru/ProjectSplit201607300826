#pragma once
#include "Window.h"
#include "InitializeWndProc.h"
#include "KeyboardWndProc.h"

class Window1 : public ytyaru::Framework::MultiWindow::PartWndProc::Window
{
public:
	Window1(void);
	~Window1(void);
private:
	InitializeWndProc m_InitializeWndProc;
	KeyboardWndProc m_KeyboardWndProc;
};


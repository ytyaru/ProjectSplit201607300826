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
		0,							// �g���E�B���h�E�X�^�C��
		className.c_str(),			// class��
		_T("Window::Create�Ő������ꂽWindow�ł��B"),		// �^�C�g��
		WS_OVERLAPPEDWINDOW,		// Style
		CW_USEDEFAULT,				// X
		CW_USEDEFAULT,				// Y
		CW_USEDEFAULT,				// Width
		CW_USEDEFAULT,				// Height
		NULL,						// �e�E�B���h�E�܂��̓I�[�i�[�E�B���h�E�̃n���h��
		NULL,						// ���j���[�n���h���܂��͎q�E�B���h�E ID
		hInstance,					// �A�v���P�[�V�����C���X�^���X�̃n���h��
		NULL						// �E�B���h�E�쐬�f�[�^
	);
	if (NULL == this->m_hWnd) { throw "CreateWindow�֐������s�����B"; }

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

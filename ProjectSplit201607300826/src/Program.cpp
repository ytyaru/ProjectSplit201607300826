#include <locale.h>
#include <windows.h>
#include <tchar.h>
#include <string>
#include "WndProcMapper.h"
#include "Window1.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow)
{
	setlocale(LC_ALL, ".ACP");
	
	// using namespace �̖��O������h���ׂ��X�R�[�v�����߂��B
	// �������A�L�[�������Ă��������Ȃ��Ȃ����BWM_KEYDOWN�̏��������삵�Ă��Ȃ��B
	//
	// ������Window1�̃X�R�[�v���Ǝv���B
	// ���b�Z�[�W���[�v�̑O�ɃX�R�[�v���I�����ĉ������Ă��܂��̂��Ǝv���B
	//
	// ����Ȃ̂�WM_CREATE��E�C���h�E����������Ă���̂͂Ȃ����B
	// WM_CREATE�͂܂��X�R�[�v��������B
	// �E�C���h�E���\�����ꑱ����̂�CreateWindow����ē����n���h�����q�[�v�̈�ɂ��m�ۂ����炾�낤�B
	// �΂��Ă�����Window1�̓X�^�b�N�������B�X�R�[�v������o��Ɖ������Ă��܂��̂��낤�B
	// 
	//{
	//using namespace ytyaru::Framework::MultiWindow;
	//using namespace ytyaru::Framework::MultiWindow::PartWndProc;
	//Window1 window1;
	//WndProcMapper::RegistWndClass(hInstance, (Window*)&window1);
	//}

	// using�錾
	using ytyaru::Framework::MultiWindow::WndProcMapper;
	using ytyaru::Framework::MultiWindow::PartWndProc::Window;
	Window1 window1;
	WndProcMapper::RegistWndClass(hInstance, (Window*)&window1);

	// ���@
	// �Eusing A::SomeClass;		using�錾
	// �Eusing namespace A::B;	using�f�B���N�e�B�u
	// �Eusing A = ABC::DEF;		�G�C���A�X�i�ʖ���`�jtypedef

	// using�錾�̂ق������O�������ŏ����ɗ}������B
	
	// using�f�B���N�e�B�u
	//
	// �X�R�[�v�̊O��Window1 window1;��錾���A�X�R�[�v���ŗ��p����Ζ��Ȃ��͂��B
	// �ł��X�R�[�v�O���ƁA���O��Ԃ̉���������ł��Ȃ��B
	// �E���߂ĉ���������B
	// �E���O��Ԃ��܂߂��t���l�[���ŏ���
	// �E���r���[�ȑΉ��ɂȂ��ĉǐ������������̏�Ԃɂ���
	//

	//// ----------------------------
	//// �t���l�[���\�L
	//// ----------------------------
	//Window1 window1;
	//ytyaru::Framework::MultiWindow::WndProcMapper::RegistWndClass(hInstance, (ytyaru::Framework::MultiWindow::PartWndProc::Window*)&window1);
	//
	//// ----------------------------
	//// ���r���[�P
	//// ----------------------------
	//ytyaru::Framework::MultiWindow::PartWndProc::Window1 window1;
	//{	
	//using namespace ytyaru::Framework::MultiWindow::PartWndProc;
	//WndProcMapper::RegistWndClass(hInstance, (Window*)&window1);
	//}
	//
	//// ----------------------------
	//// ���r���[�Q
	//// ----------------------------
	//using namespace ytyaru::Framework::MultiWindow;
	//Window1 window1;
	//{	
	//using namespace ytyaru::Framework::MultiWindow::PartWndProc;
	//WndProcMapper::RegistWndClass(hInstance, (Window*)&window1);
	//}

	// �ʖ���`���ł���Ǝv������VC++2010Express�ł͂ł��Ȃ������B
	
	//// ----------------------------
	//// �ʖ���`�P
	//// ----------------------------
	//{
	//using Multi = ytyaru::Framework::MultiWindow;
	//Window1 window1;
	//Multi::WndProcMapper::RegistWndClass(hInstance, (Multi::PartWndProc::Window*)&window1);
	//}

	//// ----------------------------
	//// �ʖ���`�Q
	//// ----------------------------
	//{
	//using WndProcMapper = ytyaru::Framework::MultiWindow::WndProcMapper;
	//using Window = ytyaru::Framework::MultiWindow::PartWndProc::Window;
	//Window1 window1;
	//WndProcMapper::RegistWndClass(hInstance, (Window*)&window1);
	//}

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

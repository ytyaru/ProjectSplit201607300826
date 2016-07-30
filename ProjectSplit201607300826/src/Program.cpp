#include <locale.h>
#include <windows.h>
#include <tchar.h>
#include <string>
#include "WndProcMapper.h"
#include "Window1.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow)
{
	setlocale(LC_ALL, ".ACP");
	
	// using namespace の名前汚染を防ぐべくスコープを狭めた。
	// しかし、キーを押しても反応しなくなった。WM_KEYDOWNの処理が動作していない。
	//
	// 原因はWindow1のスコープだと思う。
	// メッセージループの前にスコープが終了して解放されてしまうのだと思う。
	//
	// それなのにWM_CREATEやウインドウが生成されているのはなぜか。
	// WM_CREATEはまだスコープ内だから。
	// ウインドウが表示され続けるのはCreateWindowされて得たハンドルがヒープ領域による確保だからだろう。
	// 対してここのWindow1はスタックメモリ。スコープ内から出ると解放されてしまうのだろう。
	// 
	//{
	//using namespace ytyaru::Framework::MultiWindow;
	//using namespace ytyaru::Framework::MultiWindow::PartWndProc;
	//Window1 window1;
	//WndProcMapper::RegistWndClass(hInstance, (Window*)&window1);
	//}

	// using宣言
	using ytyaru::Framework::MultiWindow::WndProcMapper;
	using ytyaru::Framework::MultiWindow::PartWndProc::Window;
	Window1 window1;
	WndProcMapper::RegistWndClass(hInstance, (Window*)&window1);

	// 方法
	// ・using A::SomeClass;		using宣言
	// ・using namespace A::B;	usingディレクティブ
	// ・using A = ABC::DEF;		エイリアス（別名定義）typedef

	// using宣言のほうが名前汚染を最小限に抑えられる。
	
	// usingディレクティブ
	//
	// スコープの外にWindow1 window1;を宣言し、スコープ内で利用すれば問題ないはず。
	// でもスコープ外だと、名前空間の汚染を限定できない。
	// ・諦めて汚染させる。
	// ・名前空間を含めたフルネームで書く
	// ・中途半端な対応になって可読性が悪いだけの状態にする
	//

	//// ----------------------------
	//// フルネーム表記
	//// ----------------------------
	//Window1 window1;
	//ytyaru::Framework::MultiWindow::WndProcMapper::RegistWndClass(hInstance, (ytyaru::Framework::MultiWindow::PartWndProc::Window*)&window1);
	//
	//// ----------------------------
	//// 中途半端１
	//// ----------------------------
	//ytyaru::Framework::MultiWindow::PartWndProc::Window1 window1;
	//{	
	//using namespace ytyaru::Framework::MultiWindow::PartWndProc;
	//WndProcMapper::RegistWndClass(hInstance, (Window*)&window1);
	//}
	//
	//// ----------------------------
	//// 中途半端２
	//// ----------------------------
	//using namespace ytyaru::Framework::MultiWindow;
	//Window1 window1;
	//{	
	//using namespace ytyaru::Framework::MultiWindow::PartWndProc;
	//WndProcMapper::RegistWndClass(hInstance, (Window*)&window1);
	//}

	// 別名定義もできると思ったがVC++2010Expressではできなかった。
	
	//// ----------------------------
	//// 別名定義１
	//// ----------------------------
	//{
	//using Multi = ytyaru::Framework::MultiWindow;
	//Window1 window1;
	//Multi::WndProcMapper::RegistWndClass(hInstance, (Multi::PartWndProc::Window*)&window1);
	//}

	//// ----------------------------
	//// 別名定義２
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

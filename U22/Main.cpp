#include "Main.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd) {


	ChangeWindowMode(TRUE);		//ウィンドウモード設定

	if (DxLib_Init() == -1)	return -1;	//DXライブラリ初期化処理

	Main main;
	//ゲームの環境設定
	if (main.init() == false) {
		return -1;
	}

	//裏画面を表画面に反映、メッセージ処理、画面クリア
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//画面の状態
		switch (main.status) {
		//メイン画面
		case Main::Status::main:
			
			break;
		}
	}

	DxLib_End();		//DXライブラリ使用の終了処理

	return 0;			//ソフトの終了
}

//初期化(DXライブラリと画面の基本設定)
bool Main::init()
{
	//タイトル
	SetMainWindowText("U22");
	status = Status::main;

	//Windowサイズの設定
	SetGraphMode(800, 600, 16);

	//Windowモード変更と初期化
	ChangeWindowMode(TRUE);
	if (DxLib_Init() != 0) {
		return false;
	}
	//裏画面設定
	SetDrawScreen(DX_SCREEN_BACK);

	//img読み込み

	return true;
}
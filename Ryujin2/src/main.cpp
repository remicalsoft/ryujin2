#include <DxLib.h>

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

    // while( 裏画面を表画面に反映, メッセージ処理, 画面クリア )
    while(!ScreenFlip()&&!ProcessMessage()&&!ClearDrawScreen()){

    }
        
    DxLib_End(); // DXライブラリ終了処理
    return 0;
}
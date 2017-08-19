#pragma once

class Define final {
public:
    const static int WIN_W;    //ウィンドウサイズ横
    const static int WIN_H;    //ウィンドウサイズ縦

    const static int OUT_W;//外枠幅
    const static int OUT_H;//外枠高さ
    const static int IN_W;//内枠幅
    const static int IN_H;//内枠高さ
    const static int CENTER_X;//動ける範囲の中央X
    const static int CENTER_Y;//動ける範囲の中央Y
    const static int IN_X;//内枠X
    const static int IN_Y;//内枠Y

    const static float PI;    //円周率

    enum eStage {
        Stage1,
        Stage2,
        Stage3,
        Stage4,
        Stage5,
        StageEX,
        StageNum,
    };

    enum eLevel {
        Easy,
        Normal,
        LevelNum
    };

};

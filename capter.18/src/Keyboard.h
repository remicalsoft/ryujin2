#pragma once

#include "Singleton.h"
#include <array>

class Keyboard final : public Singleton<Keyboard> {

	Keyboard() = default;
	friend Singleton< Keyboard >;

public:
	bool update();	//更新
	int getPressingCount(int keyCode);//keyCodeのキーが押されているフレーム数を取得
	int getReleasingCount(int keyCode);//keyCodeのキーが離されているフレーム数を取得

private:
	static const int KEY_NUM = 256;	//キー総数
    std::array<int, KEY_NUM> _pressingCount;//押されカウンタ
    std::array<int, KEY_NUM> _releasingCount;//離されカウンタ

	bool isAvailableCode(int keyCode);//keyCodeが有効なキー番号か問う
};

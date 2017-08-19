#include "Pad.h"
#include <DxLib.h>
#include "Keyboard.h"
#include "Define.h"
#include <string>
#include <algorithm>

using namespace std;

Pad::Pad() 
{
    _idArray[ePad::down]   = 0;  
    _idArray[ePad::left]   = 1;
    _idArray[ePad::right]  = 2;
    _idArray[ePad::up]     = 3;
    _idArray[ePad::bom]    = 4;
    _idArray[ePad::shot]   = 5;
    _idArray[ePad::slow]   = 11;
    _idArray[ePad::start]  = 12;
    _idArray[ePad::change] = 8;
}

void Pad::update() {
    int padInput;
	padInput = GetJoypadInputState(DX_INPUT_PAD1);//パッドの入力状態を取得
	for (int i = 0; i<16; i++) {
		if (padInput & (1<<i)) {
			_pad[i]++;
		}
		else {
			_pad[i] = 0;
		}
	}
    merge();
}

/*!
@brief パッドと、それに対応するキーボードの入力状態をマージする
*/
void Pad::merge() {
    _pad[_idArray[ePad::left]]   = max(_pad[_idArray[ePad::left]],   Keyboard::getIns()->getPressingCount(KEY_INPUT_LEFT));
    _pad[_idArray[ePad::up]]     = max(_pad[_idArray[ePad::up]],     Keyboard::getIns()->getPressingCount(KEY_INPUT_UP));
    _pad[_idArray[ePad::right]]  = max(_pad[_idArray[ePad::right]],  Keyboard::getIns()->getPressingCount(KEY_INPUT_RIGHT));
    _pad[_idArray[ePad::down]]   = max(_pad[_idArray[ePad::down]],   Keyboard::getIns()->getPressingCount(KEY_INPUT_DOWN));
    _pad[_idArray[ePad::shot]]   = max(_pad[_idArray[ePad::shot]],   Keyboard::getIns()->getPressingCount(KEY_INPUT_Z));
    _pad[_idArray[ePad::shot]]   = max(_pad[_idArray[ePad::shot]],   Keyboard::getIns()->getPressingCount(KEY_INPUT_RETURN));
    _pad[_idArray[ePad::bom]]    = max(_pad[_idArray[ePad::bom]],    Keyboard::getIns()->getPressingCount(KEY_INPUT_X));
    _pad[_idArray[ePad::slow]]   = max(_pad[_idArray[ePad::slow]],   Keyboard::getIns()->getPressingCount(KEY_INPUT_LSHIFT));
    _pad[_idArray[ePad::start]]  = max(_pad[_idArray[ePad::start]],  Keyboard::getIns()->getPressingCount(KEY_INPUT_ESCAPE));
    _pad[_idArray[ePad::change]] = max(_pad[_idArray[ePad::change]], Keyboard::getIns()->getPressingCount(KEY_INPUT_LCONTROL));
    _pad[_idArray[ePad::change]] = max(_pad[_idArray[ePad::change]], Keyboard::getIns()->getPressingCount(KEY_INPUT_C));
}

/*!
@brief 渡されたパッドキー番号の入力フレーム数を返す
*/
int Pad::get(ePad eID) const
{
	return _pad[_idArray[eID]];
}

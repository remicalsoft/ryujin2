#include "Keyboard.h"
#include <DxLib.h>

bool Keyboard::update() {
	char nowKeyStatus[KEY_NUM];
	GetHitKeyStateAll(nowKeyStatus);       //今のキーの入力状態を取得
	for (int i = 0; i<KEY_NUM; i++) {
		if (nowKeyStatus[i] != 0) {            //i番のキーが押されていたら
			if (_releasingCount[i] > 0) {//離されカウンタが0より大きければ
				_releasingCount[i] = 0;   //0に戻す
			}
			_pressingCount[i]++;          //押されカウンタを増やす
		}
		else {                             //i番のキーが離されていたら
			if (_pressingCount[i] > 0) { //押されカウンタが0より大きければ
				_pressingCount[i] = 0;    //0に戻す
			}
			_releasingCount[i]++;         //離されカウンタを増やす
		}
	}
	return true;
}

/*!
@brief keyCodeのキーが押されているフレーム数を返す
*/
int Keyboard::getPressingCount(int keyCode) {
	if (!isAvailableCode(keyCode)) {
		return -1;
	}
	return _pressingCount[keyCode];
}

/*!
@brief keyCodeのキーが離されているフレーム数を返す
*/
int Keyboard::getReleasingCount(int keyCode) {
	if (!isAvailableCode(keyCode)) {
		return -1;
	}
	return _releasingCount[keyCode];
}

/*!
@brief keyCodeが有効な値か否かを返す
*/
bool Keyboard::isAvailableCode(int keyCode) {
	if (!(0 <= keyCode && keyCode<KEY_NUM)) {
		return false;
	}
	return true;
}

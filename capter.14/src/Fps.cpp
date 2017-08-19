#include <DxLib.h>
#include "Fps.h"
#include "CalcUtils.h"

const static int LIST_LEN_MAX = 120;	//最大120フレームで待機処理を計算する(2以上にする)
const static int FPS = 60;			    //FPS
const static int UPINTVL = 60;		    //60フレームに一度更新する

Fps::Fps():_counter(0),_fps(0){}

void Fps::wait()
{
    _counter++;
    Sleep(getWaitTime());   //待つべき時間を取得して待つ
    regist();
    if (_counter == UPINTVL) {  //更新タイミングに1回平均値を更新する
        updateAverage();
        _counter = 0;
    }
}

void Fps::draw() const
{
    if (_fps == 0) {
        return;
    }
    DrawFormatString(0, 0, GetColor(255, 255, 255), "%04.1ffps", _fps);
}

void Fps::regist()
{
	_list.push_back( GetNowCount() );   //現在の時刻を記憶
	if( _list.size() > LIST_LEN_MAX ){  //器から漏れたらポップ
		_list.pop_front();
	}
}

unsigned Fps::getWaitTime() const
{
	int len = (int)_list.size();
	if( len == 0 ){
		return 0;
	}
	int shouldTookTime = (int)(1000/60.f*(len));            //計算上かかるべき時間
	int actuallyTookTime = GetNowCount() - _list.front();   //実際にかかった時間
	int waitTime = shouldTookTime - actuallyTookTime;       //計算上かかるべき時間 - 実際にかかった時間　はすなわち待つべき時間
	waitTime = waitTime > 0 ? waitTime : 0;
	return (unsigned)(waitTime);
}

void Fps::updateAverage() {
    int len = (int)_list.size();
    if (len < LIST_LEN_MAX) {   //まだ平均を計算するレベルにまでたまっていなければ計算しない
        return;
    }
    int tookTime = _list.back() - _list.front();//LIST_LEN_MAXフレームにかかった時間
    float average = (float)tookTime / (len - 1);//平均を取る
    if (average == 0) {//0割り防止
        return;
    }
    _fps = CalcUtils::roundPoint(1000 / average, 2);//小数点第2位で四捨五入する
}

#include "Looper.h"
#include "TitleScene.h"
#include "Error.h"

using namespace std;

Looper::Looper()
{
    Parameter parameter;
    _sceneStack.push(make_shared<TitleScene>(this, parameter)); //タイトル画面シーンを作ってpush
}
/*!
@brief スタックのトップのシーンの処理をする
*/
bool Looper::loop() const
{
    _sceneStack.top()->update();    //スタックのトップのシーンを更新
    _sceneStack.top()->draw();      //スタックのトップのシーンを描画
    return true;
}

/*!
@brief シーン変更(各シーンからコールバックされる)
@param scene 変更するシーンのenum
@param parameter 前のシーンから引き継ぐパラメータ
@param stackClear 現在のシーンのスタックをクリアするか
*/
void Looper::onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear)
{
}

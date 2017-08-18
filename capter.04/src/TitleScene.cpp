#include "TitleScene.h"
#include <DxLib.h>

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
}

void TitleScene::update()
{
}

void TitleScene::draw()
{
    DrawString(100, 100, "タイトル画面", GetColor(255,255,255));
}

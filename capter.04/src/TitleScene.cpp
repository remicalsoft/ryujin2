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
    DrawString(100, 100, "ƒ^ƒCƒgƒ‹‰æ–Ê", GetColor(255,255,255));
}

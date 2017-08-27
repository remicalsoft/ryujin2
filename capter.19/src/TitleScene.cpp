#include "TitleScene.h"
#include <DxLib.h>
#include "GameScene.h"
#include "Define.h"
#include "Keyboard.h"
#include "Pad.h"

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
}

void TitleScene::update()
{
    if (Pad::getIns()->get(ePad::shot) == 1) {
        Parameter parameter;
        parameter.set(GameScene::ParameterTagLevel, Define::eLevel::Easy);
        const bool stackClear = false;
        _implSceneChanged->onSceneChanged(eScene::Game, parameter, stackClear);
        return;
    }
    if (Keyboard::getIns()->getPressingCount(KEY_INPUT_N) == 1) {
        Parameter parameter;
        parameter.set(GameScene::ParameterTagLevel, Define::eLevel::Normal);
        const bool stackClear = false;
        _implSceneChanged->onSceneChanged(eScene::Game, parameter, stackClear);
        return;
    }
}

void TitleScene::draw() const
{
    DrawString(100, 100, "ƒ^ƒCƒgƒ‹‰æ–Ê", GetColor(255,255,255));
}

#include "GameScene.h"
#include <DxLib.h>

const char* GameScene::ParameterTagStage = "ParameterTagStage";//パラメータのタグ「ステージ」
const char* GameScene::ParameterTagLevel = "ParameterTagLevel";//パラメータのタグ「レベル」

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
    _level = parameter.get(ParameterTagLevel);
}

void GameScene::update()
{
}

void GameScene::draw() const
{
    DrawFormatString(100, 100, GetColor(255, 255, 255), "ゲームレベルは %d です", _level);
}

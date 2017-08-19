#include "GameScene.h"
#include <DxLib.h>
#include "Macro.h"
#include "Background01spell.h"

using namespace std;

const char* GameScene::ParameterTagStage = "ParameterTagStage";//パラメータのタグ「ステージ」
const char* GameScene::ParameterTagLevel = "ParameterTagLevel";//パラメータのタグ「レベル」

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
    _backgroundSpell = make_shared<Background01spell>();
    _player = make_shared<Player>();
    _board = make_shared<Board>();
}

void GameScene::update()
{
    _backgroundSpell->update();
    _player->update();
    _board->update();
}

void GameScene::draw() const
{
    _backgroundSpell->draw();
    _player->draw();
    _board->draw();
}

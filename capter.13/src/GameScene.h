#pragma once

#include "AbstractScene.h"
#include "Player.h"
#include <memory>
#include "Board.h"
#include "AbstractBackground.h"

class GameScene : public AbstractScene
{
public:
    const static char* ParameterTagStage;//パラメータのタグ「ステージ」
    const static char* ParameterTagLevel;//パラメータのタグ「レベル」

    GameScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~GameScene() = default;

    void update() override;
    void draw() const override;

private:
    std::shared_ptr<Player> _player;
    std::shared_ptr<Board>  _board;
    std::shared_ptr<AbstractBackground> _backgroundSpell;
};


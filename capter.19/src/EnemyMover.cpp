#include "EnemyMover.h"
#include "Macro.h"
#include "Define.h"
#include "AbstractEnemy.h"

using namespace std;

EnemyMover::EnemyMover()
{
    setFunction();
}

void EnemyMover::move(AbstractEnemy* enemy)
{
    const unsigned int id = enemy->getMovePatternID();
    if (_movePattern.size() <= id) {
        ERR("moveIDが不正です");
    }
    (this->*_movePattern[id])(enemy);  //idに応じた移動処理を行う
    enemy->setX(enemy->getX() + cos(enemy->getAngle()) * enemy->getSpeed());//x移動
    enemy->setY(enemy->getY() + sin(enemy->getAngle()) * enemy->getSpeed());//y移動
}

/*
@brief 下に下がって止まり、また下がる
*/
void EnemyMover::movePattern00(AbstractEnemy* enemy)
{
    const int cnt  = enemy->getCounter();
    const int wait = 180;
    if (0 == cnt) {
        enemy->setAngle(Define::PI / 2);
        enemy->setSpeed(3);
    }
    if (60 < cnt && cnt <= 90) {
        enemy->setSpeed(enemy->getSpeed() - 0.1f);
    }
    if (90 + wait < cnt && cnt <= 90 + wait + 30) {
        enemy->setSpeed(enemy->getSpeed() + 0.1f);
    }
}

/*!
@brief 左下へ移動する
*/
void EnemyMover::movePattern01(AbstractEnemy* enemy)
{
    int cnt = enemy->getCounter();
    if (0 == cnt) {
        enemy->setAngle(Define::PI * 3 / 4);
        enemy->setSpeed(4);
    }
}

/*!
@brief 右下へ移動する
*/
void EnemyMover::movePattern02(AbstractEnemy* enemy)
{
    int cnt = enemy->getCounter();
    if (0 == cnt) {
        enemy->setAngle(Define::PI * 1 / 4);
        enemy->setSpeed(4);
    }
}

void EnemyMover::movePattern03(AbstractEnemy* enemy)
{
}

void EnemyMover::movePattern04(AbstractEnemy* enemy)
{
}

/*!
@brief 関数ポインタをリストにセット
*/
void EnemyMover::setFunction()
{
    _movePattern.push_back(&EnemyMover::movePattern00);
    _movePattern.push_back(&EnemyMover::movePattern01);
    _movePattern.push_back(&EnemyMover::movePattern02);
    _movePattern.push_back(&EnemyMover::movePattern03);
    _movePattern.push_back(&EnemyMover::movePattern04);
}

#include "Enemy.h"
#include <DxLib.h>
#include "Image.h"
#include "Define.h"

Enemy::Enemy(float x, float y) : _x(x), _y(y), _speed(2.f), _angle(Define::PI/2)
{
}

bool Enemy::update()
{
    _x += cos(_angle)*_speed;
    _y += sin(_angle)*_speed;
    return true;
}

void Enemy::draw() const
{
    DrawRotaGraphF(_x, _y, 1.0, 0.0, Image::getIns()->getEnemyNormal()[4], TRUE);
}

#include "AbstractEnemy.h"
#include <DxLib.h>
#include "Image.h"
#include "Define.h"

AbstractEnemy::AbstractEnemy(float x, float y) : 
    _x(x), 
    _y(y), 
    _speed(0), 
    _angle(0), 
    _counter(0),
    _width(0),
    _height(0)
{
}

void AbstractEnemy::initialize()
{
    setSize();
}

bool AbstractEnemy::update()
{
    _counter++;
    _x += cos(_angle)*_speed;
    _y += sin(_angle)*_speed;
    return true;
}

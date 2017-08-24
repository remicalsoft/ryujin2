#pragma once

#include "Task.h"
#include "EnemyMover.h"

class EnemyMover;

class AbstractEnemy : public Task
{
public:
    AbstractEnemy(float x, float y);
    virtual ~AbstractEnemy() = default;
    void initialize();
    bool update() override;

    float getX() { return _x; }
    void  setX(float x) { _x = x; }
    float getY() { return _y; }
    void  setY(float y) { _y = y; }
    int   getCounter() { return _counter; }
    void  setSpeed(float speed) { _speed = speed; }
    float getSpeed() { return _speed; }
    void  setAngle(float angle) { _angle = angle; }
    float getAngle() { return _angle; }
    int   getMovePatternID() { return _movePatternID;  }

protected:
    virtual void setSize() = 0;
    bool isInside() const;

    EnemyMover _mover;

    float _x, _y;//座標
    float _speed;//速さ
    float _angle;//角度

    int _counter;//カウンタ
    int _width; //幅
    int _height;//高さ

    int _movePatternID;//移動パターン
};


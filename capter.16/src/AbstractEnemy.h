#pragma once

#include "Task.h"

class AbstractEnemy : public Task
{
public:
    AbstractEnemy(float x, float y);
    virtual ~AbstractEnemy() = default;
    void initialize();
    bool update() override;

protected:
    virtual void setSize() = 0;

    float _x, _y;//座標
    float _speed;//速さ
    float _angle;//角度

    int _counter;//カウンタ
    int _width; //幅
    int _height;//高さ
};


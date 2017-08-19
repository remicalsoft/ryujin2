#pragma once

#include "Task.h"

class Enemy : public Task
{
public:
    Enemy(float x, float y);
    virtual ~Enemy() = default;
    bool update() override;
    void draw() const override;

protected:
    float _x, _y;//À•W
    float _speed;//‘¬‚³
    float _angle;//Šp“x
};


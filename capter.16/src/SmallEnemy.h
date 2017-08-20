#pragma once

#include "AbstractEnemy.h"

class SmallEnemy final : public AbstractEnemy
{
public:
    SmallEnemy(float x, float y);
    ~SmallEnemy() = default;
    void draw() const override;

protected:
    void setSize() override;
};


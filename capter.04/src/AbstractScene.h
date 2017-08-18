#pragma once

#include "IOnSceneChangedListener.h"
#include "Parameter.h"

class IOnSceneChangedListener;

class AbstractScene
{
protected:
    IOnSceneChangedListener* _implSceneChanged;
public:
    AbstractScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~AbstractScene() = default;
    virtual void update() = 0;
    virtual void draw()   = 0;
};

#pragma once

#include "AbstractScene.h"

class TitleScene : public AbstractScene
{
public:
    TitleScene(IOnSceneChangedListener *impl, const Parameter& parameter);
    virtual ~TitleScene() = default;
    void update() override;
    void draw() const override;
};

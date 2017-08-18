#pragma once

#include <stack>
#include <memory>
#include "AbstractScene.h"
#include "IOnSceneChangedListener.h"

class Looper final : public IOnSceneChangedListener
{
public:
    Looper();
    ~Looper() = default;
    bool loop() const;
    void onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear) override;

private:
    std::stack<std::shared_ptr<AbstractScene>> _sceneStack; //シーンのスタック
};


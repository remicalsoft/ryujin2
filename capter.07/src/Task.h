#pragma once

class Task {
public:
    Task() = default;
    virtual ~Task() = default;
    virtual bool update() = 0;
    virtual void draw()   = 0;
};

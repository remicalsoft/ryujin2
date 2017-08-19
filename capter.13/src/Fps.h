#pragma once

#include <list>

class Fps {

public:
    Fps();
    void wait();
    void draw() const;

private:
    std::list<int> _list;
    float    _fps;
    unsigned _counter;

    void        updateAverage();
    void        regist();
    unsigned    getWaitTime() const;

};


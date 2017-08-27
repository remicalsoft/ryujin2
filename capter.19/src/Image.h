#pragma once

#include "Singleton.h"
#include <vector>
#include <array>

class Image final : public Singleton<Image> {

public:
    Image();
    ~Image() = default;
    void load() {}
    void release();

    int getPlayer() const { return _player; }
    int getBoard() const { return _board; }
    int getFusuma() const { return _fusuma; }
    int getFloor() const { return _floor; }
    int getBackSpell00() const { return _backSpell00; }
    int getBackSpell01() const { return _backSpell01; }
    const int* getEnemySmall () const { return _enemySmall; }
    const int* getEnemyNormal() const { return _enemyNormal; }
    const int* getEnemyBig   () const { return _enemyBig; }

private:
    int myLoadGraph(char*);
    int myLoadDivGraph(char *fileName, int n, int xn, int yn, int w, int h, int* buf);

    std::vector<int> _images;
    int _player;
    int _board;
    int _fusuma, _floor;
    int _backSpell00, _backSpell01;
    int _enemySmall[2];
    int _enemyNormal[9];
    int _enemyBig[9];

};


#pragma once

#include "Singleton.h"
#include <vector>

class Image final : public Singleton<Image> {

public:
    Image();
    ~Image() = default;
    void load() {}
    void release();

    int getPlayer() const;

private:
    int myLoadGraph(char*);
    int myLoadDivGraph(char *fileName, int n, int xn, int yn, int w, int h, int* buf);

    std::vector<int> _images;
    int _player;

};


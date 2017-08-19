#include "Image.h"
#include <DxLib.h>

Image::Image()
{
    _player       = myLoadGraph("../dat/image/player/body/seishi0.png");
    _board        = myLoadGraph("../dat/image/board/board.png");
    _fusuma       = myLoadGraph("../dat/image/background/01/fusuma.png");
    _floor        = myLoadGraph("../dat/image/background/01/floor.png");
    _backSpell00  = myLoadGraph("../dat/image/background/01spell/00.png");
    _backSpell01  = myLoadGraph("../dat/image/background/01spell/01.png");
    myLoadDivGraph("../dat/image/enemy/normal.png", 9, 3, 3, 54, 54, _enemyNormal);
    myLoadDivGraph("../dat/image/enemy/bit.png", 9, 3, 3, 160, 120, _enemyBig);
    myLoadDivGraph("../dat/image/enemy/small.png", 2, 2, 1, 32, 32, _enemySmall);
}

/*!
@brief 今までロードした画像を解放する
*/
void Image::release() 
{
    const int size = _images.size();
    for (int i = 0; i < size; i++) {
        DeleteGraph(_images[i]);
    }
    _images.clear();
}

/*!
@brief LoadGraphをして、かつそのハンドルをメンバ変数に追加する
*/
int Image::myLoadGraph(char *fileName)
{
    int ret = LoadGraph(fileName);
    _images.push_back(ret);
    return ret;
}

/*!
@brief LoadDivGraphをして、かつそのハンドルをメンバ変数に追加する
*/
int Image::myLoadDivGraph(char *fileName, int n, int xn, int yn, int w, int h, int* buf)
{
    int ret = LoadDivGraph(fileName, n, xn, yn, w, h, buf);
    for (int i = 0; i < n; i++) {
        _images.push_back(buf[i]);
    }
    return ret;
}
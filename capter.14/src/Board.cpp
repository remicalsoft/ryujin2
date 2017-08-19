#include "Board.h"
#include "Define.h"
#include <DxLib.h>
#include "Image.h"

bool Board::update()
{
    return true;
}

void Board::draw() const
{
    DrawGraph(Define::OUT_W, 0, Image::getIns()->getBoard(), TRUE);
    drawFrame();
}

void Board::drawFrame() const
{
    int color = GetColor(0, 64, 128);
    const int x = Define::IN_X;
    const int y = Define::IN_Y;
    const int w = Define::IN_W;
    const int h = Define::IN_H;
    DrawLine(x,     y,     x + w, y,     color);
    DrawLine(x,     y,     x,     y + h, color);
    DrawLine(x + w, y,     x + w, y + h, color);
    DrawLine(x,     y + h, x + w, y + h, color);
}

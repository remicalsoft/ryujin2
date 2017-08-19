#include "Player.h"
#include "Pad.h"
#include <DxLib.h>
#include "Image.h"

const static float SPEED = 9;

Player::Player() : _x(100), _y(100)
{
    _image = LoadGraph("../dat/image/player/body/seishi0.png");
}

bool Player::update()
{
    move();
    return true;
}

void Player::draw() const
{
    DrawRotaGraphF(_x, _y, 1.0, 0.0, _image, TRUE);
}

/*!
@brief ƒvƒŒƒCƒ„[‚ð“®‚©‚·
*/
void Player::move()
{
    float moveX = 0, moveY = 0;
    if (Pad::getIns()->get(ePad::left) > 0) {
        moveX -= SPEED;
    }
    if (Pad::getIns()->get(ePad::right) > 0) {
        moveX += SPEED;
    }
    if (Pad::getIns()->get(ePad::down) > 0) {
        moveY += SPEED;
    }
    if (Pad::getIns()->get(ePad::up) > 0) {
        moveY -= SPEED;
    }
    if (moveX && moveY) { //ŽÎ‚ßˆÚ“®
        moveX /= (float)sqrt(2.0);
        moveY /= (float)sqrt(2.0);
    }
    if (Pad::getIns()->get(ePad::slow) > 0) {//’á‘¬ˆÚ“®
        moveX /= 3;
        moveY /= 3;
    }
    _x += moveX;
    _y += moveY;
}
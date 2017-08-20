#include "Player.h"
#include "Pad.h"
#include <DxLib.h>
#include "Image.h"
#include "Define.h"

const static float SPEED = 9;

Player::Player() : 
    _x((float)Define::CENTER_X),
    _y((float)Define::OUT_H*0.8f)
{
}

bool Player::update()
{
    move();
    return true;
}

void Player::draw() const
{
    DrawRotaGraphF(_x, _y, 1.0, 0.0, Image::getIns()->getPlayer(), TRUE);
}

/*!
@brief ƒvƒŒƒCƒ„[‚ğ“®‚©‚·
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
    if (moveX && moveY) { //Î‚ßˆÚ“®
        moveX /= (float)sqrt(2.0);
        moveY /= (float)sqrt(2.0);
    }
    if (Pad::getIns()->get(ePad::slow) > 0) {//’á‘¬ˆÚ“®
        moveX /= 3;
        moveY /= 3;
    }
    if (moveX + _x < Define::IN_X) {//¶˜g‚æ‚è¶‚È‚ç
        _x = (float)Define::IN_X;   //¶˜g‚Å~‚ß‚é
    }
    else if (moveX + _x > Define::IN_X + Define::IN_W) {//‰E˜g‚æ‚è‰E‚È‚ç
        _x = (float)(Define::IN_X + Define::IN_W);      //‰E˜g‚Å~‚ß‚é
    }
    else {//˜g“à‚È‚ç
        _x += moveX;//•’Ê‚ÉˆÚ“®
    }
    if (moveY + _y < Define::IN_Y) {   //ã˜g‚æ‚èã‚È‚ç
        _y = (float)Define::IN_Y;      //ã˜g‚Å~‚ß‚é
    }
    else if (moveY + _y > Define::IN_Y + Define::IN_H) {    //‰º˜g‚æ‚è‰º‚È‚ç
        _y = (float)(Define::IN_Y + Define::IN_H);          //‰º˜g‚Å~‚ß‚é
    }
    else {//˜g“à‚È‚ç
        _y += moveY;//•’Ê‚ÉˆÚ“®
    }
}
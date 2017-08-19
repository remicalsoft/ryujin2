#include "CalcUtils.h"
#include <cmath>
#include <DxLib.h>

/*
*@brief val‚Ì¬”“_‘æpointˆÊ‚ğlÌŒÜ“ü‚µ‚ÄŠÛ‚ß‚é
*/
float CalcUtils::roundPoint(float val, int point) {
    float ret;
    ret = val * pow(10.f, + point - 1);
    ret = (float)(int)(ret + 0.5f);
    return ret * pow(10.f, - point + 1);
}

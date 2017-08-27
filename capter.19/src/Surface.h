#pragma once

#include <DxLib.h>

class Surface {

public:
    enum eSurface {
        WIND,
        FLOR,
        DOOR,
        LOOF,
        DATANUM,
    };

    Surface( int z, int sHdl, unsigned uType );
    bool update();
    void draw(VECTOR offset);

    float getZ();
    float getZWid();
    void addZ( float fZ );
   
private:
    VERTEX3D    _vertex[4];
    WORD        _index[6];
    int         _handle;
    VECTOR      _angle;

};

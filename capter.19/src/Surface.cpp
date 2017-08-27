#include "Surface.h"
#include "Define.h"

const static float  WIDX = 40.0f;
const static float  WIDY = 40.0f;
const static float  WIDZ = 40.0f;
const static float  SCRSPD = 0.1f;
const static float  SPACE = 5;
const static float  SPD = 0.01f;
const static float csDefRotaX = (-Define::PI/5.f);
const static VECTOR vMOVE={0,5,-50};
const static VECTOR gvPos[Surface::DATANUM][4] = {
	{{0,WIDY,0},{0,WIDY,WIDZ},{0,0,WIDZ},{0,0,0}},
	{{0,0,0},{0,0,WIDZ},{WIDX,0,WIDZ},{WIDX,0,0}},
	{{WIDX,WIDY,0},{WIDX,WIDY,WIDZ},{WIDX,0,WIDZ},{WIDX,0,0}},
	{{0,WIDY,0},{0,WIDY,WIDZ},{WIDX,WIDY,WIDZ},{WIDX,WIDY,0}},
};

Surface::Surface( int z, int sHdl, unsigned uType )
{
	VECTOR vPos[DATANUM][4]={};
	for( int i=0; i<DATANUM; i++ ){
		for( int j=0; j<4; j++ ){
			vPos[i][j].x = gvPos[i][j].x - WIDX/2;
			vPos[i][j].y = gvPos[i][j].y - WIDY/2;
		}
	}
	unsigned Tp = uType;
	_handle = sHdl;
	_angle = VGet( -SPD, 0.0f, -SPD );
	_vertex[ 0 ].pos  = VGet( vPos[Tp][0].x, vPos[Tp][0].y, vPos[Tp][0].z+WIDZ*z ) ;	//左上
	_vertex[ 0 ].norm = VGet( 1.0f, 0.0f, 0.0f ) ;
	_vertex[ 0 ].dif  = GetColorU8(255,255,255,255);
	_vertex[ 0 ].spc  = GetColorU8(  0,  0,  0,  0);
	_vertex[ 0 ].u    = 0.0f ;
	_vertex[ 0 ].v    = 0.0f ;
	_vertex[ 0 ].su   = 0.0f ;
	_vertex[ 0 ].sv   = 0.0f ;

	_vertex[ 1 ].pos  = VGet( vPos[Tp][1].x, vPos[Tp][1].y, vPos[Tp][1].z+WIDZ*(z+1) );	//右上
	_vertex[ 1 ].norm = VGet( 0.0f, 1.0f, 0.0f ) ;
	_vertex[ 1 ].dif  = GetColorU8(255,255,255,255) ;
	_vertex[ 1 ].spc  = GetColorU8(  0,  0,  0,  0) ;
	_vertex[ 1 ].u    = 1.0f ;
	_vertex[ 1 ].v    = 0.0f ;
	_vertex[ 1 ].su   = 0.0f ;
	_vertex[ 1 ].sv   = 0.0f ;

	_vertex[ 2 ].pos  = VGet( vPos[Tp][2].x, vPos[Tp][2].y, vPos[Tp][2].z+WIDZ*(z+1) );	//右下
	_vertex[ 2 ].norm = VGet( -1.0f, 0.0f, 0.0f ) ;
	_vertex[ 2 ].dif  = GetColorU8(255,255,255,255) ;
	_vertex[ 2 ].spc  = GetColorU8(  0,  0,  0,  0) ;
	_vertex[ 2 ].u    = 1.0f ;
	_vertex[ 2 ].v    = 1.0f ;
	_vertex[ 2 ].su   = 0.0f ;
	_vertex[ 2 ].sv   = 0.0f ;

	_vertex[ 3 ].pos  = VGet( vPos[Tp][3].x, vPos[Tp][3].y, vPos[Tp][3].z+WIDZ*z );	//左下
	_vertex[ 3 ].norm = VGet( 0.0f, -1.0f, 0.0f ) ;
	_vertex[ 3 ].dif  = GetColorU8(255,255,255,255) ;
	_vertex[ 3 ].spc  = GetColorU8(  0,  0,  0,  0) ;
	_vertex[ 3 ].u    = 0.0f ;
	_vertex[ 3 ].v    = 1.0f ;
	_vertex[ 3 ].su   = 0.0f ;
	_vertex[ 3 ].sv   = 0.0f ;

	// ２ポリゴン分のインデックスデータをセット
	_index[ 0 ] = 0 ;
	_index[ 1 ] = 1 ;
	_index[ 2 ] = 2 ;
	_index[ 3 ] = 2 ;
	_index[ 4 ] = 3 ;
	_index[ 5 ] = 0 ;
}

bool Surface::update()
{
	for(int i=0; i<4; i++){
		_vertex[i].pos.z -= SCRSPD;
	}
	return true;
}

void Surface::draw(VECTOR offset)
{
	MATRIX Matrix = MGetRotX( csDefRotaX ) ;
	VERTEX3D	tmpVertex[ 4 ];
	memcpy( tmpVertex, _vertex, sizeof( _vertex ) );
	for( int i=0; i<4; i++ ){
		tmpVertex[i].pos = VTransform( tmpVertex[i].pos, Matrix ) ;
		tmpVertex[i].pos = VAdd(tmpVertex[i].pos, vMOVE);
		tmpVertex[i].pos = VAdd(tmpVertex[i].pos, offset);
	}
	DrawPolygonIndexed3D( tmpVertex, 4, _index, 2, _handle, TRUE ) ;
}

float Surface::getZ()
{
	return _vertex[0].pos.z;
}

float Surface::getZWid()
{
	return WIDZ;
}

void Surface::addZ( float fZ )
{
	for(int i=0; i<4; i++){
		_vertex[i].pos.z += fZ;
	}
}

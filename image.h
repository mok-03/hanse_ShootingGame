#pragma once
#include "LPspriteBase.h"
#include <d3d9.h>
#include <d3dx9.h>
#include <string>
struct IMAGE {
	LPDIRECT3DTEXTURE9 texture;
	D3DXIMAGE_INFO info;
	RECT rect;
	D3DXVECTOR3 center;
	D3DXVECTOR3 position;


	bool rotation;
	D3DXCOLOR color;
};

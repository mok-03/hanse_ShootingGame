#include "DXUT.h"
#include "spriteActor.h"

void spriteActor::SetImage(std::wstring _filename)
{
	IMAGE  tempImage;
	ZeroMemory(&tempImage, sizeof(tempImage));

	D3DXCreateTextureFromFileEx(DXUTGetD3D9Device(), _filename.c_str(), -2, -2, 1, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
		D3DX_FILTER_NONE, 0, 0, 0, 0, &tempImage.texture);

	D3DXGetImageInfoFromFile(_filename.c_str(), &tempImage.info);

	tempImage.rect = { 0,0,(LONG)tempImage.info.Width, (LONG)tempImage.info.Height };
	//센터도 해줘야하나?
	image = tempImage;
}

void spriteActor::Draw()
{
	LPsprite->Begin(D3DXSPRITE_ALPHABLEND);
	LPsprite->Draw(image.texture, &image.rect, &image.center, &image.position, 0xffffffff);
	LPsprite->End();
}

void spriteActor::Init(D3DXVECTOR3 Pos)
{

	image.position = Pos;
	//추가할거 생기면 추가하셈 
}



void spriteActor::Release()
{
	image.texture->Release();
}

void spriteActor::SetPos(D3DXVECTOR3 Pos)
{

	image.position = Pos;
}

D3DXVECTOR3 spriteActor::GetPos()
{
	return image.position;
}

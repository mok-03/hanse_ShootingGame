#pragma once

#include "image.h"
#include <vector>

class spriteActor :
	public LPspriteBase
{
protected:
	//IMAGE image;

public:
	IMAGE image;
	
	void SetImage(std::wstring _filename);
	void Draw();
	void Init(D3DXVECTOR3 Pos);
	void Release();
	void SetPos(D3DXVECTOR3 Pos);
	D3DXVECTOR3 GetPos();
};

// 충돌처리 (OBB 구현할것임) 회전 할것아니면 필요없을까?
// 빠르게 제작해야하니 회전을 뺄것이다.


// 충돌처리 메니저를 만들어서 내부에서 Rect 값을 받아서 구현할것이다. 

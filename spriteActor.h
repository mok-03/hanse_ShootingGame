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

// �浹ó�� (OBB �����Ұ���) ȸ�� �Ұ;ƴϸ� �ʿ������?
// ������ �����ؾ��ϴ� ȸ���� �����̴�.


// �浹ó�� �޴����� ���� ���ο��� Rect ���� �޾Ƽ� �����Ұ��̴�. 

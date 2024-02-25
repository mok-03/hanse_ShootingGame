#pragma once
#define MAXBULLET 20

#include "Ani_spriteActor.h"
class Player
{
private:


	INT Speed =4;
	INT BulletNum = 19;
	DWORD BulletTime; //�Ѿ� �ð�
	DWORD HiTTime;
public:	
	spriteActor HPspritePlayer[10];
	INT HP =10;
	BOOL HitBullet = false;
	Ani_spriteActor PlayerAni;
	D3DXVECTOR3 PlayerPos;
	D3DXVECTOR3 BulletPos[MAXBULLET];
	bool BulletH[MAXBULLET];//�Ѿ��� �����ִ���
		Ani_spriteActor Bullet[MAXBULLET]; //�Ѿ� ���߿� �ٲ������

	void InitPlayer();
	void UpdatePlayer();
	void RealsePlayer();
	void DrawPlayer();
	void KeySet();//Ű���� �Է�
	void MoveLeft();
	void MoveRight();
	void MoveDown();
	void MoveUP();

	void HitDamge();


	void Shootting();
	void BulletDiE(Ani_spriteActor(*));

};


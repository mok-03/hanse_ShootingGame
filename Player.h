#pragma once
#define MAXBULLET 20

#include "Ani_spriteActor.h"
class Player
{
private:


	INT Speed =4;
	INT BulletNum = 19;
	DWORD BulletTime; //총알 시간
	DWORD HiTTime;
public:	
	spriteActor HPspritePlayer[10];
	INT HP =10;
	BOOL HitBullet = false;
	Ani_spriteActor PlayerAni;
	D3DXVECTOR3 PlayerPos;
	D3DXVECTOR3 BulletPos[MAXBULLET];
	bool BulletH[MAXBULLET];//총알이 켜져있는지
		Ani_spriteActor Bullet[MAXBULLET]; //총알 나중에 바꿔줘야함

	void InitPlayer();
	void UpdatePlayer();
	void RealsePlayer();
	void DrawPlayer();
	void KeySet();//키보드 입력
	void MoveLeft();
	void MoveRight();
	void MoveDown();
	void MoveUP();

	void HitDamge();


	void Shootting();
	void BulletDiE(Ani_spriteActor(*));

};


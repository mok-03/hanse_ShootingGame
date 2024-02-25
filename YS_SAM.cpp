#include "DXUT.h"
#include "YS_SAM.h"

void YS_SAM::Update_YS()
{
	DWORD curTime = GetTickCount64();
	//�Ѿ��̶� ���� �ִϸ��̼� ����
	//YS_SAM::MonsterUpdate();

	for (int i = 0; i < YS_BULLETMAXNUM; i++) {
		//YS_BULLET[i].UpdateBullet();
			//�Ѿ� ������
		if (BulletH[i] == true) {

			YS_BULLET[i].Bullet.SetPos(YS_BULLET[i].BulletPos);
			YS_BULLET[i].BulletPos = (YS_BULLET[i].Shootting(YS_BULLET[i].Bullet, YS_BULLET[i].BulletPos, speed));
		}
		else {
			YS_BULLET[i].Bullet.SetPos({ -1000,1000,0 });

		}

		//�Ѿ� �ʱ�ȭ
		if (YS_BULLET[i].BulletPos.y > 1200 ||
			YS_BULLET[i].BulletPos.y < -1200 ||
			YS_BULLET[i].BulletPos.x > 1000 ||
			YS_BULLET[i].BulletPos.x < -1000
			) {
			BulletH[i] = false;
		}
	}
	//YS_BULLET[5].BulletPos.y +=  0.5f;
	//�Ѿ˹߻�
	if (nowBulletNum >= 0 && nowBulletNum < YS_BULLETMAXNUM && curTime - Bullettime > 800 && SpoonAni == true) {
		if (BulletH[nowBulletNum] == false) {


			for (int i = 0; i < 8; i++) {
				if (YS_BULLETMAXNUM <= nowBulletNum) {
				nowBulletNum = 0;
				}
	
				BulletH[nowBulletNum] = true;
				YS_BULLET[nowBulletNum].InitBullet(BulletTypeNUM++ % 8);
				YS_BULLET[nowBulletNum].BulletPos = (GetPos() + Centor);
				nowBulletNum++;
			}


			Bullettime = curTime;
		}

	}
	if (YS_BULLETMAXNUM <= nowBulletNum) {
		nowBulletNum = 0;
	}


	//������
	MonsterMove();

}

void YS_SAM::Realse_YS()
{
	YS_SAM::MonsterRealse();
	for (int i = 0; i < YS_BULLETMAXNUM; i++) {
		YS_BULLET[i].RealseBullet();
	}
}

void YS_SAM::Draw_YS()
{
	YS_SAM::MonsterDraw();
	for (int i = 0; i < YS_BULLETMAXNUM; i++) {

		YS_BULLET[i].DrawBullet();
	}
}

void YS_SAM::Init_YS()
{
	AniInit(L"image/Monster/Sam/YS.png", 1, 1, 1, 1, 1);
	Centor = { (FLOAT)image.rect.right / 2,(FLOAT)image.rect.bottom / 2,0 };
	for (int i = 0; i < YS_BULLETMAXNUM; i++) {


		//YS_BULLET[i].Bullet.AniInit(L"image/Bullet/samBullet/SungchanSem_Bullet.png", 1, 1, 1, 1, 1);
		YS_BULLET[i].Bullet.AniInit(L"image/Bullet/samBullet/YunsungSem_Bullet.png", 1, 1, 1, 1, 1);


		BulletTypeNUM = i % 8;
		YS_BULLET[i].InitBullet(i % 8);

		YS_BULLET[i].Bullet.SetPos({ -100,-100,0 });
		speed = 8;

	}
	SetPos({ -1000, 0, 0 });

}

void YS_SAM::Init_YS1()
{

	AniInit(L"image/Monster/Sam/YS1.png", 1, 1, 1, 1, 1);
	Centor = { (FLOAT)image.rect.right / 2,(FLOAT)image.rect.bottom / 2,0 };
	for (int i = 0; i < YS_BULLETMAXNUM; i++) {


		//YS_BULLET[i].Bullet.AniInit(L"image/Bullet/samBullet/SungchanSem_Bullet.png", 1, 1, 1, 1, 1);
		YS_BULLET[i].Bullet.AniInit(L"image/Bullet/samBullet/YunsungSem_Bullet.png", 1, 1, 1, 1, 1);


		BulletTypeNUM = i % 8;
		YS_BULLET[i].InitBullet(i % 8);

		YS_BULLET[i].Bullet.SetPos({ -100,-100,0 });
		speed = 8;

	}
	SetPos({ -1000, 0, 0 });


}

void YS_SAM::MonsterMove()
{

	DWORD curTime = GetTickCount64();
	if (Pos.y <= 100 && SpoonAni == false)
	{
		Pos.y++;
	}
	else	SpoonAni = true;

	if (SpoonAni == true) {
		Pos.x -= MoveSpeedx;
		Pos.y -= MoveSpeedy;
	}
	if (Pos.x < 250 || Pos.x > 500) {
		MoveSpeedx *= -1;

	}
	if (Pos.y < 100 || Pos.y > 500) {
		MoveSpeedy *= -1;

	}





	SetPos(Pos);
}





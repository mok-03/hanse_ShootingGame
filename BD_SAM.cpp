#include "DXUT.h"
#include "BD_SAM.h"

void BD_SAM::Update_BD()
{
	DWORD curTime = GetTickCount64();
	//총알이랑 몬스터 애니메이션 없음
	//BD_SAM::MonsterUpdate();

	for (int i = 0; i < BD_BULLETMAXNUM; i++) {
		//BD_BULLET[i].UpdateBullet();
			//총알 움직임
		if (BulletH[i] == true) {

			BD_BULLET[i].Bullet.SetPos(BD_BULLET[i].BulletPos);
			BD_BULLET[i].BulletPos = (BD_BULLET[i].Shootting(BD_BULLET[i].Bullet, BD_BULLET[i].BulletPos, speed));
		}
		else {
			BD_BULLET[i].Bullet.SetPos({ -1000,1000,0 });
		}

		//총알 초기화
		if (BD_BULLET[i].BulletPos.y > 1200 ||
			BD_BULLET[i].BulletPos.y < -1200 ||
			BD_BULLET[i].BulletPos.x > 1200 ||
			BD_BULLET[i].BulletPos.x < -1200
			) {
			BulletH[i] = false;
		}
	}
	//BD_BULLET[5].BulletPos.y +=  0.5f;
	//총알발사
	if (nowBulletNum >= 0 && nowBulletNum < BD_BULLETMAXNUM && curTime - Bullettime > 50 && SpoonAni == true) {
		if (BulletH[nowBulletNum] == false) {

			if (BD_BULLETMAXNUM <= nowBulletNum) {
				nowBulletNum = 0;
			}
			BulletH[nowBulletNum] = true;
			BD_BULLET[nowBulletNum].InitBullet(BulletTypeNUM++ % 8);
			BD_BULLET[nowBulletNum].BulletPos = (GetPos() + Centor);
			nowBulletNum++;


		}

			Bullettime = curTime;
	}

	if (BD_BULLETMAXNUM <= nowBulletNum) {
		nowBulletNum = 0;
	}
	//움직임
	MonsterMove();

}

void BD_SAM::Realse_BD()
{
	BD_SAM::MonsterRealse();
	for (int i = 0; i < BD_BULLETMAXNUM; i++) {
		BD_BULLET[i].RealseBullet();
	}
}

void BD_SAM::Draw_BD()
{
	BD_SAM::MonsterDraw();
	for (int i = 0; i < BD_BULLETMAXNUM; i++) {

		BD_BULLET[i].DrawBullet();
	}
}

void BD_SAM::Init_BD()
{
	AniInit(L"image/Monster/Sam/DY.png", 1, 1, 1, 1, 1);
	Centor = { (FLOAT)image.rect.right / 2,(FLOAT)image.rect.bottom / 2,0 };
	for (int i = 0; i < BD_BULLETMAXNUM; i++) {


		//BD_BULLET[i].Bullet.AniInit(L"image/Bullet/samBullet/SungchanSem_Bullet.png", 1, 1, 1, 1, 1);
		BD_BULLET[i].Bullet.AniInit(L"image/Bullet/samBullet/Dragon_Bullet.png", 1, 1, 1, 1, 1);

		BulletTypeNUM = i % 8;
		BD_BULLET[i].InitBullet(i % 8);

		BD_BULLET[i].Bullet.SetPos({ -100,-100,0 });
		speed = 8;

	}
	SetPos({ -1000, 0, 0 });

}

void BD_SAM::MonsterMove()
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





#include "DXUT.h"
#include "SC_SAM.h"

void SC_SAM::Update_CS()
{
	DWORD curTime = GetTickCount64();
	//총알이랑 몬스터 애니메이션 없음
	//SC_SAM::MonsterUpdate();
	
	for (int i = 0; i < CS_BULLETMAXNUM; i++) {	
		//총알 초기화
		if (CS_BULLET[i].BulletPos.y > 1200||
			CS_BULLET[i].BulletPos.y < -200||
			CS_BULLET[i].BulletPos.x > 1000||
			CS_BULLET[i].BulletPos.x < -200
			)
		{
			BulletH[i]=0;

		}	
		//CS_BULLET[i].UpdateBullet();
			//총알 움직임
		if (BulletH[i] == true) {

			CS_BULLET[i].Bullet.SetPos(CS_BULLET[i].BulletPos);
			CS_BULLET[i].BulletPos = (CS_BULLET[i].Shootting(CS_BULLET[i].Bullet, CS_BULLET[i].BulletPos, speed));
		}
		else {
			CS_BULLET[i].Bullet.SetPos({ -1000,1000,0 });
		}

	
	}
	//CS_BULLET[5].BulletPos.y +=  0.5f;
	//총알발사
	if (nowBulletNum >= 0 && nowBulletNum < CS_BULLETMAXNUM-1 && curTime - Bullettime > 1000 && SpoonAni == true) {
		if (BulletH[nowBulletNum] == false) {
			for (int i = 0; i < 6; i++) {

				if (CS_BULLETMAXNUM <= nowBulletNum) {
					nowBulletNum = 0;
				
				}

			BulletH[nowBulletNum] = true;
			CS_BULLET[nowBulletNum].InitBullet((BulletTypeNUM));
			CS_BULLET[nowBulletNum].BulletPos = (GetPos()+ Centor);
			CS_BULLET[nowBulletNum].BulletPos.x = (GetPos().x+ Centor.x +i*30);
				nowBulletNum++;
			
			}
			BulletTypeNUM = 6+BulletTypeNUM%10 ;
			Bullettime = curTime;
		}

		
	}
	if (CS_BULLETMAXNUM <= nowBulletNum) {
		nowBulletNum = 0;

	}

	//움직임
	MonsterMove();

}

void SC_SAM::Realse_CS()
{
	SC_SAM::MonsterRealse();
	for (int i = 0; i < CS_BULLETMAXNUM; i++) {
		CS_BULLET[i].RealseBullet();
	}
}

void SC_SAM::Draw_CS()
{
	SC_SAM::MonsterDraw();
	for (int i = 0; i < CS_BULLETMAXNUM; i++) {
	
		CS_BULLET[i].DrawBullet();
	}
}

void SC_SAM::Init_CS()
{
	AniInit(L"image/Monster/Sam/SC.png", 1, 1, 1, 1, 1);
	Centor = { (FLOAT)image.rect.right / 2,(FLOAT)image.rect.bottom / 2,0 };
	for (int i = 0; i < CS_BULLETMAXNUM; i++) {


		CS_BULLET[i].Bullet.AniInit(L"image/Bullet/samBullet/SungchanSem_Bullet.png", 1, 1, 1, 1, 1);
		//CS_BULLET[i].Bullet.AniInit(L"image/Bullet/samBullet/SungchanSem_Bullet.png", 1, 1, 1, 1, 1);

		CS_BULLET[i].Bullet.SetPos({ -100,-100,0 });


	}	
	speed = 8;
SetPos({ -1000, 0, 0 });
}

void SC_SAM::MonsterMove()
{

	DWORD curTime = GetTickCount64();
	if (Pos.y <=100&& SpoonAni == false)
	{
		Pos.y ++;
	}else	SpoonAni = true;
	
	if (SpoonAni == true) {
		Pos.x -= MoveSpeed;

	}
	if (Pos.x < 150 || Pos.x > 700) {
		MoveSpeed *= -1;

	}
	

	SetPos(Pos);
}





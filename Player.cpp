#include "DXUT.h"
#include "Player.h"

void Player::InitPlayer()
{
	PlayerAni.AniInit(L"image/Player/Player.png", 4, 200, 1);
	PlayerAni.SetPos(D3DXVECTOR3(450, 700, 0));
	PlayerPos = D3DXVECTOR3(450, 700, 0);

	for (int i = 0; i < MAXBULLET; i++) { //이후 총알 클레스 제작하여 풀링기법사용할것임
		Bullet[i].AniInit(L"image/Bullet/PlayerBullet/puchang.png", 4, 30, 1);
		Bullet[i].SetPos(D3DXVECTOR3(-100, -100, 0));
		BulletPos[i]= (D3DXVECTOR3(-100, -100, 0));

	}
	for (int i = 0; i < HP; i++) {
		HPspritePlayer[i].SetImage(L"image/Player/HP/player_heart.png");
		HPspritePlayer[i].SetPos(D3DXVECTOR3(100+i*50, 900, 0));

	}

}
void Player::UpdatePlayer()
{

	PlayerAni.Update();
	KeySet();
	PlayerAni.SetPos(PlayerPos);
	for (int i = 0; i < MAXBULLET; i++) {
		Bullet[i].Update();
		BulletPos[i]= (D3DXVECTOR3(BulletPos[i].x, --BulletPos[i].y, 0));
		BulletPos[i].y -= 5;
		Bullet[i].SetPos(D3DXVECTOR3(BulletPos[i].x, BulletPos[i].y, 0));
		if (Bullet[i].GetPos().y <= 0) {
			BulletH[i] = false;
		}
	}


	
}

void Player::RealsePlayer()
{
	PlayerAni.Release();
	for (int i = 0; i < MAXBULLET; i++)
		Bullet[i].Release();
	for (int i = 0; i < 10; i++) {
		HPspritePlayer[i].Release();

	}
}

void Player::DrawPlayer()
{
	PlayerAni.Draw();

	for (int i = 0; i < MAXBULLET; i++)
		Bullet[i].Draw();

	for (int i = 0; i < HP; i++) {
		HPspritePlayer[i].Draw();

	}
}

void Player::KeySet()
{
	if (GetAsyncKeyState(VK_LEFT)) {
		MoveLeft();
	};
	if (GetAsyncKeyState(VK_RIGHT)) {
		MoveRight();
	};
	if (GetAsyncKeyState(VK_UP)) {
		MoveUP();
	};
	if (GetAsyncKeyState(VK_DOWN)) {
		MoveDown();
	};
	if (GetAsyncKeyState(VK_SPACE)) {
		Shootting();
	};
}

void Player::MoveLeft()
{
	if (PlayerPos.x > 0 )
	PlayerPos.x -= Speed;
}

void Player::MoveRight()
{
	if(PlayerPos.x <1024-PlayerAni.frameWidth)
	PlayerPos.x += Speed;
}

void Player::MoveDown()
{
	if (PlayerPos.y < 1024 - PlayerAni.frameHeight)
	PlayerPos.y += Speed;
}

void Player::MoveUP()
{
	if (PlayerPos.y > 0)
	PlayerPos.y -= Speed;
}


//총알
void Player::Shootting() //스페이스 누르면 Shootting 실행
{
	//시간제한주기
	DWORD curTime = GetTickCount64();

	if (BulletNum >= 0 && BulletNum < MAXBULLET && curTime - BulletTime > 250) {
		if (BulletH[BulletNum] == false) {
			BulletH[BulletNum] = true;
			//총알발사
			BulletPos[BulletNum] = (D3DXVECTOR3(PlayerPos.x, PlayerPos.y + 30, 0));
			Bullet[BulletNum].SetPos(BulletPos[BulletNum]);
			BulletTime = curTime;
		}
		BulletNum--;
	}
	else {
		BulletNum = 19;
	}
}

void Player::BulletDiE(Ani_spriteActor(*))
{
}

void Player::HitDamge()
{
	DWORD curTime = GetTickCount64();


	//if ( curTime - HiTTime > 100) {
	//	
	//	HP--;
	//	HitBullet = false;
	//	HiTTime = curTime;
	//}
	
}

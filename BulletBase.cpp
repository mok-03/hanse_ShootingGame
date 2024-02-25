#include "DXUT.h"
#include "BulletBase.h"



void BulletBase::UpdateBullet()
{
	Bullet.Update();
}


//realse
void BulletBase::RealseBullet()
{
	Bullet.Release();
}
//그리기
void BulletBase::DrawBullet()
{
	Bullet.Draw();	
}
//함수 넣어주는 함수
void BulletBase::SETBulletTiype( D3DXVECTOR3(_Funce(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed)))
{
	this->Shootting = _Funce;
}






void BulletBase::InitBullet(int Cas)
{
	switch (Cas)
	{
	case 0:
		this->SETBulletTiype(Shutting_Under);
		break;
	case 1:
		this->SETBulletTiype(Shutting_LeftUnder);
		break;
	case 2:
		this->SETBulletTiype(Shutting_Left);
		break;
	case 3:
		this->SETBulletTiype(Shutting_LeftUP);
		break;
	case 4:
		this->SETBulletTiype(Shutting_UP);
		break;
	case 5:
		this->SETBulletTiype(Shutting_RightUP);
		break;
	case 6 :
		this->SETBulletTiype(Shutting_Right);
		break;
	case 7:
		this->SETBulletTiype(Shutting_RightUnder);
		break;
	case 8:
		this->SETBulletTiype(Shutting_Under);
		break;
	case 9:
		this->SETBulletTiype(Shutting_LeftUnder);
		break;

	default:
		this->SETBulletTiype();
		break;
	}

}



//슈팅
	D3DXVECTOR3 BulletBase::Shutting_Under(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed)
	{
		//_Bullet.SetPos(D3DXVECTOR3(_BulletPos.x, _BulletPos.y -= _speed, 0));
		return (D3DXVECTOR3(_BulletPos.x, _BulletPos.y += _speed, 0));

	}
	D3DXVECTOR3 BulletBase::Shutting_LeftUnder(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed)
	 {
		 return (D3DXVECTOR3(_BulletPos.x -= _speed, _BulletPos.y += _speed, 0));

	 }
	 D3DXVECTOR3 BulletBase::Shutting_Left(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed)
	{
		 return (D3DXVECTOR3(_BulletPos.x -= _speed, _BulletPos.y , 0));
		  
	}
	 D3DXVECTOR3 BulletBase::Shutting_LeftUP(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed)
	 {
		 return (D3DXVECTOR3(_BulletPos.x -= _speed, _BulletPos.y -= _speed, 0));

	 }
	 D3DXVECTOR3 BulletBase::Shutting_UP(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed)
	 {
		 return (D3DXVECTOR3(_BulletPos.x , _BulletPos.y -= _speed, 0));

	 }
	 D3DXVECTOR3 BulletBase::Shutting_RightUP(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed)
	 {
		 return (D3DXVECTOR3(_BulletPos.x += _speed, _BulletPos.y -= _speed, 0));

	 }
	 D3DXVECTOR3 BulletBase::Shutting_Right(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed)
	{
		 return (D3DXVECTOR3(_BulletPos.x += _speed, _BulletPos.y, 0));
		 
	}

	 D3DXVECTOR3 BulletBase::Shutting_RightUnder(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed)
	 {
		 return (D3DXVECTOR3(_BulletPos.x += _speed, _BulletPos.y+=_speed, 0));

	 }


void test() {
	BulletBase *B =new BulletBase;
	//B.InitBullet(1,B.Shutting_Under);
	B->SETBulletTiype(); //

}
//InitBullet(Shutting_Under, 0); 사용법.
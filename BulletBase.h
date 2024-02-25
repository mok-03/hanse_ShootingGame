#pragma once
#include "Ani_spriteActor.h"
/*
enum ShoottingSettum
{

}STN;
*/
class BulletBase
{ 
private:
	INT BulletNum;
	
	DWORD BulletTime;
	int speed;
	
public:
	Ani_spriteActor Bullet;
	D3DXVECTOR3 BulletPos;

	void SETBulletTiype(  D3DXVECTOR3(_Funce(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed))=Shutting_Under);
	void UpdateBullet();
	void RealseBullet();
	void DrawBullet();
	void InitBullet(int Cas);
	 //총쏘기? 
	//함수 포인터로 어떤 형식으로 날라갈지 정해준다 init 에서 이넘으로 선택?
	// 리턴값으로 계산을 해볼까? 리턴값이 필요할까?

	D3DXVECTOR3(*Shootting)(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos,int _speed);
	// ㄴ어떤 방식으로 총알이나가는지 함수
	 //  ㄴ 기본세팅 shutting_under
	inline static D3DXVECTOR3 Shutting_Under(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	inline static D3DXVECTOR3 Shutting_Left(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	inline static D3DXVECTOR3 Shutting_Right(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	inline static D3DXVECTOR3 Shutting_LeftUnder(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	inline static D3DXVECTOR3 Shutting_RightUnder(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	inline static D3DXVECTOR3 Shutting_RightUP(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	inline static D3DXVECTOR3 Shutting_LeftUP(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	inline static D3DXVECTOR3 Shutting_UP(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	//아마 left right 는 좌우 좌우 한번씩 쏘는 방법에서 쓰지않을까?


	//static 이여야 매게변수로 참조가 가능했다.
	//init 에서 원하는 함수 받아써야함.
	
	//몬스터마다 직접 배열선언 해줄까 아니면
	// 원형 링크드 리스트로 
	//몬스터  패턴대로 사용하며 풀링 방식 사용해서
	//자동 대입?
	//자동 대입 나중에 구현하자
	

};


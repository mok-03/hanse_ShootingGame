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
	 //�ѽ��? 
	//�Լ� �����ͷ� � �������� ������ �����ش� init ���� �̳����� ����?
	// ���ϰ����� ����� �غ���? ���ϰ��� �ʿ��ұ�?

	D3DXVECTOR3(*Shootting)(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos,int _speed);
	// ��� ������� �Ѿ��̳������� �Լ�
	 //  �� �⺻���� shutting_under
	inline static D3DXVECTOR3 Shutting_Under(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	inline static D3DXVECTOR3 Shutting_Left(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	inline static D3DXVECTOR3 Shutting_Right(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	inline static D3DXVECTOR3 Shutting_LeftUnder(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	inline static D3DXVECTOR3 Shutting_RightUnder(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	inline static D3DXVECTOR3 Shutting_RightUP(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	inline static D3DXVECTOR3 Shutting_LeftUP(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	inline static D3DXVECTOR3 Shutting_UP(Ani_spriteActor _Bullet, D3DXVECTOR3 _BulletPos, int _speed);
	//�Ƹ� left right �� �¿� �¿� �ѹ��� ��� ������� ����������?


	//static �̿��� �ŰԺ����� ������ �����ߴ�.
	//init ���� ���ϴ� �Լ� �޾ƽ����.
	
	//���͸��� ���� �迭���� ���ٱ� �ƴϸ�
	// ���� ��ũ�� ����Ʈ�� 
	//����  ���ϴ�� ����ϸ� Ǯ�� ��� ����ؼ�
	//�ڵ� ����?
	//�ڵ� ���� ���߿� ��������
	

};


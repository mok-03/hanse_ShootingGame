#pragma once
#include "Ani_spriteActor.h"
#include "BulletBase.h"
class BaseMonster :
    public Ani_spriteActor
{
protected:
   int Monster_HP; 
   BOOL MonsterArrive;//���� ��������

   int AttackSpeed;
public:
    float speed ;
    D3DXVECTOR3 Centor;
    INT nowBulletNum =0;
    FLOAT Bullettime;

   void  MonsterUpdate();
   void  MonsterDraw();
   void  MonsterRealse();
};

//���ͺ��̽��� �⺻���� �ΰ� 
//���͵��� �����ѵ�
//������ �޴������� ���θ� ��� �����Ұ��̴�.


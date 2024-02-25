#pragma once
#include "Ani_spriteActor.h"
#include "BulletBase.h"
class BaseMonster :
    public Ani_spriteActor
{
protected:
   int Monster_HP; 
   BOOL MonsterArrive;//몬스터 생존여부

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

//몬스터베이스를 기본으로 두고 
//몬스터들을 제작한뒤
//문스터 메니저에서 전부를 잡고 관리할것이다.


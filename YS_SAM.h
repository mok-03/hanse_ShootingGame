#pragma once


#include "BaseMonster.h"
#include <list>

#define YS_BULLETMAXNUM 50

class YS_SAM :
    public BaseMonster
{
    //std::list<BulletBase> YS_BULLET{ new BulletBase,new BulletBase };
    //리스트 나중에 사용하자

    INT BulletTypeNUM = 1;
    D3DXVECTOR3 Pos = { 400,-180,0 };
public:    
    BOOL  SpoonAni = false;

    INT MoveSpeedy = 2;
    INT MoveSpeedx = 2;

    INT HP = 15;
    BOOL BulletH[YS_BULLETMAXNUM];
    BulletBase YS_BULLET[YS_BULLETMAXNUM];
    void Update_YS();
    void Realse_YS();
    void Draw_YS();
    void Init_YS();
    void Init_YS1();
    void MonsterMove();


};


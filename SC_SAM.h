#pragma once


#include "BaseMonster.h"
#include <list>

#define CS_BULLETMAXNUM 50

class SC_SAM :
    public BaseMonster
{
    //std::list<BulletBase> SC_BULLET{ new BulletBase,new BulletBase };
    //리스트 나중에 사용하자
 
    INT BulletTypeNUM =1;
    D3DXVECTOR3 Pos = {400,-180,0};
    INT MoveSpeed = 6;
public:  
    BOOL  SpoonAni = false;

    INT HP =20;
    BOOL BulletH[CS_BULLETMAXNUM];
    BulletBase CS_BULLET[CS_BULLETMAXNUM];
    void Update_CS();
    void Realse_CS();
    void Draw_CS();
    void Init_CS();
    void MonsterMove();


};


#pragma once


#include "BaseMonster.h"
#include <list>

#define BD_BULLETMAXNUM 50

class BD_SAM :
    public BaseMonster
{
    //std::list<BulletBase> SC_BULLET{ new BulletBase,new BulletBase };
    //리스트 나중에 사용하자

    INT BulletTypeNUM = 0;
    D3DXVECTOR3 Pos = { 400,-180,0 };
    INT MoveSpeedx = 2;
    INT MoveSpeedy = 2;
public:
    BOOL  SpoonAni = false;

    INT HP = 20;
    BOOL BulletH[BD_BULLETMAXNUM];
    BulletBase BD_BULLET[BD_BULLETMAXNUM];
    void Update_BD();
    void Realse_BD();
    void Draw_BD();
    void Init_BD();
    void MonsterMove();

};
#pragma once
#include "spriteActor.h"
#include "Ani_spriteActor.h"
#include "Player.h"
class CollisionSystem
{

};
class AABB {
public:
	BOOL operator()(spriteActor A, spriteActor B);
	BOOL operator()(Ani_spriteActor A, spriteActor B);
	BOOL operator()(Ani_spriteActor A, Ani_spriteActor B);
};

//콜리전 시스템 
//AABB로 제작후 OBB로 전환

//충돌 확인은 오브젝트 정보를 받아와서비교 하는거 만들고
//BSP 같은 알고리즘으로 처리해줄것임


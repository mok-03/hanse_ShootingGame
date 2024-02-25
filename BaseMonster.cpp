#include "DXUT.h"
#include "BaseMonster.h"

void BaseMonster::MonsterUpdate()
{
	Ani_spriteActor::Update();
}

void BaseMonster::MonsterDraw()
{
	Ani_spriteActor::Draw();
}

void BaseMonster::MonsterRealse()
{
	Ani_spriteActor::Release();
}

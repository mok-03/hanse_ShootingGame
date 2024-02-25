#include "DXUT.h"
#include "CollisionSystem.h"

BOOL AABB::operator()(Ani_spriteActor A, Ani_spriteActor B)
{
	if (A.frameWidth + A.GetPos().x >  B.GetPos().x &&
		A.image.rect.left + A.GetPos().x < B.frameWidth + B.GetPos().x &&
		A.image.rect.bottom + A.GetPos().y > B.image.rect.top + B.GetPos().y &&
		 A.GetPos().y < B.image.rect.bottom + B.GetPos().y
		) {
		return true;
	}
	return false;

}

//BOOL AABB::operator()(Ani_spriteActor A, Player B)
//{
//	if (A.frameWidth + A.GetPos().x > B.PlayerAni.GetPos().x &&
//		A.image.rect.left + A.GetPos().x < B.PlayerAni.frameWidth + B.PlayerAni.GetPos().x &&
//		A.image.rect.bottom + A.GetPos().y > B.PlayerAni.image.rect.top-50 + B.PlayerAni.GetPos().y &&
//		A.GetPos().y < B.PlayerAni.image.rect.bottom + 50 + B.PlayerAni.GetPos().y
//		) {
//		return true;
//	}
//	return false;
//}
//

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

//�ݸ��� �ý��� 
//AABB�� ������ OBB�� ��ȯ

//�浹 Ȯ���� ������Ʈ ������ �޾ƿͼ��� �ϴ°� �����
//BSP ���� �˰������� ó�����ٰ���


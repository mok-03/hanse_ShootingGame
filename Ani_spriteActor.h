#pragma once
#include "spriteActor.h"
class Ani_spriteActor :
    public spriteActor
{
public:

	DWORD index;		//�׸��� �׷��� �ε���
	DWORD Hindex;      // ����  �׷��� �ε���

	INT nFrameCount;	//���������� ���� //���͸��� �߰��������
	DWORD oldTime;		//���� �������� �׷��� �ð�
	DWORD frameWidth;	//������ ���� ũ��
	DWORD frameHeight;	//������ ���� ũ��

	DWORD aniSpeed ;		//������ ��ȯ �ӵ�  ���͸��� �߰��������
	INT HFrameNum;      //���� ������ ����
	
	INT StartW_Frame=0;


  //���� ��ü�� ���� ������ ���ϸ��̼� ������ ���ϰ� �ϴ°ɷ� �����ϱ�

	void Update();
	void AniInit(std::wstring _filename, int _FrameNum, int _FrameTime, int _HFrameNum, int _HFrame = 0, int _Index = 0);
	
};


#include "DXUT.h"
#include "Ani_spriteActor.h"
	//�ִϸ��̼� ���� ���⶧ �ִϸ��̼� ���翩��,�������� ��� �Ұ��ΰ�.

	/*
	���ϸ��̼� �� �ΰ��϶��ϱ�
	���ϸ��̼� ������ vector �� ����
	������ �Ľ��� �ް� ������ŭ vector�� �÷��� 
	������ ���� �ִϸ��̼� ���� ��� �� �ø��� �ִ�
	
	�Ǵ� ���ϸ��̼� ����&������ �ӵ� ������ �迭�� �߰�����.
	���δ� �ϳ��� �־ ��������� 
	�ִϸ��̼� ������ �ӵ��� ���� �� ���̰� �����ϱ�.

	*/

void Ani_spriteActor::Update()
{

	DWORD curTime = GetTickCount64();
	
	////����
	//image.rect.top = frameHeight * Hindex;
	//image.rect.bottom = image.rect.top + frameHeight;

	if (curTime - oldTime > aniSpeed) {
		index++;
		//����
		index = index % nFrameCount;
		image.rect.left = frameWidth * (index+StartW_Frame);//���� ������
		image.rect.right = image.rect.left + frameWidth;
		

		oldTime = curTime;
	}
}

void Ani_spriteActor::AniInit(std::wstring _filename, int _FrameNum, int _FrameTime, int _HFrameNum,int _HFrame , int _Index)
{
	SetImage(_filename);
	this->index = _Index;
	this->nFrameCount = _FrameNum;
	this->aniSpeed = _FrameTime;
	this->HFrameNum = _HFrameNum;
	this->Hindex = _HFrame;
	this->frameWidth = this->image.info.Width/_FrameNum;
	this->frameHeight= this->image.info.Height/_HFrameNum;
}



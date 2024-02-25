#include "DXUT.h"
#include "Ani_spriteActor.h"
	//애니메이션 동작 멈출때 애니메이션 존재여부,멈췄을때 어떻게 할것인가.

	/*
	에니메이션 이 두개일때니까
	에니메이션 정보를 vector 로 만들어서
	데이터 파싱을 받고 개수만큼 vector을 늘려서 
	데이터 정보 애니메이션 정보 등등 을 늘릴수 있다
	
	또는 에니메이션 가로&프레임 속도 개수만 배열로 추가하자.
	세로는 하나만 있어도 충분하지만 
	애니메이션 프레임 속도와 개수 만 차이가 있으니까.

	*/

void Ani_spriteActor::Update()
{

	DWORD curTime = GetTickCount64();
	
	////세로
	//image.rect.top = frameHeight * Hindex;
	//image.rect.bottom = image.rect.top + frameHeight;

	if (curTime - oldTime > aniSpeed) {
		index++;
		//가로
		index = index % nFrameCount;
		image.rect.left = frameWidth * (index+StartW_Frame);//시작 프레임
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



#pragma once
#include "spriteActor.h"
class Ani_spriteActor :
    public spriteActor
{
public:

	DWORD index;		//그림이 그려질 인덱스
	DWORD Hindex;      // 세로  그려질 인덱스

	INT nFrameCount;	//가로프레임 개수 //몬스터마다 추가해줘야함
	DWORD oldTime;		//이전 프레임이 그려진 시간
	DWORD frameWidth;	//프레임 가로 크기
	DWORD frameHeight;	//프레임 세로 크기

	DWORD aniSpeed ;		//프레임 전환 속도  몬스터마다 추가해줘야함
	INT HFrameNum;      //세로 프레임 개수
	
	INT StartW_Frame=0;


  //하위 객체로 몬스터 제작후 에니메이션 프레임 변하게 하는걸로 조절하기

	void Update();
	void AniInit(std::wstring _filename, int _FrameNum, int _FrameTime, int _HFrameNum, int _HFrame = 0, int _Index = 0);
	
};


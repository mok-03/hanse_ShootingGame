//--------------------------------------------------------------------------------------
// File: shooting.cpp
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
// File: EmptyProject9.cpp
//
// Empty starting point for new Direct3D 9 and/or Direct3D 11 applications
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#include "DXUT.h"
#include "resource.h"
#include "LPspriteBase.h"
#include  "image.h"
#include "spriteActor.h"
#include "Ani_spriteActor.h"
#include "Player.h"
#include "SC_SAM.h"
#include "BD_SAM.h"
#include "YS_SAM.h"
#include "CollisionSystem.h"
#include<vector>
AABB aabb;

spriteActor testActor;
Ani_spriteActor AniTestActor;

spriteActor StartImage;
spriteActor DIEImage;
spriteActor WINImage;


spriteActor Map[2];

Player player;
SC_SAM SC;
BD_SAM DB;
YS_SAM YS;
YS_SAM YS1;

INT StageNUM = 1;

//몬스터
/*
std::vector 로 선언후 사용해서
추가할때 간단하게 vector 뒤에 끼워넣는 형식으로 사용하자.
잡몹
*/
D3DXVECTOR3 MapPos1 = { 0, 0, 0 };
D3DXVECTOR3 MapPos2 = { 0,-1024,0 };

enum GamesetNum //Main=1,InGame =2, Die =3, Win=4;
{
	MainMenu,
	InGame,
	DIE,
	WIN,
};

void init() {

	testActor.SetImage(L"Enmy09.png");
	testActor.Init(D3DXVECTOR3(10, 10, 0));

	StartImage.SetImage(L"image/map/Startimage.jpg");
	DIEImage.SetImage(L"image/map/DIE.jpg");
	WINImage.SetImage(L"image/map/Win.jpg");

	AniTestActor.AniInit(L"image/Monster/2B_Robot/Efect/2b_robot_shottingEfect.png", 9, 50, 1);
	AniTestActor.SetPos(D3DXVECTOR3(35, 60, 0));

	Map[0].SetImage(L"image/Map/map1.png");
	Map[1].SetImage(L"image/Map/map2.png");

	player.InitPlayer();
	SC.Init_CS();
	DB.Init_BD();
	YS.Init_YS();
	YS1.Init_YS1();
	YS1.MoveSpeedy = 1;
	YS1.MoveSpeedx = 1;
	//YS1.YS_BULLET[0].Bullet.


}
void Update() {
	AniTestActor.Update();
	switch (StageNUM)
	{
	case 1:
		
		if (GetAsyncKeyState(VK_SPACE)) {
			StageNUM = 2;
		}
		break;
	case 2:
		//map update
		SC.Update_CS();
		//승찬쌤 피격
		for (int i = 0; i < MAXBULLET; i++) {
			if (aabb(player.Bullet[i], SC)&& SC.SpoonAni == true) {
				player.BulletH[i] = false;
				player.Bullet[i].SetPos({ 1000,1000,0 });
				player.BulletPos[i] = (D3DXVECTOR3(1200, 1000, 0));
				SC.HP--;
				if (SC.HP < 0)break;
				// player.BulletDiE(&player.Bullet[i]);

			}

		}
		if (SC.HP < 0) {

			for (int i = 0; i < CS_BULLETMAXNUM; i++) {
				SC.BulletH[i] = false;
				SC.CS_BULLET[i].Bullet.SetPos({ -20000,0,0 });
			}
			SC.SetPos({ -2000, 0, 0 });
			StageNUM = 3;
		}
		for (int i = 0; i < CS_BULLETMAXNUM; i++) {
			if (player.HitBullet == false && aabb(SC.CS_BULLET[i].Bullet, player.PlayerAni) &&
				SC.BulletH[i] == true) {
				SC.BulletH[i] = false;

				player.HP--;

				//SC.CS_BULLET->BulletPos = {1000,1000,0} ;

				   // player.HitBullet = true;
			}
		}
		break;
	case 3:
		DB.Update_BD();
		for (int i = 0; i < MAXBULLET; i++) {
			if (aabb(player.Bullet[i], DB) && DB.SpoonAni == true) {
				player.BulletH[i] = false;
				player.Bullet[i].SetPos({ 1000,1000,0 });
				player.BulletPos[i] = (D3DXVECTOR3(1200, 1000, 0));
				DB.HP--;
				if (DB.HP < 0)break;

				// player.BulletDiE(&player.Bullet[i]);

			}
		}

		if (DB.HP < 0) {

			for (int i = 0; i < BD_BULLETMAXNUM; i++) {
				DB.BulletH[i] = false;
				DB.BD_BULLET[i].Bullet.SetPos({ -20000,0,0 });
			}
			DB.SetPos({ -2000, 0, 0 });
			StageNUM = 4;
		}

		for (int i = 0; i < BD_BULLETMAXNUM; i++) {
			if (player.HitBullet == false && aabb(DB.BD_BULLET[i].Bullet, player.PlayerAni) &&
				DB.BulletH[i] == true) {
				DB.BulletH[i] = false;
				player.HP--;

			}
		}
		break;
	case 4:
		//
		YS.Update_YS();
		YS1.Update_YS();

		for (int i = 0; i < MAXBULLET; i++) {
			if (aabb(player.Bullet[i], YS) && YS.SpoonAni == true) {
				player.BulletH[i] = false;
				player.Bullet[i].SetPos({ 1000,1000,0 });
				player.BulletPos[i] = (D3DXVECTOR3(1200, 1000, 0));
				YS.HP--;
				if (YS.HP < 0)break;
			}

		}
		for (int i = 0; i < MAXBULLET; i++) {
			if (aabb(player.Bullet[i], YS1)&& YS1.SpoonAni == true) {
				player.BulletH[i] = false;
				player.Bullet[i].SetPos({ 1000,1000,0 });
				player.BulletPos[i] = (D3DXVECTOR3(1200, 1000, 0));
				YS1.HP--;
				if (YS1.HP < 0)break;
			}

		}

		if (YS.HP < 0) {

			for (int i = 0; i < YS_BULLETMAXNUM; i++) {
				YS.BulletH[i] = false;
				YS.YS_BULLET[i].Bullet.SetPos({ -20000,0,0 });
			}
			for (int i = 0; i < YS_BULLETMAXNUM; i++) {
				YS1.BulletH[i] = false;
				YS1.YS_BULLET[i].Bullet.SetPos({ -20000,0,0 });
			}
			YS.SetPos({ -2000, 0, 0 });
			YS1.SetPos({ -2000, 0, 0 });
			StageNUM = 6;
		}

		for (int i = 0; i < YS_BULLETMAXNUM; i++) {
			if (player.HitBullet == false && aabb(YS.YS_BULLET[i].Bullet, player.PlayerAni) &&
				YS.BulletH[i] == true) {
				YS.BulletH[i] = false;
				player.HP--;
			}

		}

		break;
	default:
		break;

	}

	if (player.HP <= 0) {
		StageNUM = 7;
	}
	MapPos1.y += 4;
	MapPos2.y += 4;
	Map[0].SetPos(MapPos1);
	Map[1].SetPos(MapPos2);
	if (MapPos1.y >= 1024)
		MapPos1.y = -1024;
	if (MapPos2.y >= 1024)
		MapPos2.y = -1024;





	player.UpdatePlayer();

}

void rander() {

	testActor.Draw();
	AniTestActor.Draw();

	Map[0].Draw();
	Map[1].Draw();

	player.DrawPlayer();
	switch (StageNUM)
	{
	case 1:
		StartImage.Draw();
		break;

	case 2:
		SC.Draw_CS();
		break;

	case 3:
		DB.Draw_BD();
		break;

	case 4:		
		YS1.Draw_YS();
		YS.Draw_YS();
		break;

	case 6:
		WINImage.Draw();
		//승리
		break;
	case 7:
		DIEImage.Draw();

		break;
		//패배
	default:
		break;
	}
}
void Realse() {
	testActor.Release();
	AniTestActor.Release();

	Map[0].Release();
	Map[1].Release();

	player.RealsePlayer();

	SC.Realse_CS();
	DB.Realse_BD();
	YS.Realse_YS();
	YS1.Realse_YS();
	StartImage.Release();
	DIEImage.Release();
	WINImage.Release();
}




//--------------------------------------------------------------------------------------
// Rejects any D3D9 devices that aren't acceptable to the app by returning false
//--------------------------------------------------------------------------------------
bool CALLBACK IsD3D9DeviceAcceptable(D3DCAPS9* pCaps, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat,
	bool bWindowed, void* pUserContext)
{
	// Typically want to skip back buffer formats that don't support alpha blending
	IDirect3D9* pD3D = DXUTGetD3D9Object();
	if (FAILED(pD3D->CheckDeviceFormat(pCaps->AdapterOrdinal, pCaps->DeviceType,
		AdapterFormat, D3DUSAGE_QUERY_POSTPIXELSHADER_BLENDING,
		D3DRTYPE_TEXTURE, BackBufferFormat)))
		return false;

	return true;
}


//--------------------------------------------------------------------------------------
// Before a device is created, modify the device settings as needed
//--------------------------------------------------------------------------------------
bool CALLBACK ModifyDeviceSettings(DXUTDeviceSettings* pDeviceSettings, void* pUserContext)
{
	return true;
}


//--------------------------------------------------------------------------------------
// Create any D3D9 resources that will live through a device reset (D3DPOOL_MANAGED)
// and aren't tied to the back buffer size
//--------------------------------------------------------------------------------------
HRESULT CALLBACK OnD3D9CreateDevice(IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
	void* pUserContext)
{
	D3DXCreateSprite(pd3dDevice, &LPspriteBase::LPsprite);

	init();
	return S_OK;
}


//--------------------------------------------------------------------------------------
// Create any D3D9 resources that won't live through a device reset (D3DPOOL_DEFAULT) 
// or that are tied to the back buffer size 
//--------------------------------------------------------------------------------------
HRESULT CALLBACK OnD3D9ResetDevice(IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
	void* pUserContext)
{
	return S_OK;
}


//--------------------------------------------------------------------------------------
// Handle updates to the scene.  This is called regardless of which D3D API is used
//--------------------------------------------------------------------------------------
void CALLBACK OnFrameMove(double fTime, float fElapsedTime, void* pUserContext)
{
	Update();
}


//--------------------------------------------------------------------------------------
// Render the scene using the D3D9 device
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9FrameRender(IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext)
{
	HRESULT hr;

	// Clear the render target and the zbuffer 
	V(pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(0, 45, 50, 170), 1.0f, 0));

	// Render the scene
	if (SUCCEEDED(pd3dDevice->BeginScene()))
	{
		rander();
		V(pd3dDevice->EndScene());
	}
}


//--------------------------------------------------------------------------------------
// Handle messages to the application 
//--------------------------------------------------------------------------------------
LRESULT CALLBACK MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
	bool* pbNoFurtherProcessing, void* pUserContext)
{
	return 0;
}


//--------------------------------------------------------------------------------------
// Release D3D9 resources created in the OnD3D9ResetDevice callback 
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9LostDevice(void* pUserContext)
{
}


//--------------------------------------------------------------------------------------
// Release D3D9 resources created in the OnD3D9CreateDevice callback 
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9DestroyDevice(void* pUserContext)
{
	Realse();
	SAFE_RELEASE(LPspriteBase::LPsprite);
}


//--------------------------------------------------------------------------------------
// Initialize everything and go into a render loop
//--------------------------------------------------------------------------------------
INT WINAPI wWinMain(HINSTANCE, HINSTANCE, LPWSTR, int)
{
	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	// Set the callback functions
	DXUTSetCallbackD3D9DeviceAcceptable(IsD3D9DeviceAcceptable);
	DXUTSetCallbackD3D9DeviceCreated(OnD3D9CreateDevice);
	DXUTSetCallbackD3D9DeviceReset(OnD3D9ResetDevice);
	DXUTSetCallbackD3D9FrameRender(OnD3D9FrameRender);
	DXUTSetCallbackD3D9DeviceLost(OnD3D9LostDevice);
	DXUTSetCallbackD3D9DeviceDestroyed(OnD3D9DestroyDevice);
	DXUTSetCallbackDeviceChanging(ModifyDeviceSettings);
	DXUTSetCallbackMsgProc(MsgProc);
	DXUTSetCallbackFrameMove(OnFrameMove);

	// TODO: Perform any application-level initialization here

	// Initialize DXUT and create the desired Win32 window and Direct3D device for the application
	DXUTInit(true, true); // Parse the command line and show msgboxes
	DXUTSetHotkeyHandling(true, true, true);  // handle the default hotkeys
	DXUTSetCursorSettings(true, true); // Show the cursor and clip it when in full screen
	DXUTCreateWindow(L"shooting");
	DXUTCreateDevice(true, 1024, 1024);

	// Start the render loop
	DXUTMainLoop();

	// TODO: Perform any application-level cleanup here

	return DXUTGetExitCode();
}



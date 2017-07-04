#include "DirectX.h"

//Credits: learn_more, xCyniu, Zooom, Roverturbo, KingOrgy

directx_s DirectX;
CMenu Menu;

//UC Forum for all the verts and prims :)
#define MECPlayers1 ((NumVertices==3229 && primCount==2549)||(NumVertices==1311 && primCount==1377)||(NumVertices==463 && primCount==256)||(NumVertices==67 && primCount==82)||(NumVertices==2080 && primCount==1546)||(NumVertices==661 && primCount==604)||(NumVertices==1972 && primCount==1531)||(NumVertices==2381 && primCount==1607)||(NumVertices==571 && primCount==622)||(NumVertices==407 && primCount==264)||(NumVertices==2080 && primCount==1546)||(NumVertices==1745 && primCount==1450)||(NumVertices==526 && primCount==628)||(NumVertices==1407 && primCount==1568)||(NumVertices==394 && primCount==280))
#define MECPlayers2 ((NumVertices == 551 && primCount == 648 && startIndex == 11805) || (NumVertices == 526 && primCount == 628 && startIndex == 10260) || (NumVertices == 661 && primCount == 604 && startIndex == 9153) || (NumVertices == 571 && primCount == 622 && startIndex == 8394) || (NumVertices == 349 && primCount == 280 && startIndex == 10965) || (NumVertices == 394 && primCount == 280 && startIndex == 12144) || (NumVertices == 1972 && primCount == 1531 && startIndex == 0) || (NumVertices == 2080 && primCount == 1546 && startIndex == 26316) || (NumVertices == 1311 && primCount == 1377 && startIndex == 15345) || (NumVertices == 1665 && primCount == 1533 && startIndex == 32274) || (NumVertices == 3229 && primCount == 2549 && startIndex == 5865) ||  (NumVertices == 1745 && primCount == 1450 && startIndex == 20760) || (NumVertices == 2381 && primCount == 1607 && startIndex == 38085) || (NumVertices == 407 && primCount == 264 && startIndex == 13230) || (NumVertices == 463 && primCount == 256 && startIndex == 13995))
#define USMCPlayers1 ((NumVertices==1270 && primCount==1050)||(NumVertices==456 && primCount==272)||(NumVertices==2675 && primCount==1867)||(NumVertices==495 && primCount==274)||(NumVertices==2240 && primCount==1421)||(NumVertices==782 && primCount==686)||(NumVertices==662 && primCount==692)||(NumVertices==398 && primCount==280)||(NumVertices==361 && primCount==280)||(NumVertices==1073 && primCount==1384)||(NumVertices==341 && primCount==200)||(NumVertices==480 && primCount==574)||(NumVertices==549 && primCount==518)||(NumVertices==2148 && primCount==1486)||(NumVertices==2303 && primCount==1607))
#define USMCPlayers2 ((NumVertices==1518 && primCount==1291)||(NumVertices == 480 && primCount == 574 && startIndex == 11553) || (NumVertices == 549 && primCount == 518 && startIndex == 11727) || (NumVertices == 782 && primCount == 686 && startIndex == 9495) || (NumVertices == 662 && primCount == 692 && startIndex == 9651) || (NumVertices == 398 && primCount == 280 && startIndex == 13281) || (NumVertices == 361 && primCount == 280 && startIndex == 13275) || (NumVertices == 2303 && primCount == 1607 && startIndex == 4557) || (NumVertices == 1270 && primCount == 1050 && startIndex == 0) || (NumVertices == 1518 && primCount == 1291 && startIndex == 10776) || (NumVertices == 2675 && primCount == 1867 && startIndex == 21903) || (NumVertices == 2414 && primCount == 1631 && startIndex == 29052) || (NumVertices == 2148 && primCount == 1486 && startIndex == 16086) || (NumVertices == 2240 && primCount == 1421 && startIndex == 35463) || (NumVertices == 456 && primCount == 272 && startIndex == 14121) || (NumVertices == 495 && primCount == 274 && startIndex == 14115))
#define PLAPlayers1 ((NumVertices==1423 && primCount==1434)||(NumVertices==617 && primCount==642)||(NumVertices==643 && primCount==674)||(NumVertices==1867 && primCount==1486)||(NumVertices==425 && primCount==274)||(NumVertices==422 && primCount==268)||(NumVertices==1803 && primCount==1484)||(NumVertices==75 && primCount==86)||(NumVertices==1321 && primCount==1439))
#define PLAPlayers2 ((NumVertices == 532 && primCount == 574 && startIndex == 11115) || (NumVertices == 486 && primCount == 574 && startIndex == 11331) || (NumVertices == 617 && primCount == 642 && startIndex == 8349) || (NumVertices == 643 && primCount == 674 && startIndex == 8469) || (NumVertices == 406 && primCount == 280 && startIndex == 10275) || (NumVertices == 396 && primCount == 280 && startIndex == 10491) || (NumVertices == 1867 && primCount == 1486 && startIndex == 22305) || (NumVertices == 1423 && primCount == 1434 && startIndex == 10851) || (NumVertices == 1975 && primCount == 1486 && startIndex == 4839) || (NumVertices == 2318 && primCount == 1575 && startIndex == 34329) || (NumVertices == 1854 && primCount == 1500 && startIndex == 16575) || (NumVertices == 1503 && primCount == 1233 && startIndex == 0) || (NumVertices == 1803 && primCount == 1484 && startIndex == 28293) || (NumVertices == 422 && primCount == 268 && startIndex == 13311) || (NumVertices == 425 && primCount == 274 && startIndex == 13095))
#define DEBUG_USMC ((NumVertices == 1282 && primCount == 1620) || (NumVertices == 1176 && primCount == 1348))
#define DEBUG_MEC ((NumVertices == 1183 && primCount == 1490) || (NumVertices == 1383 && primCount == 1587))
#define SkyDE ((NumVertices == 667 && primCount == 1120))
#define Explo ((NumVertices ==  2055 && primCount == 1500) || (NumVertices ==  217 && primCount == 153 && startIndex == 3909) || (NumVertices ==  1396 && primCount == 1303 && startIndex == 0))

HRESULT WINAPI hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	if (!DirectX.Includes)
	{
		if (!DirectX.Line)
			D3DXCreateLine(pDevice, &DirectX.Line);

		if (!DirectX.Font)
			D3DXCreateFont(pDevice, 16, 0, 0, 0, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "Tahoma", &DirectX.Font);

		if (!DirectX.ShaderFront)
			Draw.CreateShader(&DirectX.ShaderFront, pDevice, Menu.RedF, Menu.GreenF, Menu.BlueF, 1.0f);

		if (!DirectX.ShaderBehind)
			Draw.CreateShader(&DirectX.ShaderBehind, pDevice, Menu.RedB, Menu.GreenB, Menu.BlueB, 1.0f);

		if (!DirectX.ShaderBlack)
			Draw.CreateShader(&DirectX.ShaderBlack, pDevice, 0, 0, 0, 1.0f);
		
		if (!DirectX.ShaderExplosive)
			Draw.CreateShader(&DirectX.ShaderExplosive, pDevice, 1.0f, 0, 1.0f, 1.0f);

		DirectX.Includes = true;
	}

	DirectX.Device = pDevice;

	GetCenter(pDevice);

	Draw.String("Arcane Cheats - Battlefield 2", 5, 0, 255, 255, 255);

	if (GetAsyncKeyState(VK_DELETE) & 1)
		Menu.Visible = !Menu.Visible;

	if (Menu.Visible)
		Menu.Paint();

	if (Menu.Crosshair)
		Draw.String("+", DirectX.CenterX - 4, DirectX.CenterY - 6, 255, 255, 255);

	return DirectX.pEndScene(pDevice);
}


HRESULT WINAPI hkDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
	if (Menu.Fog)
		pDevice->SetRenderState(D3DRS_FOGENABLE, false);

	DWORD * Pointer = (DWORD*)((DWORD)Module.dwRendDx9Base + 0x23B970);
	DWORD Final = (DWORD)((*Pointer) + 0x4F8);
	*(float*)Final = Menu.Distance;

	if (DirectX.mStride == 52 && Menu.Chams)
	{
		if (pLocalPlayer->iTeam == 1)
		{
			if (USMCPlayers1 || USMCPlayers2 || DEBUG_USMC)
			{
				pDevice->SetRenderState(D3DRS_ZENABLE, false);
				pDevice->SetPixelShader(DirectX.ShaderBehind);
				DirectX.pDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
				pDevice->SetRenderState(D3DRS_ZENABLE, true);
				pDevice->SetPixelShader(DirectX.ShaderFront);
			}
		}
		else if (pLocalPlayer->iTeam == 2)
		{
			if (MECPlayers1 || MECPlayers2 || DEBUG_MEC)
			{
				pDevice->SetRenderState(D3DRS_ZENABLE, false);
				pDevice->SetPixelShader(DirectX.ShaderBehind);
				DirectX.pDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
				pDevice->SetRenderState(D3DRS_ZENABLE, true);
				pDevice->SetPixelShader(DirectX.ShaderFront);
			}
		}
	}

	if (DirectX.mStride == 32)
	{
		if (SkyDE && Menu.Sky)
			pDevice->SetPixelShader(DirectX.ShaderBlack);
	}


	if (DirectX.mStride == 24)
	{
		if (Explo && Menu.Explosive)
		{
			pDevice->SetRenderState(D3DRS_ZENABLE, false);
			pDevice->SetPixelShader(DirectX.ShaderExplosive);
			DirectX.pDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			pDevice->SetRenderState(D3DRS_ZENABLE, true);
			pDevice->SetPixelShader(DirectX.ShaderExplosive);
		}
	}


	return DirectX.pDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

HRESULT WINAPI hkReset(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	DirectX.Font->OnLostDevice();
	DirectX.Line->OnLostDevice();

	int ReturnValue = DirectX.pReset(pDevice, pPresentationParameters);

	DirectX.Font->OnResetDevice();
	DirectX.Line->OnResetDevice();

	return ReturnValue;
}

HRESULT WINAPI hkSetStreamSource(LPDIRECT3DDEVICE9 pDevice, UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride)
{
	if (StreamNumber == 0)
		DirectX.mStride = Stride;

	return DirectX.pSetStreamSource(pDevice, StreamNumber, pStreamData, OffsetInBytes, Stride);
}

void GetCenter(LPDIRECT3DDEVICE9 pDevice)
{
	pDevice->GetViewport(&DirectX.Viewport);
	DirectX.CenterX = DirectX.Viewport.Width / 2;
	DirectX.CenterY = DirectX.Viewport.Height / 2;
}

HDC __stdcall hkGetDC(HWND hWnd)
{
	return NULL; //still working on bf2 :)
}

void UpgradeShader(LPDIRECT3DDEVICE9 pDevice)
{
	Draw.CreateShader(&DirectX.ShaderFront, pDevice, Menu.RedF, Menu.GreenF, Menu.BlueF, 1.0f);
	Draw.CreateShader(&DirectX.ShaderBehind, pDevice, Menu.RedB, Menu.GreenB, Menu.BlueB, 1.0f);
}
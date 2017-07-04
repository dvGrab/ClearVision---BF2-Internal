#ifndef DIRECTX_H
#define DIRECTX_H

#include "Main.h"

typedef HRESULT(WINAPI * tEndScene)(LPDIRECT3DDEVICE9 pDevice);
HRESULT WINAPI hkEndScene(LPDIRECT3DDEVICE9 pDevice);

typedef HRESULT(WINAPI * tDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount);
HRESULT WINAPI hkDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount);

typedef HRESULT(WINAPI * tReset)(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
HRESULT WINAPI hkReset(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);

typedef HRESULT(WINAPI * tSetStreamSource)(LPDIRECT3DDEVICE9 pDevice, UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride);
HRESULT WINAPI hkSetStreamSource(LPDIRECT3DDEVICE9 pDevice, UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride);

typedef HDC(__stdcall * tGetDC)(HWND hWnd);
HDC __stdcall hkGetDC(HWND hWnd);

void GetCenter(LPDIRECT3DDEVICE9 pDevice);
void UpgradeShader(LPDIRECT3DDEVICE9 pDevice);

struct directx_s
{
	bool Visuals = true;

	ID3DXLine * Line = NULL;
	ID3DXFont * Font = NULL;

	bool Includes = false;

	LPDIRECT3DDEVICE9 Device;

	tEndScene pEndScene;
	tDrawIndexedPrimitive pDrawIndexedPrimitive;
	tReset pReset;
	tSetStreamSource pSetStreamSource;
	tGetDC pGetDC;

	D3DVIEWPORT9 Viewport;
	int CenterX, CenterY;
	UINT mStride;

	IDirect3DPixelShader9 * ShaderFront;
	IDirect3DPixelShader9 * ShaderBehind;
	IDirect3DPixelShader9 * ShaderBlack;
	IDirect3DPixelShader9 * ShaderExplosive;
};
extern directx_s DirectX;

#endif //DIRECTX_H

#include "Main.h"

module_s Module;
CClassManager * pClassMgr;

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Initialization, 0, 0, 0);
		break;
	}
	return true;
}

DWORD Initialization(LPVOID)
{
	OpenDevConsole();

	while (!Module.dwRendDx9Base)
		Module.dwRendDx9Base = GetModuleHandle("RendDx9.dll");

	Module.dwClassMgrAddr = (DWORD)Module.dwRendDx9Base + 0x744B7;

	pClassMgr = *(CClassManager**)(*(DWORD*)Module.dwClassMgrAddr);
	Hacks.GetClassPointers();

	if (!Module.pDevice)
	{
		Module.pDevice = (LPDIRECT3DDEVICE9)pRenderer->pDirect3Ddev;
		Hooks();
	}

	while (true)
	{
		Sleep(1000);
		Hacks.GetClassPointers();
	}

	return false;
}

void OpenDevConsole(void)
{
	if (AllocConsole())
	{
		freopen("CONOUT$", "w", stdout);
	}
}

void Hooks(void)
{
	DWORD dwPunkbuster = 0;
	DWORD dwAddress = 0;

	Module.GameDevice = (DWORD*)Module.pDevice;
	Module.GameDevice = (DWORD*)Module.GameDevice[0];

	DirectX.pEndScene = (tEndScene)DetourFunction((PBYTE)Module.GameDevice[42], (PBYTE)hkEndScene);
	DirectX.pDrawIndexedPrimitive = (tDrawIndexedPrimitive)DetourFunction((PBYTE)Module.GameDevice[82], (PBYTE)hkDrawIndexedPrimitive);
	DirectX.pReset = (tReset)DetourFunction((PBYTE)Module.GameDevice[16], (PBYTE)hkReset);
	DirectX.pSetStreamSource = (tSetStreamSource)DetourFunction((PBYTE)Module.GameDevice[100], (PBYTE)hkSetStreamSource);

	printf_s("EndScene: 0x%X\n\n", reinterpret_cast<unsigned int>(DirectX.pEndScene));
	printf_s("DrawIndexedPrimitive: 0x%X\n\n", reinterpret_cast<unsigned int>(DirectX.pDrawIndexedPrimitive));
	printf_s("Reset: 0x%X\n\n", reinterpret_cast<unsigned int>(DirectX.pReset));
	printf_s("SetStreamSource: 0x%X\n\n", reinterpret_cast<unsigned int>(DirectX.pSetStreamSource));


	while (!dwPunkbuster)
		dwPunkbuster = (DWORD)GetModuleHandle("pbcl.dll");

	DirectX.pGetDC = (tGetDC)DetourFunction((PBYTE)GetDC, (PBYTE)&hkGetDC);
	printf_s("GetDC: 0x%X\n\n", reinterpret_cast<unsigned int>(DirectX.pGetDC));
}
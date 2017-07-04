#ifndef HMAIN_H
#define HMAIN_H

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4099)
#pragma warning(disable:4244)

#include <Windows.h>
#include <stdio.h>
#include <string>
#include <d3d9.h>
#include <d3dx9.h>
#include <detours.h>

#include "Function.h"
#include "Read.h"
#include "Classes.h"
#include "DirectX.h"
#include "Drawings.h"
#include "Menu.h"
#include "ESP.h"

#pragma once
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "detours.lib")

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved);
DWORD Initialization(LPVOID);
void OpenDevConsole(void);
bool FindClassMgr(void);
void Hooks(void);

struct module_s
{
	HMODULE dwRendDx9Base	= NULL;
	DWORD	dwInitDllBase	= NULL;

	DWORD	dwClassMgrAddr	= NULL;
	DWORD   dwClassMgrPtr	= NULL;

	LPDIRECT3DDEVICE9 pDevice;
	DWORD * GameDevice		= NULL;
};
extern module_s Module;

#endif // HMAIN_H
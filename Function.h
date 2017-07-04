#ifndef HFUNCTION_H
#define HFUNCTION_H

#include "Main.h"

struct function_s
{
	DWORD FindPattern(DWORD base, DWORD size, char pattern[], char mask[]);
	D3DXVECTOR3* WorldToScreen(D3DXVECTOR3* out, D3DXVECTOR3* TargetPos);
};
extern function_s Function;

#endif //HFUNCTION_H
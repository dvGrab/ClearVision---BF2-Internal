#include "Function.h"

function_s Function;

DWORD function_s::FindPattern(DWORD base, DWORD size, char pattern[], char mask[])
{
	for (DWORD retAddress = base; retAddress < (base + size); retAddress++)
	{
		if (*(BYTE*)retAddress == (pattern[0] & 0xff) || mask[0] == '?')
		{
			DWORD startSearch = retAddress;
			for (int i = 0; mask[i] != '\0'; i++, startSearch++)
			{
				if ((pattern[i] & 0xff) != *(BYTE*)startSearch && mask[i] != '?')
					break;

				if (((pattern[i] & 0xff) == *(BYTE*)startSearch || mask[i] == '?') && mask[i + 1] == '\0')
					return retAddress;
			}
		}
	}
	return NULL;
}

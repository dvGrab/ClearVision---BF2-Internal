#include "Read.h"

hack_s Hacks;
CRenderer * pRenderer;
CPlayer * pPlayer;
CPlayerManager * pPlayerManager;
CPlayer * pLocalPlayer;

int hack_s::GetClassPointers(void)
{
	pRenderer = (CRenderer*)pClassMgr->GetClassPtrByName(&std::string("Renderer"));

	pPlayerManager = (CPlayerManager*)pClassMgr->GetClassPtrByName(&std::string("PlayerManager"));

	pLocalPlayer = (CPlayer*)pPlayerManager->LocalPlayer;

	return true;
}
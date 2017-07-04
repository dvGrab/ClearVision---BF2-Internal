#ifndef HCLASSES_H
#define HCLASSES_H

#include "Main.h"

//Credits: xCyniu

class CPlayerManager;
class CPlayer;
class CInfo;
class CObject;
class CHealth;
class CTemplate;
class CPhysics;
class CCamera;
class CSoldierPtr;
class CSoldier;
class CWeapon;
class CDeviation;
class CSkeleton;
class CBone;
class CRenderer;
class CClassManager;
class CTextWriter;
class CGame;
class CObjectManager;
class CRayTest;
class CPhysicsManager;

class CPlayerManager
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual CPlayer* GetPlayerByIndex(int Index); //virtual CPlayer* GetPlayerByIndex(int Index);
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual CPlayer* GetLocalPlayer();//virtual CPlayer* GetLocalPlayer();

	char _0x0004[4];
	CPlayer* ActivePlayer; //0x0008 
	char _0x000C[8];
	DWORD NumberOfPlayers; //0x0014 
	char _0x0018[8];
	DWORD PlayersPerTeam; //0x0020 
	char _0x0024[8];
	DWORD NumberOfPlayers_; //0x002C 
	char _0x0030[32];
	__int32 TotalPlayers; //0x0050 
	char _0x0054[12];
	CPlayer* LocalPlayer; //0x0060 
	char _0x0064[28];

};//Size=0x0080

class CViewMatrix
{
public:
	char unknown0[184];
	float Matrix[16]; //00B8
};



class CPlayer
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual char* GetName(); //virtual char* GetName();
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); // virtual CVehicle* Vehicle();
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual void Function24(); //
	virtual void Function25(); //
	virtual bool Alive();  //virtual bool Alive(); 
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void* GetKit(); //virtual void* GetKit();
	virtual void Function41(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
	virtual void Function48(); //
	virtual void Function49(); //
	virtual void Function50(); //
	virtual void Function51(); //
	virtual void Function52(); //
	virtual void Function53(); //
	virtual void Function54(); //
	virtual int GetTeam(); //virtual int GetTeam();
	virtual void Function56(); //
	virtual void Function57(); //
	virtual void Function58(); //
	virtual void Function59(); //
	virtual void Function60(); //
	virtual void Function61(); //
	virtual void Function62(); //
	virtual void Function63(); //
	virtual int SquadID(); //virtual int SquadID();
	virtual void Function65(); //
	virtual bool IsCommander(); //virtual bool IsCommander();
	virtual void Function67(); //
	virtual void Function68(); //
	virtual void Function69(); //
	virtual void Function70(); //
	virtual void Function71(); //
	virtual void Function72(); //
	virtual void Function73(); //
	virtual void Function74(); //
	virtual void Function75(); //
	virtual void Function76(); //
	virtual void Function77(); //
	virtual void Function78(); //
	virtual void Function79(); //
	virtual void Function80(); //
	virtual void Function81(); //
	virtual void Function82(); //
	virtual void Function83(); //
	virtual void Function84(); //
	virtual void Function85(); //
	virtual int Ping(); //virtual int Ping();
	virtual void Function87(); //
	virtual void Function88(); //
	virtual void Function89(); //
	virtual void Function90(); //
	virtual int FlagHolder(); //virtual int FlagHolder();
	virtual CCamera* GetViewMatrix(); //virtual CCamera* GetViewMatrix();
	virtual void Function93(); //
	virtual void Function94(); //
	virtual CCamera* GetPlayerView(void); //virtual CCamera* GetPlayerView(void);
	virtual void Function96(); //
	virtual void Function97(); //


	char _0x0004[84];
	__int32 Kit; //0x0058 
	char _0x005C[4];
	std::string Name; //0x0060 
	char _0x007C[4];
	CInfo* PlayerObj; //0x0080 
	CCamera* Camera; //0x0084 
	char _0x0088[44];
	__int32 PlayerSeat; //0x00B4 
	__int32 N00327FC0; //0x00B8 wtf?
	char _0x00BC[4];
	float Zoom; //0x00C0   
	float ZoomFinal; //0x00C4 
	char _0x00C8[4];
	CSoldierPtr* SoldierObj; //0x00CC 
	char _0x00D0[5]; //0x00D0 
	BYTE iAlive; //0x00D5 
	char _0x00D6[2];
	__int32 iTeam; //0x00D8 
	char _0x00DC[28];
	DWORD iPing; //0x00F8 
	char _0x00FC[16];
	__int32 Squad_Number; //0x010C 
	BYTE N00327FD7; //0x0110 
	BYTE Squad_Leader; //0x0111 
	char _0x0112[102];
	BYTE InVehicle; //0x0178  1 = OnFoot || 2 = OnVehicle
	char N00F34823[3]; //0x0179 
	char _0x017C[8];
	BYTE N00327FF4; //0x0184 
	BYTE N00390C6D; //0x0185 
	BYTE N0039672D; //0x0186 
	BYTE Sprinting; //0x0187 
	char _0x0188[68];
	__int32 Weapon_Ammo; //0x01CC 
	char _0x01D0[8];
	__int32 Weapon_MaxAmmo; //0x01D8 
	char _0x01DC[8];
	__int32 Weapon_Firemode; //0x01E4 
	char _0x01E8[8];
	__int32 Weapon_Zoomed; //0x01F0 
	char _0x01F4[8];
	__int32 Weapon_Mags; //0x01FC 
	char _0x0200[8];
	__int32 Weapon_Max_Mags; //0x0208 
	char _0x020C[8];
	float Weapon_Heat_Primary; //0x0214 
	char _0x0218[56];
	__int32 Vehicle_Pilot; //0x0250 
	BYTE N003D7618333; //0x0254 
	WORD N003D7618; //0x0255 
	BYTE N003D7619; //0x0257 
	float Weapon_Overheat_Primary; //0x0258 
	float Weapon_Overheat_Secondary; //0x025C 
	
};//Size=0x043C
class CInfo
{
public:
	char _0x0000[4];
	CObject * PlayerPtr; //0x0004 
};//Size=0x003C

class CObject
{
public:
	char _0x0000[4];
	DWORD ObjectFlags; //0x0004 Untested
	char _0x0008[4];
	CObject* Obj_Root; //0x000C 
	char _0x0010[4];
	CTemplate* Obj_Template; //0x0014 
	char _0x0018[36];
	CHealth* Health; //0x003C 
	char _0x0040[4];
	CPhysics* Obj_Physics; //0x0044 
	char _0x0048[64];
	D3DXMATRIX Matrix; //0x0088 
	D3DXMATRIX N01292717; //0x00C8 
	char _0x0108[256];

	D3DXVECTOR3* getViewPosition()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&Matrix.m[3][0]);
	}
	D3DXVECTOR3* getViewRight()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&Matrix.m[0][0]);
	}

	D3DXVECTOR3* getViewUp()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&Matrix.m[1][0]);
	}

	D3DXVECTOR3* getViewDirection()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&Matrix.m[2][0]);
	}

};//Size=0x0208
class CHealth
{
public:
	char _0x0000[16];
	float Health; //0x0010 
	char _0x0014[108];

};//Size=0x0080

class CTemplate
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual int GetTemplateType(void); //virtual int GetTemplateType(void);
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //

	char _0x0004[176];
	float w_gravitymodifier; //0x00B4 
	char _0x00B8[444];
	float N01209E0D; //0x0274 
	float w_velocity; //0x0278 
	char _0x027C[32];
	float w_damage; //0x029C 
	char _0x02A0[188];

};//Size=0x035C

class CPhysics
{
public:
	char _0x0000[108];
	D3DXVECTOR3 Position; //0x006C 
	D3DXVECTOR3 Speed; //0x0078 
	char _0x0084[16];
	D3DXVECTOR3 Rotation; //0x0094 
	char _0x00A0[32];

};//Size=0x00C0

class CCamera
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual float GetInsideFOV(void); //virtual float GetInsideFOV(void);

	char _0x0000[4];
	__int32 IsValid; //0x0004 
	__int32 Perspective; //0x0008 
	char _0x000C[172];
	D3DXMATRIX Matrix; //0x00B8 

	D3DXVECTOR3* getViewPosition()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&Matrix.m[3][0]);
	}
	D3DXVECTOR3* getViewRight()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&Matrix.m[0][0]);
	}

	D3DXVECTOR3* getViewUp()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&Matrix.m[1][0]);
	}

	D3DXVECTOR3* getViewDirection()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&Matrix.m[2][0]);
	}

};//Size=0x0108

class CSoldierPtr
{
public:
	char _0x0000[4];
	CSoldier* Ptr; //0x0004 
	char _0x0008[56];

};//Size=0x0040

class CSoldier
{
public:
	char _0x0000[20];
	CTemplate* Obj_Template; //0x0014 
	char _0x0018[36];
	CHealth* Health; //0x003C 
	char _0x0040[4];
	CPhysics* Obj_Physics; //0x0044
	char _0x0048[64];
	D3DXMATRIX Matrix; //0x0088
	char _0x00C8[240];
	CWeapon* Player_Weapon; //0x01B8 
	char _0x01BC[36];
	__int32 Current_Weapon_Slot; //0x01E0 
	char _0x01E4[64];
	float N01453A9F; //0x0224 
	float N01453AA0; //0x0228 
	float N01453AA1; //0x022C 
	__int32 sPosture; //0x0230 
	__int32 sCurPosture; //0x0234 
	float Head_Pitch; //0x0238 
	float Head_Pitch_Change; //0x023C 
	float Head_Yaw; //0x0240 
	float Head_Yaw_Change; //0x0244 
	char _0x0248[64];
	CSkeleton* Skeleton_1P; //0x0288 
	char _0x028C[4];
	CSkeleton* Skeleton_3P; //0x0290 
	char _0x0294[20];

	D3DXVECTOR3* getViewPosition()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&Matrix.m[3][0]);
	}
	D3DXVECTOR3* getViewRight()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&Matrix.m[0][0]);
	}

	D3DXVECTOR3* getViewUp()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&Matrix.m[1][0]);
	}

	D3DXVECTOR3* getViewDirection()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&Matrix.m[2][0]);
	}
};//Size=0x02A8

class CWeapon
{
public:
	char _0x0000[136];
	D3DXMATRIX w_matrix; //0x0088 
	char _0x00C8[216];
	CDeviation* Weapon_Deviation; //0x01A0 
	char _0x01A4[68];
	CTemplate* Weapon_Template; //0x01E8 
	char _0x01EC[8];

};//Size=0x01F4

class CDeviation
{
public:
	char _0x0000[4];
	float DeviationTotal; //0x0004 
	char _0x0008[48];

};//Size=0x0038

class CSkeleton
{
public:
	char _0x0000[8];
	CBone* Bones; //0x0008 
	char _0x000C[4];
	D3DXMATRIX* matrices;; //0x0010 
	__int32 iTotBones; //0x0014 
	char _0x0018[232];

};//Size=0x0100

class CBone
{
public:
	__int32 Bone_Number; //0x0000 
	__int16 Bone_Code; //0x0004 
	__int16 Bone_Parent; //0x0006 
	char _0x0008[4];
	float Bone_Ofs_x; //0x000C 
	float Bone_Ofs_y; //0x0010 
	float Bone_Ofs_z; //0x0014 
	float Bone_Lenght; //0x0018 
	float Bone_Radius; //0x001C 
	__int32 Bone_Material; //0x0020 
	char _0x0024[28];

};//Size=0x0040

class CPhysicsManager
{
public:
	char _0x0000[8];
	float p_gravity; //0x0008 

};//Size=0x0040

class CRenderer
{
public:
	char _0x0000[8];
	IDirect3D9 * Direct3D_Device; //0x0008 
	IDirect3DDevice9 * pDirect3Ddev; //0x000C  
	char _0x0010[20];
	D3DXVECTOR2 ScreenInfo; //0x0024 
	char _0x002C[1648];
	BYTE N00FA8F34; //0x069C 
	BYTE N01061B57; //0x069D 
	BYTE N01053840; //0x069E 
	BYTE bDrawWater; //0x069F 
	BYTE N00FA8F33; //0x06A0 
	BYTE N01048FDA; //0x06A1 
	BYTE N0104978B; //0x06A2 
	BYTE bShowBodies; //0x06A3 
	BYTE N00FA8F32; //0x06A4 
	BYTE bShowGround; //0x06A5 
	BYTE bShowGrass; //0x06A6 
	BYTE bShowThrees; //0x06A7 
	BYTE bShowFriendlyTags; //0x06A8 Nametags
	BYTE N00FBAEB4; //0x06A9 
	BYTE N00FC0334; //0x06AA 
	BYTE N00FBAEB5; //0x06AB 
	__int32 DrawFps; //0x06AC 
	BYTE N00DCC523; //0x06B0 
	BYTE bShowHud; //0x06B1 
	BYTE bDrawSky; //0x06B2 
	BYTE bDrawSunFlare; //0x06B3 
	BYTE bDrawConsole; //0x06B4 
};//Size=0x06B5

class CClassManager
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual int GetClassPtrByName(std::string* szClassname); //
};//Size=0x004C(76)

const D3DCOLOR TextOutline = D3DCOLOR_RGBA(0, 0, 0, 200);

class CTextWriter
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void DrawText(int x, int y, DWORD txColor, char* Text, BOOL SomeWtfParm = 0);

	void ShadowedText(int x, int y, DWORD txColor, char* Text)
	{
		DrawText(x - 1, y, TextOutline, Text);
		DrawText(x + 1, y, TextOutline, Text);
		DrawText(x, y - 1, TextOutline, Text);
		DrawText(x, y + 1, TextOutline, Text);
		DrawText(x, y, txColor, Text);
	}
};

class CSpreadTable
{
public:
	float table[1024]; //0x0000  
};//Size=0x0400(1024) 

class CGame
{
public:
	virtual void function0(); //
	virtual void function1(); //
	virtual void function2(); //
	virtual void function3(); //
	virtual void function4(); //
	virtual void function5(); //
	virtual void function6(); //
	virtual void function7(); //
	virtual void function8(); //
	virtual void function9(); //
	virtual void function10(); //
	virtual void function11(); //
	virtual void function12(); //
	virtual void function13(); //
	virtual void function14(); //
	virtual void function15(); //
	virtual void function16(); //
	virtual void function17(); //
	virtual void function18(); //
	virtual void function19(); //
	virtual void function20(); //
	virtual void function21(); //
	virtual void function22(); //
	virtual void function23(); //
	virtual void function24(); //
	virtual void function25(); //
	virtual int getCounter(void); //
	virtual void function27(); //
	virtual void function28(); //
	virtual void function29(); //
	virtual void function30(); //
	virtual void function31(); //
	virtual void function32(); //
	virtual void function33(); //
	virtual void function34(); //
	virtual void function35(); //
	virtual void function36(); //
	virtual void function37(); //
	virtual void function38(); //
	virtual void function39(); //
	virtual void function40(); //
	virtual void function41(); //
	virtual void function42(); //
	virtual void function43(); //
	virtual void function44(); //
	virtual void function45(); //
	virtual void function46(); //
	virtual void function47(); //
	virtual void function48(); //
	virtual void function49(); //
	virtual void function50(); //
	virtual void function51(); //
	virtual void function52(); //
	virtual void function53(); //
	virtual void function54(); //
	virtual void function55(); //
	virtual void function56(); //
	virtual void function57(); //
	virtual void function58(); //
	virtual void function59(); //
	virtual void function60(); //
	virtual char* getMapName(void); //
	virtual char* getGameMode(void); //
};//Size=0x0004(4) 

class CActionBuffer
{
public:
	float InputFlags[64]; //0x0000  
};//Size=0x0040(64)

class CInputManager
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual CActionBuffer* GetNextActionBuffer();
	virtual CActionBuffer* GetCurrentActionBuffer();
};

class CObjectManager
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual BYTE Intersect(CObject** inter_obj, D3DXVECTOR3* inter_point, D3DXVECTOR3* inter_angle, int* inter_mat, D3DXVECTOR3* ray_start, D3DXVECTOR3* ray_end, CRayTest* ray, BOOL unk1, BOOL unk2, BOOL unk3, BOOL unk4, BOOL unk5 = FALSE);
};

extern CClassManager * pClassMgr;
extern CRenderer * pRenderer;
extern CPlayer * pLocalPlayer;
extern CPlayerManager * pPlayerManager;

#endif //HCLASSES_H
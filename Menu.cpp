#include "Menu.h"


void CMenu::Paint(void)
{
	Control();
	char Temp[256];


	Draw.FilledBox(50, 70, 210, 27, 220, 70, 90, 200, 200, 200, 180);
	Draw.FilledBox(50, 100, 210, 250, 220, 70, 90, 200, 200, 200, 180);
	Draw.String("Arcane Cheats - Menu", 75, 75, 255, 255, 255);

	Draw.FilledBox(52, 102 + (15 * Count), 206, 20, 255, 100, 100, 0, 0, 0, 100);

	if(Fog)
		Draw.String(" Disable Fog", 65, 105, 0, 255, 0);
	else
		Draw.String(" Disable Fog", 65, 105, 255, 0, 0);

	if (Chams)
		Draw.String(" Colored Playermodels", 65, 120, 0, 255, 0);
	else
		Draw.String(" Colored Playermodels", 65, 120, 255, 0, 0);

	if (Distance >= 1.1f)
	{
		char Temp[256];
		sprintf_s(Temp, " Viewdistance (%.2fm)", Distance);
		Draw.String(Temp, 65, 135, 0, 255, 0);
	}
	else if (Distance <= 1.1f)
	{
		char Temp[256];
		sprintf_s(Temp, " Viewdistance (%.2fm)", Distance);
		Draw.String(Temp, 65, 135, 255, 0, 0);
	}

	if (Crosshair)
		Draw.String(" Crosshair", 65, 150, 0, 255, 0);
	else
		Draw.String(" Crosshair", 65, 150, 255, 0, 0);
		
	if (Sky)
		Draw.String(" Black Sky", 65, 165, 0, 255, 0);
	else
		Draw.String(" Black Sky", 65, 165, 255, 0, 0);

	if (ShowESP)
		Draw.String("  ", 65, 180, 0, 255, 0);
	else
		Draw.String("  ", 65, 180, 255, 0, 0);
	
	sprintf_s(Temp, " Chams Behind - RED (%.3f)", RedB);
	Draw.String(Temp, 65, 195, 255, 255, 255);

	sprintf_s(Temp, " Chams Behind - GREEN (%.3f)", GreenB);
	Draw.String(Temp, 65, 210, 255, 255, 255);

	sprintf_s(Temp, " Chams Behind - BLUE (%.3f)", BlueB);
	Draw.String(Temp, 65, 225, 255, 255, 255);

	Draw.FilledBox(270, 200, 40, 40, RedB * 255, GreenB * 255, BlueB * 255, 0, 0, 0, 255);


	sprintf_s(Temp, " Chams Front - RED (%.3f)", RedF);
	Draw.String(Temp, 65, 255, 255, 255, 255);

	sprintf_s(Temp, " Chams Front - GREEN (%.3f)", GreenF);
	Draw.String(Temp, 65, 270, 255, 255, 255);

	sprintf_s(Temp, " Chams Front - BLUE (%.3f)", BlueF);
	Draw.String(Temp, 65, 285, 255, 255, 255);

	Draw.FilledBox(270, 260, 40, 40, RedF * 255, GreenF * 255, BlueF * 255, 0, 0, 0, 255);

	if (Explosive)
		Draw.String(" Colored Explosive", 65, 315, 0, 255, 0);
	else
		Draw.String(" Colored Explosive", 65, 315, 255, 0, 0);
}

void CMenu::Control(void)
{
	if (GetAsyncKeyState(VK_DOWN) & 1 && Count <= Items)
		Count++;

	if (GetAsyncKeyState(VK_UP) & 1 && Count >= 1)
		Count--;

	if (GetAsyncKeyState(VK_RIGHT) & 1)
	{
		switch (Count)
		{
		case 0:
			Fog = true;
			break;
		case 1:
			Chams = true;
			break;
		case 2:
			if(Distance <= 10.0f) Distance += 0.1f;
			break;
		case 3:
			Crosshair = true;
			break;
		case 4:
			Sky = true;
			break;  
		case 5:
			ShowESP = true;
			break;
		case 6:
			if (RedB <= 0.990f) RedB += 0.01f;
			UpgradeShader(DirectX.Device);
			break;
		case 7:
			if (GreenB <= 0.990f) GreenB += 0.01f;
			UpgradeShader(DirectX.Device);
			break;
		case 8:
			if (BlueB <= 0.990f) BlueB += 0.01f;
			UpgradeShader(DirectX.Device);
			break;
		case 9:
			break;
		case 10:
			if (RedF <= 0.990f) RedF += 0.01f;
			UpgradeShader(DirectX.Device);
			break;
		case 11:
			if (GreenF <= 0.990f) GreenF += 0.01f;
			UpgradeShader(DirectX.Device);
			break;
		case 12:
			if (BlueF <= 0.990f) BlueF += 0.01f;
			UpgradeShader(DirectX.Device);
			break;
		case 13: 
			break;
		case 14:
			Explosive = true;
			break;
		}
	}


	if (GetAsyncKeyState(VK_LEFT) & 1)
	{
		switch (Count)
		{
		case 0:
			Fog = false;
			break;
		case 1:
			Chams = false;
			break;
		case 2:
			if (Distance >= 1.1f) Distance -= 0.1f;
			break;
		case 3:
			Crosshair = false;
			break;
		case 4:
			Sky = false;
			break;
		case 5:
			ShowESP = false;
			break;
		case 6:
			if (RedB >= 0.010f) RedB -= 0.01f;
			UpgradeShader(DirectX.Device);
			break;
		case 7:
			if (GreenB >= 0.010f) GreenB -= 0.01f;
			UpgradeShader(DirectX.Device);
			break;
		case 8:
			if (BlueB >= 0.010f) BlueB -= 0.01f;
			UpgradeShader(DirectX.Device);
			break;
		case 9:
			break;
		case 10:
			if (RedF >= 0.010f) RedF -= 0.01f;
			UpgradeShader(DirectX.Device);
			break;
		case 11:
			if (GreenF >= 0.010f) GreenF -= 0.01f;
			UpgradeShader(DirectX.Device);
			break;
		case 12:
			if (BlueF >= 0.010f) BlueF -= 0.01f;
			UpgradeShader(DirectX.Device);
			break;
		case 13:
			break;
		case 14: 
			Explosive = false;
		}
	}
}

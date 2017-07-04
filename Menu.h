#ifndef MENU_H
#define MENU_H

#include "Main.h"

class CMenu
{
public:
	void Paint(void);
	void Control(void); 

	int Items = 15;
	int Count = 0;
	bool Visible = false;
	bool Fog = false;
	bool Chams = false;
	float Distance = 1.0f;
	bool Crosshair = false;
	bool Sky = false;
	bool ShowESP = false;

	float RedB = 1.0f;
	float GreenB = 0.0f;
	float BlueB = 0.0f;

	float RedF = 1.0f;
	float GreenF = 1.0f;
	float BlueF = 0.0f;

	bool Explosive = false;
};

#endif
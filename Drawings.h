#ifndef DRAWINGS_H
#define DRAWINGS_H

#include "Main.h"

struct draw_s
{
	RECT Position;

	void String(char * text, int x, int y, int r, int g, int b);
	void Box(int x, int y, int width, int height, int r, int g, int b, int a);
	void FilledBox(int x, int y, int width, int height, int r, int g, int b, int outr, int outg, int outb, int a);
	HRESULT CreateShader(IDirect3DPixelShader9 **pShader, IDirect3DDevice9 *Device, float red, float green, float blue, float alpha);
};
extern draw_s Draw;

#endif //DRAWINGS_H
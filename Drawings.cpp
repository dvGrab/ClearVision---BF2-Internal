#include "Drawings.h"

draw_s Draw;

void draw_s::String(char * text, int x, int y, int r, int g, int b)
{
	Position.left = x + 1;
	Position.top = y + 1;
	DirectX.Font->DrawTextA(0, text, strlen(text), &Position, DT_NOCLIP, D3DCOLOR_RGBA(r / 10, g / 10, b / 10, 255));

	Position.left = x;
	Position.top = y;
	DirectX.Font->DrawTextA(0, text, strlen(text), &Position, DT_NOCLIP, D3DCOLOR_RGBA(r, g, b, 255));
}

//s0beit? or ROVER?
HRESULT draw_s::CreateShader(IDirect3DPixelShader9 **pShader, IDirect3DDevice9 *Device, float red, float green, float blue, float alpha)
{
	const char *format = "ps.1.1\ndef c0, %f, %f, %f, %f\nmov r0,c0";
	char buffer[100];
	sprintf(buffer, format, red, green, blue, alpha);
	LPD3DXBUFFER pCode = NULL;
	LPD3DXBUFFER pErrorMsgs = NULL;

	D3DXAssembleShader(buffer, strlen(buffer), NULL, NULL, NULL, &pCode, &pErrorMsgs);
	Device->CreatePixelShader((DWORD *)pCode->GetBufferPointer(), pShader);

	return S_OK;
}

void draw_s::Box(int x, int y, int width, int height, int r, int g, int b, int a)
{
	D3DXVECTOR2 Corner[5];
	Corner[0] = D3DXVECTOR2(x, y);
	Corner[1] = D3DXVECTOR2(x + width, y);
	Corner[2] = D3DXVECTOR2(x + width, y + height);
	Corner[3] = D3DXVECTOR2(x, y + height);
	Corner[4] = D3DXVECTOR2(x, y);

	DirectX.Line->SetWidth(1);
	DirectX.Line->SetAntialias(false);

	DirectX.Line->Draw(Corner, 5, D3DCOLOR_ARGB(a, g, b, b));
}

void draw_s::FilledBox(int x, int y, int width, int height, int r, int g, int b, int outr, int outg, int outb, int a)
{
	D3DXVECTOR2 Corner[5];

	Corner[0] = D3DXVECTOR2(x + width / 2, y);
	Corner[1] = D3DXVECTOR2(x + width / 2, y + height);

	DirectX.Line->SetWidth(width);
	DirectX.Line->SetAntialias(false);
	DirectX.Line->Draw(Corner, 2, D3DCOLOR_ARGB(a, r, g, b));

	Corner[0] = D3DXVECTOR2(x, y);
	Corner[1] = D3DXVECTOR2(x + width, y);
	Corner[2] = D3DXVECTOR2(x + width, y + height);
	Corner[3] = D3DXVECTOR2(x, y + height);
	Corner[4] = D3DXVECTOR2(x, y);

	DirectX.Line->SetWidth(1);
	DirectX.Line->SetAntialias(false);
	DirectX.Line->Draw(Corner, 5, D3DCOLOR_ARGB(a, outr, outg, outb));

}

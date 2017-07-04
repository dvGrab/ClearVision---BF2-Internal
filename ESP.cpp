#include "ESP.h"

#define GET_XAXIS_FROMMATRIX( out_vector, pMatrix) { D3DXVec3Normalize( out_vector, &D3DXVECTOR3((pMatrix)->_11,(pMatrix)->_12,(pMatrix)->_13)); } 
#define GET_YAXIS_FROMMATRIX( out_vector, pMatrix) { D3DXVec3Normalize( out_vector, &D3DXVECTOR3((pMatrix)->_21,(pMatrix)->_22,(pMatrix)->_23)); } 
#define GET_ZAXIS_FROMMATRIX( out_vector, pMatrix) { D3DXVec3Normalize( out_vector, &D3DXVECTOR3(((pMatrix))->_31,(pMatrix)->_32,(pMatrix)->_33)); } 
#define GET_ORIGIN_FROMMATRIX( out_vector, pMatrix){ (out_vector)->x = (pMatrix)->_41; (out_vector)->y = (pMatrix)->_42; (out_vector)->z = (pMatrix)->_43; } 

D3DXMATRIX* PlayerViewMatrix;

bool World2Screen(D3DXVECTOR3 vWorldLocation, float fScreenX, float fScreenY)
{
	UINT iCenterX = DirectX.Viewport.X / 2;
	UINT iCenterY = DirectX.Viewport.Y / 2;

	D3DXVECTOR3 vLocal, vTransForm;
	D3DXVECTOR3 vright, vup, vfwd, vorig;

	GET_ORIGIN_FROMMATRIX(&vorig, PlayerViewMatrix);
	GET_XAXIS_FROMMATRIX(&vright, PlayerViewMatrix);
	GET_YAXIS_FROMMATRIX(&vup, PlayerViewMatrix);
	GET_ZAXIS_FROMMATRIX(&vfwd, PlayerViewMatrix);

	D3DXVec3Subtract(&vLocal, &vWorldLocation, &vorig);

	vTransForm[0] = D3DXVec3Dot(&vLocal, &vright);
	vTransForm[1] = D3DXVec3Dot(&vLocal, &vup);
	vTransForm[2] = D3DXVec3Dot(&vLocal, &vfwd);

	if (vTransForm.z < 0.01)
	{
		return 0;
	}

	if (fScreenX && fScreenY)
	{
		float LocalFOV = pPlayerManager->LocalPlayer->Zoom;
		float FOVx10 = LocalFOV * 10;

		fScreenX = iCenterX / vTransForm[2] * ((1.333f + (0.3f / (LocalFOV * 10))) / LocalFOV);
		fScreenY = iCenterY / vTransForm[2] * ((1.333f + (0.3f / (LocalFOV * 10))) / (LocalFOV / 1.333f));

		vWorldLocation.x = iCenterX + fScreenX * vTransForm[0];
		vWorldLocation.y = iCenterY - fScreenY * vTransForm[1];
		vWorldLocation.z = vTransForm[2];
	}

	return  vTransForm.z > 0;
}
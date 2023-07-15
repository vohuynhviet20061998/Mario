#include "map.h"

void CMap::Render()
{
	CSprites* s = CSprites::GetInstance();

	s->Get(this->spriteIdBegin)->Draw(x, y);
	
	RenderBoundingBox();
}

void CMap::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	
}
void CMap::RenderBoundingBox()
{
	D3DXVECTOR3 p(x, y, 0);
	RECT rect;

	LPTEXTURE bbox = CTextures::GetInstance()->Get(ID_TEX_BBOX);

	float l, t, r, b;

	GetBoundingBox(l, t, r, b);
	rect.left = l;
	rect.top = t;
	rect.right = (int)r - (int)l;
	rect.bottom = (int)b - (int)t;

	float cx, cy;
	CGame::GetInstance()->GetCamPos(cx, cy);



	CGame::GetInstance()->Draw(x - cy, y - cy, bbox, nullptr, BBOX_ALPHA, rect.right - 1, rect.bottom - 1);
}

void CMap::Release()
{
}

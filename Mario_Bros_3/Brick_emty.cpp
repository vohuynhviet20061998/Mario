#include "Brick_emty.h"

void CBrick_Emty::Render()
{
	CSprites* s = CSprites::GetInstance();

	s->Get(this->spriteId)->Draw(x, y);
	RenderBoundingBox();
}

void CBrick_Emty::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - Brick_Emty_BBOX_WIDTH / 2;
	t = y - Brick_Emty_BBOX_HEIGHT / 2;
	r = l + Brick_Emty_BBOX_WIDTH;
	b = t + Brick_Emty_BBOX_HEIGHT;
}
void CBrick_Emty::Release()
{
}

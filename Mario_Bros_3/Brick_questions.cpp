#include "Brick_questions.h"


void CBrick_Questions::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (object == BRICK_OBJECT_QUESTION) {
	animations->Get(ID_ANI_Brick_Questions)->Render(x, y);
	}
	else if (object == BRICK_OBJECT_TREE) {
		animations->Get(ID_ANI_Brick_Tree)->Render(x, y);
		RenderBoundingBox();
	}
}

void CBrick_Questions::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
}

void CBrick_Questions::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - Brick_Questions_BBOX_WIDTH / 2;
	t = y - Brick_Questions_BBOX_HEIGHT / 2;
	r = l + Brick_Questions_BBOX_WIDTH;
	b = t + Brick_Questions_BBOX_HEIGHT;
}
void CBrick_Questions::Release()
{
}

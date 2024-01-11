#include "Brick_questions.h"


void CBrick_Questions::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = ID_ANI_Brick_Questions;
	if (state == QUESTIONBRICK_STATE_DISABLE) {
		aniId = ID_ANI_Brick_normal;
	}
	animations->Get(aniId)->Render(x, y);
}

void CBrick_Questions::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

	if (GetState() == QUESTIONBRICK_STATE_DISABLE) {
		if (throwup_start == 0) {
			StartThrowup();
		}
		else if (GetTickCount64() - throwup_start > 0) {
			if (y < start_y)
				y++;
			else
				y = start_y;
		}
	}

	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CBrick_Questions::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - Brick_Questions_BBOX_WIDTH / 2;
	t = y - Brick_Questions_BBOX_HEIGHT / 2;
	r = l + Brick_Questions_BBOX_WIDTH;
	b = t + Brick_Questions_BBOX_HEIGHT;
}
void CBrick_Questions::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case QUESTIONBRICK_STATE_DISABLE:
		vx = 0;
		vy = 0;
		y = y - QUESTIONBRICK_JUMP_Y;
		break;
	}
}
void CBrick_Questions::Release()
{
}

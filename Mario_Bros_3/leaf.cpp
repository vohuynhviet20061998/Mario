#include "leaf.h"
#include "Brick.h"


void Cleaf::Render()
{
	CSprites* s = CSprites::GetInstance();

	s->Get(this->spriteId)->Draw(x, y);

	RenderBoundingBox();
}

void Cleaf::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{


	if (GetTickCount64() - time_jump < TIME_JUMP) {
		this->vy += ay * dt;
	}
	else if ((GetTickCount64() - time_jump >= TIME_JUMP) && (GetTickCount64() - time_jump <= TIME_JUMP * 2)) {
		SetState(leaf_STATE_WALK);
	}
	else if (GetTickCount64() - time_jump > TIME_JUMP * 2) {
		if (this->state == leaf_STATE_WALK) {
			this->vy = leaf_JUMP_DEFLECT_Y;
			this->vx = leaf_WALK_X;
		}

	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);


}



void Cleaf::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};


void Cleaf::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - leaf_BBOX_WIDTH / 2;
	t = y - leaf_BBOX_HEIGHT / 2;
	r = l + leaf_BBOX_WIDTH;
	b = t + leaf_BBOX_HEIGHT;
}

void Cleaf::SetState(int state)
{
	switch (state)
	{
	case leaf_STATE_IDLE:
		this->vy = 0;
		this->ay = 0;
		break;
	case leaf_STATE_JUMP:
		this->vy = -leaf_JUMP_Y;
		time_jump = GetTickCount64();
		break;
	case leaf_STATE_WALK:
		this->vy = leaf_JUMP_DEFLECT_Y;
		this->vx = 0;
		break;
	}
}

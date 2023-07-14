#include "fireBall.h"

void fireBall::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_FIREBALL)->Render(x, y);

	RenderBoundingBox();
}

void fireBall::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void fireBall::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};
void fireBall::OnCollisionWith(LPCOLLISIONEVENT e)
{


	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		this->Delete();
	}
}


void fireBall::SetState(int state)
{
	switch (state) {
	case FIREBALL_LEFT:
		maxVx = -FIREBALL_SPEED;
		nx = -1;
		break;
	case FIREBALL_RIGHT:
		maxVx = FIREBALL_SPEED;
		nx = 1;
		break;

	}
}

void fireBall::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - FIREBALL_WIDTH / 2;
	top = y - FIREBALL_HEIGHT/ 2;
	right = left + FIREBALL_WIDTH;
	bottom = top + FIREBALL_HEIGHT;
}



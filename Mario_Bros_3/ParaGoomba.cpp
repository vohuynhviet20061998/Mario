#include "ParaGoomba.h"

CParaGoomba::CParaGoomba(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	vx = PARAGOOMBA_WALKING_SPEED;
	this->ay = PARAGOOMBA_GRAVITY;
	isOnPlatform = false;
	level = PARAGOOMBA_LEVEL_WING;
	die_start = -1;

}

void CParaGoomba::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == PARAGOOMBA_STATE_DIE)
	{
		left = x - PARAGOOMBA_BBOX_WIDTH / 2;
		top = y - PARAGOOMBA_BBOX_HEIGHT_DIE / 2;
		right = left + PARAGOOMBA_BBOX_WIDTH;
		bottom = top + PARAGOOMBA_BBOX_HEIGHT_DIE;
	}
	else
	{
		left = x - PARAGOOMBA_BBOX_WIDTH / 2;
		top = y - PARAGOOMBA_BBOX_HEIGHT / 2;
		right = left + PARAGOOMBA_BBOX_WIDTH;
		bottom = top + PARAGOOMBA_BBOX_HEIGHT;
	}
}

void CParaGoomba::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CParaGoomba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CParaGoomba*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
		if (e->ny < 0) {
			isOnPlatform = true;
		}
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}

}


void CParaGoomba::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;
	if (level == PARAGOOMBA_LEVEL_WING) {
		if (isOnPlatform == true ) {
			SetState(PARAGOOMBA_STATE_FLY);
		}
	}
	if ((state == PARAGOOMBA_STATE_DIE) && (GetTickCount64() - die_start > PARAGOOMBA_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}


	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CParaGoomba::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

	if (level == PARAGOOMBA_LEVEL_WING) {
		if (isOnPlatform == true) {
			aniId = ID_ANI_PARAGOOMBA_WALK_FLY;
		}
		else
			aniId = ID_ANI_PARAGOOMBA_FLY;
	}
	else if (level == PARAGOOMBA_LEVEL_NO_WING) {
		if (state == PARAGOOMBA_STATE_DIE)
			aniId = ID_ANI_PARAGOOMBA_DIE;
		else
			aniId = ID_ANI_PARAGOOMBA_NORMAL;
	}


	animations->Get(aniId)->Render(x, y);

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CParaGoomba::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case PARAGOOMBA_STATE_DIE:
		die_start = GetTickCount64();
		y += (PARAGOOMBA_BBOX_HEIGHT - PARAGOOMBA_BBOX_HEIGHT_DIE) / 2;
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	case PARAGOOMBA_STATE_FLY:

		vy = -PARAGOOMBA_JUMP_LOW_SPEED;
		break;
	}
}
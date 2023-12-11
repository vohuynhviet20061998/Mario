#include "ParaGoomba.h"

CParaGoomba::CParaGoomba(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	vx = PARAGOOMBA_WALKING_SPEED;
	this->ay = PARAGOOMBA_GRAVITY;
	jumpTime = PARAGOOMBA_FLY_TIMES;
	isOnPlatform = false;
	level = PARAGOOMBA_LEVEL_WALK_FLY;
	isCollision = true;
	start_y = y;
	start_x = x;
}

void CParaGoomba::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
		left = x - PARAGOOMBA_BBOX_WIDTH / 2;
		top = y - PARAGOOMBA_BBOX_HEIGHT / 2;
		right = left + PARAGOOMBA_BBOX_WIDTH;
		bottom = top + PARAGOOMBA_BBOX_HEIGHT;
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
	if (level == PARAGOOMBA_LEVEL_WALK_FLY) {
		if (isOnPlatform == true && jumpTime > 0) {
			SetState(PARAGOOMBA_STATE_FLY);
		}
		if (GetTickCount64() - walkingTime > PARAGOOMBA_WALK_TIME && walkingTime > 0) {
			walkingTime = 0;
			jumpTime = PARAGOOMBA_FLY_TIMES;
		}
	}


	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CParaGoomba::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

	if (level == PARAGOOMBA_LEVEL_WALK_FLY) {
		if (isOnPlatform == true) {
			aniId = ID_ANI_PARAGOOMBA_WALK_FLY;
		}
		else
			aniId = ID_ANI_PARAGOOMBA_FLY;
	}
	else if (level == PARAGOOMBA_LEVEL_NO_WALK_FLY) {
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
	case PARAGOOMBA_STATE_FLY:
		jumpTime--;
		isOnPlatform = false;
		if (jumpTime == 0) {
			vy = -PARAGOOMBA_JUMP_HIGH_SPEED;
			vx = -PARAGOOMBA_WALKING_SPEED;
			StartWalkingTime();
		}
		else
		{
			vy = -PARAGOOMBA_JUMP_LOW_SPEED;
		}
		break;
	case PARAGOOMBA_STATE_KICK_BY_RACCOON:
		vy = -PARAGOOMBA_KICK_BY_RACCOON_SPEED;
		break;
	case PARAGOOMBA_STATE_KICK_BY_KOOPA:
		vy = -PARAGOOMBA_KICK_BY_KOOPA_SPEED;
		break;
	}
}
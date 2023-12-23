#include "leaf.h"
#include "Brick.h"
#include "Koopas.h"
#include "Goomba.h"
#include "ParaGoomba.h"


void Cleaf::Render()
{
	int aniId = -1;
	if (nx > 0)
		aniId = ID_ANI_LEAF_RIGHT;
	else
		aniId = ID_ANI_LEAF_LEFT;
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void Cleaf::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	isCollidable = true;
	vy += ay * dt;
	x += vx * dt;

	if (nx == -1) {
		if (GetTickCount64() - direct_time > DIRECT_TIME && isDirect == true) {
			nx = 1;
			direct_time = 0;
			isDirect = false;
		}
		else if (isDirect == false) {
			vx = -ax * dt;
			startDirect();
		}
	}
	else if (nx == 1) {
		if (GetTickCount64() - direct_time > DIRECT_TIME && isDirect == true) {
			nx = -1;
			direct_time = 0;
			isDirect = false;
		}
		else if (isDirect == false) {
			vx = ax * dt;
			startDirect();
		}
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);


}




void Cleaf::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void Cleaf::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CKoopas*>(e->obj)) return;
	if (dynamic_cast<CParaGoomba*>(e->obj)) return;
	if (e->ny != 0)
	{
		vy = 0;
	}
	else
		if (e->nx != 0)
		{
			vx = -vx;
		}


}


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
		isCollidable = false;
		y = start_y - MAX_Y;
		ay = LEAF_GRAVITY_AY;
		ax = LEAF_GRAVITY_AX;
		break;
	}
}

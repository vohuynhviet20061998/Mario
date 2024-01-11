#include "Items.h"
#include "ParaGoomba.h"
#include "PlayScene.h"
#include "Mario.h"

CItems::CItems(float x, float y)
{
	this->x = x;
	this->y = y;
	start_y = y;
	nx = 1;
}

void CItems::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;
	if (state == ITEMS_STATE_LEAF)
	{
		if (nx > 0)
			aniId = ID_ANI_LEAF_RIGHT;
		else
			aniId = ID_ANI_LEAF_LEFT;
	}
	else
	{
		aniId = ID_ANI_SUPERMUSHROOM;
	}
	animations->Get(aniId)->Render(x, y);
}


void CItems::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	isCollidable = true;
	vy += ay * dt;
	x += vx * dt;
	if (state == ITEMS_STATE_SUPERMUSHROOM) {
		if (y < start_y - ITEMS_BBOX_HEIGHT) {
			ay = SUPERMUSHROOM_GRAVITY_AY;
			vx = ax * dt;
			y = start_y - ITEMS_BBOX_HEIGHT;
		}
	}
	else if (state == ITEMS_STATE_SUPERMUSHROOM_RIGHT) {
		if (y < start_y - ITEMS_BBOX_HEIGHT) {
			ay = SUPERMUSHROOM_GRAVITY_AY;
			vx = ax * dt;
			y = start_y - ITEMS_BBOX_HEIGHT;
		}
	}
	else if (state == ITEMS_STATE_LEAF) {
		vy = ay * dt;
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
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CItems::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - ITEMS_BBOX_WIDTH / 2;
	top = y - ITEMS_BBOX_HEIGHT / 2;
	right = left + ITEMS_BBOX_WIDTH;
	bottom = top + ITEMS_BBOX_HEIGHT;
}

void CItems::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CItems::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CItems*>(e->obj)) return;
	if (dynamic_cast<CKoopas*>(e->obj)) return;
	if (dynamic_cast<CParaGoomba*>(e->obj)) return;
	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
	if (dynamic_cast<CCameraBound*>(e->obj))
		OnCollisionWithCameraBound(e);

}

void CItems::OnCollisionWithCameraBound(LPCOLLISIONEVENT e)
{
	CCameraBound* camerabound = dynamic_cast<CCameraBound*>(e->obj);
	if (e->nx != 0 || e->ny != 0) {
		this->Delete();
	}
}

void CItems::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case ITEMS_STATE_SUPERMUSHROOM:
		ax = -SUPERMUSHROOM_GRAVITY_AX;
		ay = -SUPERMUSHROOM_GRAVITY_AY;
		break;

	case ITEMS_STATE_SUPERMUSHROOM_RIGHT:
		ax = SUPERMUSHROOM_GRAVITY_AX;
		ay = -SUPERMUSHROOM_GRAVITY_AY;
		break;

	case ITEMS_STATE_LEAF:
		isCollidable = false;
		y = start_y - MAX_Y;
		ay = LEAF_GRAVITY_AY;
		ax = LEAF_GRAVITY_AX;
		break;
	}
}
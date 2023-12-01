#include "FLowers.h"
#include "Coin.h"
#include <cmath>

#include "debug.h"

Flowers::Flowers(float x, float y, int object) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = 0;
	die_start = -1;
	this->object = object;
}

void Flowers::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}

void Flowers::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;

};

void Flowers::OnCollisionWith(LPCOLLISIONEVENT e)
{


	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}


}


void Flowers::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;


	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void Flowers::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int ID_ANI = -1;

	if (state == FLOWER_STATE_IDLE) {
		ID_ANI = ID_ANI_FLOWER_IDLE;
	}
	else if (state == FLOWER_STATE_DOWN) {
		ID_ANI = ID_ANI_FLOWER_DOWN;
	}
	else if (state == FLOWER_STATE_UP) {
		ID_ANI = ID_ANI_FLOWER_UP;
	}

	animations->Get(ID_ANI)->Render(x, y);
	RenderBoundingBox();


}

void Flowers::SetState(int state)
{
	switch (state) {
	case FLOWER_STATE_IDLE:
		vx = 0;
		vy = -1;
		ny = 1;
		break;
	case FLOWER_STATE_DOWN:
	case FLOWER_STATE_UP:
		vx = 0;
		vy = 0;
		ny = 0;
		break;
	}

}

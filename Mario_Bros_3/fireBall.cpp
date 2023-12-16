#include "fireBall.h"
#include "Goomba.h"


fireBall::fireBall(float x, float y) : CGameObject(x, y)
{
	this->x = x;
	this->y = y - FIREBALL_Y;

	this->vx = FIRE_BALL_SPEED_X;
	this->vy = FIRE_BALL_SPEED_Y;



	mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
}

void fireBall::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_FIREBALL)->Render(x, y);

	RenderBoundingBox();
}

void fireBall::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)

{
	if (unfindslidedirecttion) {
		startfindslidedirecttion(dt);
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void fireBall::OnNoCollision(DWORD dt)
{
	if (nx < 0) {
		x += -vx * dt;
		if (ny < 0)
			y += vy * dt;
		else
			y -= vy * dt;
	}
	if (nx > 0) {
		x += vx * dt;
		if (ny < 0)
			y -= vy * dt;
		else
			y += vy * dt;
	}

};
void fireBall::OnCollisionWith(LPCOLLISIONEVENT e)
{


	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
	if (dynamic_cast<CGoomba*>(e->obj))
		OnCollisionWithGoomba(e);
}

void fireBall::OnCollisionWithGoomba(LPCOLLISIONEVENT e) {
	if( nx != 0 )
		e->obj->Delete();
}
void fireBall::SetState(int state)
{

}

void fireBall::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - FIREBALL_WIDTH / 2;
	top = y - FIREBALL_HEIGHT/ 2;
	right = left + FIREBALL_WIDTH;
	bottom = top + FIREBALL_HEIGHT;
}

void fireBall::startfindslidedirecttion(DWORD dt)
{
	float x_mario, y_mario;
	mario->GetPosition(x_mario, y_mario);

	if (x_mario < x) {
		nx = -1;
		if (y_mario > y) {
			ny = -1;
		}
		else if (y_mario < y) {
			ny = 1;
		}
	}

	else if (x_mario > x) {
		nx = 1;
		if (y_mario > y) {
			ny = 1;
		}
		else if (y_mario < y) {
			ny = -1;
		}
	}
	unfindslidedirecttion = 0;
}



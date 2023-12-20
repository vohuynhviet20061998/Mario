#include "fireBall.h"
#include "Goomba.h"
#include "FLowers.h"
#include "box.h"


fireBall::fireBall(float x, float y) : CGameObject(x, y)
{
	this->x = x;
	this->y = y - FIREBALL_Y;

	this->vx = FIRE_BALL_SPEED_X;
	this->vy = FIRE_BALL_SPEED_Y;

	unfindslidedirecttion_time = -1;
	unfindslidedirecttion = 1;



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
	

	this->Delete();
	if (dynamic_cast<CMario*>(e->obj)) {
		OnCollisionWithMario(e);
	}

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

void fireBall::OnCollisionWithMario(LPCOLLISIONEVENT e)
{
	mario->CollisionEffect();
}

void fireBall::startfindslidedirecttion(DWORD dt)
{
	float x_mario, y_mario;
	mario->GetPosition(x_mario, y_mario);


	if (x_mario < x) {
		nx = -1;
		this->vx = -FIRE_BALL_SPEED_X;
		if (y_mario > y) {
			ny = -1;
			this->vy = FIRE_BALL_SPEED_Y;
		}
		else if (y_mario < y) {
			ny = 1;
			this->vy = -FIRE_BALL_SPEED_Y;
		}
	}

	else if (x_mario > x) {
		nx = 1;
		this->vx = FIRE_BALL_SPEED_X;
		if (y_mario > y) {
			ny = 1;
			this->vy = FIRE_BALL_SPEED_Y;
		}
		else if (y_mario < y) {
			ny = -1;
			this->vy = -FIRE_BALL_SPEED_Y;
		}
	}
	unfindslidedirecttion = 0;
}



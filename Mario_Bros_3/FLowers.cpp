#include "FLowers.h"
#include "Coin.h"
#include "PlayScene.h"
#include "fireBall.h"
#include <cmath>

#include "debug.h"

Flowers::Flowers(float x, float y) :CGameObject(x, y)
{

	this->x = x;
	this->y = y;
	start_y = y;
	this->vy = -VENUS_SPEED;
	mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
}

void Flowers::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - FLOWER_BBOX_WIDTH / 2;
	top = y - FLOWER_BBOX_HEIGHT / 2;
	right = left + FLOWER_BBOX_WIDTH;
	bottom = top + FLOWER_BBOX_HEIGHT;
}

void Flowers::OnNoCollision(DWORD dt)
{

};

void Flowers::OnCollisionWith(LPCOLLISIONEVENT e)
{
}


void Flowers::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	this->y += this->vy;
	float x_mario, y_mario;
	mario->GetPosition(x_mario, y_mario);


	if (((x - x_mario < VENUS_WIDTH) && (((x + VENUS_WIDTH) - x_mario) > 0)) || ((y - y_mario > 0) && (((x + VENUS_WIDTH) - x_mario) > 0) && (x - x_mario < 0))) {
		isStop = true;
	}
	else {
		isStop = false;
	}
	if (!this->isShooting ) {
		if (y_mario > this->y)
			this->isUp = false;
		else if (y_mario < this->y)
			this->isUp = true;
		if (x_mario < this->x) {
			this->isRight = false;
		}
		else if (x_mario > this->x) {
			this->isRight = true;
		}
		if (y < start_y - VENUS_HEIGHT)
		{
			this->vy = 0.0f;
			startShootingTime();
			fireBall *fireball = new fireBall(this->x, this->y);
			if(this->x > mario->get_X())
				fireball->SetSpeed(-FIRE_BALL_SPEED_X, FIRE_BALL_SPEED_Y);
			else
				fireball->SetSpeed(FIRE_BALL_SPEED_X, FIRE_BALL_SPEED_Y);
			CPlayScene* scene = (LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene();
			scene->objects.push_back(fireball);	

		}
	}
	else if (GetTickCount64() - this->shootingTime > VENUS_SHOOTING_TIME) {

		this->shootingTime = 0;
		this->isShooting = false;
		this->vy = VENUS_SPEED;
	}
	if (y > start_y + VENUS_HEIGHT) {
		if (this->isStop) {
			this->vy = 0;
		}
		else
			this->vy = -VENUS_SPEED;
	}


	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void Flowers::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int ID_ANI = -1;

	if (this->isRight == true) {
		if (this->isShooting == true) {
			if (this->isUp == true)
				ID_ANI = ID_ANI_VENUS_SHOOT_UP_RIGHT;
			else
				ID_ANI = ID_ANI_VENUS_SHOOT_DOWN_RIGHT;
		}
		else
			if (this->isUp == true) {
				ID_ANI = ID_ANI_VENUS_UP_RIGHT;
			}
			else
				ID_ANI = ID_ANI_VENUS_DOWN_RIGHT;
	}
	else
	{
		if (this->isShooting == true) {
			if (this->isUp == true)
				ID_ANI = ID_ANI_VENUS_SHOOT_UP_LEFT;
			else
				ID_ANI = ID_ANI_VENUS_SHOOT_DOWN_LEFT;
		}
		else
			if (this->isUp == true) {
				ID_ANI = ID_ANI_VENUS_UP_LEFT;
			}
			else
				ID_ANI = ID_ANI_VENUS_DOWN_LEFT;
	}

	animations->Get(ID_ANI)->Render(this->x, this->y);
	RenderBoundingBox();


}

void Flowers::startShootingTime()
{
	this->isShooting = true;
	this->shootingTime = GetTickCount64();
}


void Flowers::SetState(int state)
{

}

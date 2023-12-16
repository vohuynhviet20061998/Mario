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
	this->type = type;
	start_y = y;
	vy = -VENUS_SPEED;
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
	y += vy;
	float x_mario, y_mario;
	mario->GetPosition(x_mario, y_mario);
	if (((x - x_mario < VENUS_WIDTH) && (((x + VENUS_WIDTH) - x_mario) > 0)) || ((y - y_mario > 0) && (((x + VENUS_WIDTH) - x_mario) > 0) && (x - x_mario < 0))) {
		isStop = true;
	}
	else {
		isStop = false;
	}
	if (isShooting == false) {
		if (y_mario > y)
			isUp = false;
		else if (y_mario < y)
			isUp = true;
		if (x_mario < x) {
			isRight = false;
		}
		else if (x_mario > x) {
			isRight = true;
		}
		if (y < start_y - VENUS_HEIGHT) 
		{
			vy = 0.0f;
			startShootingTime();
			fireBall *fireball = new fireBall(x, y);
			CPlayScene* scene = (LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene();
			scene->objects.push_back(fireball);

		}
	}
	else if (GetTickCount64() - shootingTime > VENUS_SHOOTING_TIME) {

		shootingTime = 0;
		isShooting = false;
		vy = VENUS_SPEED;
	}
	if (y > start_y + VENUS_HEIGHT) {
		if (isStop == true) {
			vy = 0;
		}
		else
			vy = -VENUS_SPEED;
	}


	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void Flowers::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int ID_ANI = -1;

	if (isRight == true) {
		if (isShooting == true) {
			if (isUp == true)
				ID_ANI = ID_ANI_VENUS_SHOOT_UP_RIGHT;
			else
				ID_ANI = ID_ANI_VENUS_SHOOT_DOWN_RIGHT;
		}
		else
			if (isUp == true) {
				ID_ANI = ID_ANI_VENUS_UP_RIGHT;
			}
			else
				ID_ANI = ID_ANI_VENUS_DOWN_RIGHT;
	}
	else
	{
		if (isShooting == true) {
			if (isUp == true)
				ID_ANI = ID_ANI_VENUS_SHOOT_UP_LEFT;
			else
				ID_ANI = ID_ANI_VENUS_SHOOT_DOWN_LEFT;
		}
		else
			if (isUp == true) {
				ID_ANI = ID_ANI_VENUS_UP_LEFT;
			}
			else
				ID_ANI = ID_ANI_VENUS_DOWN_LEFT;
	}

	animations->Get(ID_ANI)->Render(x, y);
	RenderBoundingBox();


}

void Flowers::startShootingTime()
{
	isShooting = true;
	shootingTime = GetTickCount64();
}


void Flowers::SetState(int state)
{

}

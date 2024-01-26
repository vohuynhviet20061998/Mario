#include "flowers_xanh.h"
#include "Coin.h"
#include "PlayScene.h"
#include "fireBall.h"
#include <cmath>

#include "debug.h"

flowers_xanh::flowers_xanh(float x, float y) :CGameObject(x, y)
{

	this->x = x;
	this->y = y + 31;
	start_y = y;
	this->vy = -VENUS_SPEED;

	isShootingTime = false;
	isUp = false;
	isRight = false;
	bool isStop = false;
	bool isFire = false;
	mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
}

void flowers_xanh::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - FLOWER_BBOX_WIDTH / 2;
	top = y - FLOWER_BBOX_HEIGHT / 2;
	right = left + FLOWER_BBOX_WIDTH;
	bottom = top + FLOWER_BBOX_HEIGHT;
}

void flowers_xanh::OnNoCollision(DWORD dt)
{

};

void flowers_xanh::OnCollisionWith(LPCOLLISIONEVENT e)
{
}


void flowers_xanh::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	this->y += this->vy;
	float x_mario, y_mario;
	mario->GetPosition(x_mario, y_mario);


	if (((this->x - x_mario < VENUS_WIDTH) && (((this->x + VENUS_WIDTH) - x_mario) > 0)) || ((this->y - y_mario > 0) && (((this->x + VENUS_WIDTH) - x_mario) > 0) && (this->x - x_mario < 0))) {
		this->isStop = true;
	}
	else {
		this->isStop = false;
	}

	if ((this->x > x_mario) && ((this->x - VENUS_LIMIT_FIRE) < x_mario)) {
		if (this->y > y_mario && ((this->y - VENUS_LIMIT_FIRE) < y_mario)) {
			this->isFire = true;
		}
		else if (this->y < y_mario && ((this->y + VENUS_LIMIT_FIRE) > y_mario)) {
			this->isFire = true;
		}
		else
			this->isFire = false;
	}
	else if ((this->x < x_mario) && ((this->x + VENUS_LIMIT_FIRE) > x_mario)) {
		if (this->y > y_mario && ((this->y - VENUS_LIMIT_FIRE) < y_mario)) {
			this->isFire = true;
		}
		else if (this->y < y_mario && ((this->y + VENUS_LIMIT_FIRE) > y_mario)) {
			this->isFire = true;
		}
		else
			this->isFire = false;
	}
	if (!this->isShootingTime) {
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
		if ((y < start_y - VENUS_HEIGHT))
		{
			this->vy = 0.0f;
			if (this->isFire) {
				startShootingTime();
				fireBall* fireball = new fireBall(this->x, this->y);
				if (this->x > mario->get_X())
					fireball->SetSpeed(-FIRE_BALL_SPEED_X, FIRE_BALL_SPEED_Y);
				else
					fireball->SetSpeed(FIRE_BALL_SPEED_X, FIRE_BALL_SPEED_Y);
				fireball->startfindslidedirecttion(dt);
				CPlayScene* scene = (LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene();
				scene->objects.push_back(fireball);

			}

		}
	}
	else if (GetTickCount64() - this->shootingTime > VENUS_SHOOTING_TIME) {

		this->shootingTime = 0;
		this->isShootingTime = false;
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


void flowers_xanh::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = 0;
	if (isRight == true) {
		if (isShootingTime == true) {
			if (isUp == true)
				aniId = ID_ANI_VENUS_GREEN_SHOOT_UP_RIGHT;
			else
				aniId = ID_ANI_VENUS_GREEN_SHOOT_DOWN_RIGHT;
		}
		else
			if (isUp == true) {
				aniId = ID_ANI_VENUS_GREEN_UP_RIGHT;
			}
			else
				aniId = ID_ANI_VENUS_GREEN_DOWN_RIGHT;
	}
	else
	{
		if (isShootingTime == true) {
			if (isUp == true)
				aniId = ID_ANI_VENUS_GREEN_SHOOT_UP_LEFT;
			else
				aniId = ID_ANI_VENUS_GREEN_SHOOT_DOWN_LEFT;
		}
		else
			if (isUp == true) {
				aniId = ID_ANI_VENUS_GREEN_UP_LEFT;
			}
			else
				aniId = ID_ANI_VENUS_GREEN_DOWN_LEFT;
	}

	animations->Get(aniId)->Render(this->x, this->y);
	RenderBoundingBox();


}

void flowers_xanh::startShootingTime()
{
	this->isShootingTime = true;
	this->shootingTime = GetTickCount64();
}


void flowers_xanh::SetState(int state)
{

}

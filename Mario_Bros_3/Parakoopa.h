#pragma once
#include "GameObject.h"
#include "Mario.h"
#include "Game.h"



#define PARAKOOPA_GRAVITY 0.001f
#define PARAKOOPA_GRAVITY_X 0.0002f
#define PARAKOOPA_WALKING_SPEED 0.02f
#define PARAKOOPA_WALKING_SPEED_MAX 1.0f
#define PARAKOOPA_JUMP_Y 0.5f
#define PARAKOOPA_SLIDE_SPEED 0.5f

#define BACK_TIME 3000
#define PARAKOOPA_UNTOUCHABLE_TIME 5000

#define PARAKOOPA_BBOX_WIDTH 16
#define PARAKOOPA_BBOX_HEIGHT 25
#define PARAKOOPA_BBOX_HEIGHT_DIE 16

#define PARAKOOPA_DIE_TIMEOUT 100
#define PARAKOOPA_WAKING_TIMEOUT 2000


#define PARAKOOPA_STATE_WALKING 900
#define PARAKOOPA_STATE_DIE 901
#define PARAKOOPA_STATE_WAKING 902
#define PARAKOOPA_STATE_SLIDE 903
#define PARAKOOPA_STATE_FLY 904

#define ID_ANI_PARAKOOPA_FLY_LEFT 14001
#define ID_ANI_PARAKOOPA_FLY_RIGHT 14002
#define ID_ANI_PARAKOOPA_WALKING_LEFT 14003
#define ID_ANI_PARAKOOPA_WALKING_RIGHT 14004
#define ID_ANI_PARAKOOPA_DIE 14005
#define ID_ANI_PARAKOOPA_WAKING 14006
#define ID_ANI_PARAKOOPA_SLIDE 14007

#define MARIO_SMALL_HANDLED_WIDTH 23
#define MARIO_SMALL_HANDLED_HEIGHT 2

#define MARIO_BIG_HANDLED_WIDTH 20
#define MARIO_BIG_HANDLED_HEIGHT 10

#define MARIO_RACCOON_HANDLED_WIDTH 35
#define MARIO_RACCOON_HANDLED_HEIGHT 10

#define PARAKOOPA_LEVEL_WING 1
#define PARAKOOPA_LEVEL_NO_WING 2


class CParaKoopa : public CGameObject
{
protected:
	float ax;
	float ay;
	int type;
	float start_x;
	float start_y;
	float maxVx;
	float maxVy;
	ULONGLONG reset_time;
	CMario* mario;
	ULONGLONG die_start;
	ULONGLONG waking_start;
	BOOLEAN isHandled;
	BOOLEAN isOnPlatform;

	bool isBack = false;
	bool isRight = true;

	int level;

	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();

	int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	void OnCollisionWith(LPCOLLISIONEVENT e);

	void OnCollisionWithQuestionBrick(LPCOLLISIONEVENT e);
	void OnCollisionWithCameraBound(LPCOLLISIONEVENT e);
	void OnCollisionWithPlatform(LPCOLLISIONEVENT e);
	void OnCollisionWithBigBox(LPCOLLISIONEVENT e);


public:
	CParaKoopa(float x, float y);
	virtual void SetState(int state);
	void startWakingTime() { waking_start = GetTickCount64(); }
	int Getlevel() { return this->level; }
	void Setlevel(int level) { this->level = level; }
	void setPositionHandled();
	void HandledByMario() { isHandled = true; }
	void HandledByMarioRelease() { isHandled = false; }
	void startBack() { isBack = true; 	reset_time = GetTickCount64(); }
	void setPositionSlide();

	void Release() {};
};
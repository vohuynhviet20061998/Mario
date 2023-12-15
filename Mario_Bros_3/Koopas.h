#pragma once
#include "GameObject.h"
#include "Mario.h"


#define KOOPAS_GRAVITY 0.002f
#define KOOPAS_WALKING_SPEED 0.07f
#define KOOPAS_SLIDE_SPEED 0.1f

#define KOOPAS_BBOX_WIDTH 16
#define KOOPAS_BBOX_HEIGHT 24
#define KOOPAS_BBOX_HEIGHT_DIE 16

#define KOOPAS_DIE_TIMEOUT 5000
#define KOOPAS_WAKING_TIMEOUT 2000

#define KOOPAS_STATE_WALKING 100
#define KOOPAS_STATE_DIE 200
#define KOOPAS_STATE_SLIDE 300
#define KOOPAS_STATE_WAKING 400

#define ID_ANI_KOOPAS_WALKING_LEFT 10001
#define ID_ANI_KOOPAS_WALKING_RIGHT 10002 
#define ID_ANI_KOOPAS_WAKING 10005
#define ID_ANI_KOOPAS_SLIDE 10003
#define ID_ANI_KOOPAS_DIE 10004

//Pickup by mario
#define MARIO_SMALL_HANDLED_WIDTH 23
#define MARIO_SMALL_HANDLED_HEIGHT 2

#define MARIO_BIG_HANDLED_WIDTH 20
#define MARIO_BIG_HANDLED_HEIGHT 10

#define MARIO_RACCOON_HANDLED_WIDTH 35
#define MARIO_RACCOON_HANDLED_HEIGHT 10

class CKoopas : public CGameObject
{
protected:
	float ax;
	float ay;

	CMario* mario = NULL;

	ULONGLONG die_start;
	ULONGLONG waking_start;

	BOOLEAN isHandled = false;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CKoopas(float x, float y);
	virtual void SetState(int state);
	void startWakingTime() { waking_start = GetTickCount64(); }
	void HandledByMario();
	void HandledByMarioRelease();
	void setPositionByHandle();
	void setPositionSlide();
	void Release() {};
};
#pragma once
#include "GameObject.h"

#define GOOMBA_GRAVITY 0.002f
#define GOOMBA_WALKING_SPEED 0.05f


#define GOOMBA_BBOX_WIDTH 16
#define GOOMBA_BBOX_HEIGHT 14
#define GOOMBA_BBOX_HEIGHT_DIE 7

#define GOOMBA_DIE_TIMEOUT 500

#define GOOMBA_STATE_WALKING 100
#define GOOMBA_STATE_DIE 200
#define GOOMBA_STATE_FLY	300

#define GOOMBA_FLY_SPEED_Y	0.5f

#define ID_ANI_GOOMBA_WALKING 5000
#define ID_ANI_GOOMBA_DIE 5001

#define GOOMBA_OBJECT_NORMAL	30
#define GOOMBA_OBJECT_FLY	40

#define ID_ANI_GOOMBA_FLY_WALK	6001
#define ID_ANI_GOOMBA_FLY	6002

class CGoomba : public CGameObject
{
protected:
	float ax;
	float ay;
	int coin = 0;

	ULONGLONG die_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);


public:
	CGoomba(float x, float y, int object);
	void Release() {};
	virtual void SetState(int state);
};
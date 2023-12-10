#pragma once
#include "GameObject.h"

#define FLOWER_BBOX_WIDTH 16
#define FLOWER_BBOX_HEIGHT 32


#define ID_ANI_FLOWER_IDLE	2000
#define ID_ANI_FLOWER_DOWN	2001
#define ID_ANI_FLOWER_UP	2002

#define FLOWER_STATE_IDLE	100
#define FLOWER_STATE_DOWN	200
#define FLOWER_STATE_UP		300




class Flowers : public CGameObject
{
protected:
	float ax;
	float ay;

	ULONGLONG die_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);


public:
	Flowers(float x, float y, int object);
	void Release() {};
	virtual void SetState(int state);
};
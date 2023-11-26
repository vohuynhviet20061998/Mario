#pragma once
#include "GameObject.h"

#define FLOWER_BBOX_WIDTH 16
#define FLOWER_BBOX_HEIGHT 28


#define ID_ANI_FLOWER	2000

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
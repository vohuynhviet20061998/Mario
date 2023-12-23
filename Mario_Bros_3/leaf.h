#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_LEAF_LEFT 12001
#define ID_ANI_LEAF_RIGHT 12002

#define leaf_BBOX_WIDTH 16
#define leaf_BBOX_HEIGHT 16

#define DIRECT_TIME	1000

#define LEAF_GRAVITY_AX 0.003f
#define LEAF_GRAVITY_AY 0.002f

#define leaf_STATE_IDLE 1

#define MAX_Y 150
class Cleaf : public CGameObject {
	float ax;
	float ay;
	float start_y;
	ULONGLONG direct_time;
	BOOLEAN isCollidable = true;
	BOOLEAN isDirect = false;
public:
	Cleaf(float x, float y)  {
		this->x = x;
		this->y = y;
		start_y = y;
		nx = 1;
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual int IsCollidable() { return isCollidable != false; };
	virtual int IsBlocking() { return 0; }
	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void SetState(int state);
	void startDirect() { direct_time = GetTickCount64(); isDirect = true; };
	void Release() {};
};
#pragma once
#include "GameObject.h"
#include "Brick_questions.h"

#include "Platform.h"
#include "CameraBound.h"
#include "Goomba.h"

#define SUPERMUSHROOM_GRAVITY_AX 0.003f
#define SUPERMUSHROOM_GRAVITY_AY 0.004f

#define LEAF_GRAVITY_AX 0.003f
#define LEAF_GRAVITY_AY 0.002f

#define MAX_Y 150

#define ITEMS_STATE_SUPERMUSHROOM 1
#define ITEMS_STATE_SUPERMUSHROOM_RIGHT 11
#define ITEMS_STATE_LEAF 2

#define ITEMS_BBOX_WIDTH 48
#define ITEMS_BBOX_HEIGHT 44

#define ID_ANI_SUPERMUSHROOM 11000
#define ID_ANI_LEAF_LEFT 12001
#define ID_ANI_LEAF_RIGHT 12002
#define SUPERMUSHROOM_WALKING_SPEED 0.13f

#define DIRECT_TIME 1000

class CItems : public CGameObject
{
protected:
	float x, y, start_y, ax, ay, nx;
	BOOLEAN isCollidable = true;
	BOOLEAN isDirect = false;
	ULONGLONG direct_time;
	virtual void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);
	virtual void OnCollisionWithCameraBound(LPCOLLISIONEVENT e);
	virtual int IsCollidable() { return (isCollidable != false && state != ITEMS_STATE_LEAF); };
public:
	CItems(float x, float y);

	virtual void SetState(int state);
	void startDirect() { direct_time = GetTickCount64(); isDirect = true; };
};

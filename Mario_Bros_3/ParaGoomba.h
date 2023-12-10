#pragma once
#include "GameObject.h"
#include "debug.h"
#include "Mario.h"

#define PARAGOOMBA_GRAVITY 0.002f
#define PARAGOOMBA_WALKING_SPEED 0.1f
#define PARAGOOMBA_KICK_BY_RACCOON_SPEED 0.8f
#define PARAGOOMBA_KICK_BY_KOOPA_SPEED 0.6f


#define PARAGOOMBA_BBOX_WIDTH 48
#define PARAGOOMBA_BBOX_HEIGHT 40
#define PARAGOOMBA_BBOX_HEIGHT_DIE 25

#define PARAGOOMBA_DIE_TIMEOUT 500

#define PARAGOOMBA_STATE_WING 100
#define PARAGOOMBA_STATE_DIE 200
#define PARAGOOMBA_STATE_NORMAL 300
#define PARAGOOMBA_STATE_FLY 400
#define PARAGOOMBA_STATE_KICK_BY_RACCOON 500
#define PARAGOOMBA_STATE_KICK_BY_KOOPA 600

#define PARAGOOMBA_LEVEL_WING 1
#define PARAGOOMBA_LEVEL_NO_WING 2


#define ID_ANI_PARAGOOMBA_WALK_FLY 6001
#define ID_ANI_PARAGOOMBA_FLY 6002
#define ID_ANI_PARAGOOMBA_DIE 6003
#define ID_ANI_PARAGOOMBA_NORMAL 6004


#define PARAGOOMBA_WALK_TIME 3000


#define PARAGOOMBA_JUMP_HIGH_SPEED 0.5f
#define PARAGOOMBA_JUMP_LOW_SPEED 0.3f

#define BACK_TIME 2000
class CParaGoomba : public CGameObject
{
protected:
	float ax;
	float ay;

	float die_start;

	CMario* mario = NULL;
	BOOLEAN isOnPlatform;
	BOOLEAN isCollision = true;


	int level;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return (state != PARAGOOMBA_STATE_KICK_BY_RACCOON && state != PARAGOOMBA_STATE_KICK_BY_KOOPA && isCollision != false); };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CParaGoomba(float x, float y);
	virtual void SetState(int state);
	int Getlevel() { return this->level; }
	void Setlevel(int level) { this->level = level; };
	void Release() {};
};
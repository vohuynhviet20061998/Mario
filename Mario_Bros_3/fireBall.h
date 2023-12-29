#pragma once
#include "GameObject.h"
#include "Animations.h"
#include "Mario.h"
#include "PlayScene.h"

#define FIREBALL_LEFT 1
#define FIREBALL_RIGHT 2
#define FIREBALL_SPEED 0.5f

#define ID_ANI_FIREBALL	30000
#define Width_fireBall 8
#define FIREBALL_WIDTH	8
#define FIREBALL_HEIGHT	8

#define FIREBALL_Y 8
#define FIRE_BALL_SPEED_X 0.3f
#define FIRE_BALL_SPEED_Y 0.1f

class fireBall : public CGameObject
{
private:
	float maxVx;
	float ax;
	CMario* mario = NULL;

	ULONGLONG unfindslidedirecttion_time;
	BOOLEAN unfindslidedirecttion;

	ULONGLONG untouchable = 0;
	ULONGLONG untouchable_start = -1;
public:
	
	fireBall(float x, float y);
	

	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);
	int IsCollidable() { return 1; }
	int IsThrough() { return 1; }
	void SetState(int state);
	void Release(){}
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	
	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithParaGoomba(LPCOLLISIONEVENT e);
	

	void startfindslidedirecttion(DWORD dt);

};



#pragma once
#include "GameObject.h"
#include "Animations.h"

#define FIREBALL_LEFT 1
#define FIREBALL_RIGHT 2
#define FIREBALL_SPEED 3.0f

#define ID_ANI_FIREBALL	30000
#define Width_fireBall 8
#define FIREBALL_WIDTH	8
#define FIREBALL_HEIGHT	16

class fireBall : public CGameObject
{
private:
	float maxVx;
	float ax;
public:
	fireBall(float x, float y) : CGameObject(x, y) {}
	

	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);
	int IsBlocking() { return 0; }
	int IsCollidable() { return 1; };
	void SetState(int state);
	void Release(){}
	void GetBoundingBox(float& left, float& top, float& right, float& bottom);

};



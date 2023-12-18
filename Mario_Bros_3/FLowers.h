#pragma once
#include "GameObject.h"
#include "Mario.h"

#define FLOWER_BBOX_WIDTH 16
#define FLOWER_BBOX_HEIGHT 32
#define VENUS_HEIGHT 16
#define VENUS_WIDTH	32
#define VENUS_LIMIT_FIRE	80


#define ID_ANI_FLOWER_IDLE	2000
#define ID_ANI_FLOWER_DOWN	2001
#define ID_ANI_FLOWER_UP	2002

#define ID_ANI_VENUS_DOWN_LEFT	2001 
#define ID_ANI_VENUS_UP_LEFT 2002
#define ID_ANI_VENUS_SHOOT_DOWN_LEFT 2003
#define ID_ANI_VENUS_SHOOT_UP_LEFT 2004

#define ID_ANI_VENUS_DOWN_RIGHT 2005
#define ID_ANI_VENUS_UP_RIGHT 2006
#define ID_ANI_VENUS_SHOOT_DOWN_RIGHT 2007
#define ID_ANI_VENUS_SHOOT_UP_RIGHT 2008

#define VENUS_SPEED 0.25f

#define VENUS_SHOOTING_TIME 3000





class Flowers : public CGameObject
{
protected:
	float x, y, start_y;
	bool isShootingTime = false;
	bool isUp = false;
	bool isRight = false;
	bool isStop = false;
	bool isFire = false;
	ULONGLONG shootingTime;
	CMario* mario = NULL;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);


public:
	Flowers(float x, float y);
	void Release() {};
	virtual void SetState(int state);
	void startShootingTime();
};
#pragma once
#include "GameObject.h"
#include "Mario.h"

#define FLOWER_BBOX_WIDTH 16
#define FLOWER_BBOX_HEIGHT 32
#define VENUS_HEIGHT 16
#define VENUS_WIDTH	32
#define VENUS_LIMIT_FIRE	80


#define ID_ANI_FLOWER_IDLE	11000
#define ID_ANI_FLOWER_DOWN	11001
#define ID_ANI_FLOWER_UP	11002

#define ID_ANI_VENUS_GREEN_DOWN_LEFT	11001 
#define ID_ANI_VENUS_GREEN_UP_LEFT 11002
#define ID_ANI_VENUS_GREEN_SHOOT_DOWN_LEFT 11003
#define ID_ANI_VENUS_GREEN_SHOOT_UP_LEFT 11004

#define ID_ANI_VENUS_GREEN_DOWN_RIGHT 11005
#define ID_ANI_VENUS_GREEN_UP_RIGHT 11006
#define ID_ANI_VENUS_GREEN_SHOOT_DOWN_RIGHT 11007
#define ID_ANI_VENUS_GREEN_SHOOT_UP_RIGHT 11008

#define VENUS_SHOOTING_TIME 3000
#define VENUS_SPEED 0.25f

class flowers_xanh : public CGameObject
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
	flowers_xanh(float x, float y);
	void Release() {};
	virtual void SetState(int state);
	void startShootingTime();
};


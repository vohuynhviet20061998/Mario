#pragma once
#include "GameObject.h"
#include "Mario.h"

#define PIRANHA_BBOX_WIDTH 16
#define PIRANHA_BBOX_HEIGHT 16
#define PIRANHA_HEIGHT 16
#define PIRANHA_WIDTH 16
#define PIRANHA_HEIGHT_DOWN 16

#define ID_ANI_PIRANHA 12000

#define PIRANHA_SPEED 0.25f
#define GROW_UP_TIME 2000

class CPiranha : public CGameObject
{
	float width;
	float height;
	float start_y;
	float start_time;
	bool isStop = false;
	CMario* mario = NULL;
public:
	CPiranha(float x, float y);
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void startTime() { start_time = GetTickCount64(); };
	void Release() {};
};
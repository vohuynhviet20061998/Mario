#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_COIN 110000

#define	COIN_WIDTH 10
#define COIN_BBOX_WIDTH 16
#define COIN_BBOX_HEIGHT 16
#define COIN_STATE_IDLE	0
#define COIN_STATE_JUMP	1
#define COIN_STATE_JUMP_DEFLECT	2
#define COIN_JUMP_Y	0.05f
#define COIN_JUMP_DEFLECT_Y	0.01f
#define TIME_JUMP	500


class CCoin : public CGameObject {
	float ay;
	ULONGLONG time_jump;
public:
	CCoin(float x, float y) : CGameObject(x, y) {
		this->ay = 0;
		SetState(COIN_STATE_IDLE);
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void OnNoCollision(DWORD dt);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
	void SetState(int state);
	void Release(){};
};
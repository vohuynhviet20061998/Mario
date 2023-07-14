#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"


#define	leaf_WIDTH 10
#define leaf_BBOX_WIDTH 16
#define leaf_BBOX_HEIGHT 16
#define leaf_STATE_IDLE	0
#define leaf_STATE_JUMP	1
#define leaf_STATE_WALK	2
#define leaf_WALK_X	0.05f
#define leaf_JUMP_Y	0.05f
#define leaf_JUMP_DEFLECT_Y	0.1f
#define TIME_JUMP	2000


class Cleaf : public CGameObject {
	float ax;
	float ay;
	ULONGLONG time_jump;
	int spriteId;
public:
	Cleaf(float x, float y, int spriteId) : CGameObject(x, y) {
		this->ay = 0.002f;
		this->spriteId = spriteId;
		SetState(leaf_STATE_IDLE);
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void SetState(int state);
	void Release() {};
};
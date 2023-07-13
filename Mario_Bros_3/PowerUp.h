#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_PowerUp 11000

#define	PowerUp_WIDTH 10
#define PowerUp_BBOX_WIDTH 16
#define PowerUp_BBOX_HEIGHT 16
#define PowerUp_STATE_IDLE	0
#define PowerUp_STATE_JUMP	1
#define PowerUp_STATE_JUMP_DEFLECT	2
#define PowerUp_JUMP_Y	0.05f
#define PowerUp_JUMP_DEFLECT_Y	0.01f
#define TIME_JUMP	500


class CPowerUp : public CGameObject {
	float ay;
	ULONGLONG time_jump;
	int spriteId;
public:
	CPowerUp(float x, float y, int spriteId) : CGameObject(x, y) {
		this->ay = 0;
		this->spriteId = spriteId;
		SetState(PowerUp_STATE_IDLE);
	}
	void Render();
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void OnNoCollision(DWORD dt);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }
	void SetState(int state);
	void Release() {};
};
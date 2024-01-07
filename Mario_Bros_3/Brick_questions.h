#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "Textures.h"

#define Brick_Questions_WIDTH 16
#define Brick_Questions_BBOX_WIDTH 16
#define Brick_Questions_BBOX_HEIGHT 16
#define ID_ANI_Brick_Questions	210
#define ID_ANI_Brick_normal		211
//#define	ID_ANI_Brick_Tree	310

#define BRICK_OBJECT_QUESTION	10
#define BRICK_OBJECT_TREE	11

#define QUESTIONBRICK_STATE_NORMAL 1100
#define QUESTIONBRICK_STATE_DISABLE 1200

#define QUESTIONBRICK_JUMP_Y 20.0f

class CBrick_Questions : public CGameObject {
	float x, y, start_y;
	int item_type;
	ULONGLONG throwup_start;

public:
	CBrick_Questions(float x, float y, int item_type) : CGameObject(x, y) {
		this->x = x;
		this->y = y;
		start_y = y;
		this->item_type = item_type;
	}

	void Render();
	void Update(DWORD dt,vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	virtual void SetState(int state);
	void StartThrowup() { throwup_start = GetTickCount64(); }


	void Release();
};
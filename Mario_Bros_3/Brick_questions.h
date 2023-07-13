#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "Textures.h"

#define Brick_Questions_WIDTH 16
#define Brick_Questions_BBOX_WIDTH 16
#define Brick_Questions_BBOX_HEIGHT 16
#define ID_ANI_Brick_Questions	210

class CBrick_Questions : public CGameObject {
public:
	CBrick_Questions(float x, float y) : CGameObject(x, y) {
		this->x = x;
		this->y = y;
	}

	void Render();
	void Update(DWORD dt,vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);


	void Release();
};
#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "Textures.h"

#define Brick_Emty_WIDTH 16
#define Brick_Emty_BBOX_WIDTH 16
#define Brick_Emty_BBOX_HEIGHT 16

class CBrick_Emty : public CGameObject {
	int spriteId;
public:
	CBrick_Emty(float x, float y, int spriteId) : CGameObject(x, y) {
		this->x = x;
		this->y = y;
		this->spriteId = spriteId;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);


	void Release();
};
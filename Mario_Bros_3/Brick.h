#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "Textures.h"

#define BRICK_WIDTH 16
#define BRICK_BBOX_WIDTH 16
#define BRICK_BBOX_HEIGHT 16

class CBrick : public CGameObject {
	int spriteIdBegin;
	int length;
	float cellWidth;
	float cellHeight;
public:
	CBrick(float x, float y, float cellWidth, float cellHeight, int length, int spriteIdBegin) : CGameObject(x, y) {
		this->x = x;
		this->y = y;
		this->cellWidth = cellWidth;
		this->cellHeight = cellHeight;
		this->length = length;
		this->spriteIdBegin = spriteIdBegin;
	}
	void Render();
	void Update(DWORD dt) {}
	void RenderBoundingBox();
	void GetBoundingBox(float& l, float& t, float& r, float& b);


	void Release() ;
};
#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "Textures.h"



class CMap : public CGameObject {
	int spriteIdBegin;
public:
	CMap(float x, float y,int spriteIdBegin) : CGameObject(x, y) {
		this->x = x;
		this->y = y;
		this->spriteIdBegin = spriteIdBegin;
	}
	void Render();
	void Update(DWORD dt) {}
	void RenderBoundingBox();
	void GetBoundingBox(float& l, float& t, float& r, float& b);


	void Release();
};
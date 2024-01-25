#pragma once
#include "GameObject.h"
#include "Mario.h"
#include "Sprite.h"


class Hud : public CGameObject
{
protected:
	float x;
	float y;
	CMario* mario = NULL;
public:
	Hud(float x, float y);
	void Update();
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b) { l = 0; t = 0; r = 0; b = 0; };
};
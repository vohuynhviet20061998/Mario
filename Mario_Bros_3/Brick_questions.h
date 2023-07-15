#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "Textures.h"

#define Brick_Questions_WIDTH 16
#define Brick_Questions_BBOX_WIDTH 16
#define Brick_Questions_BBOX_HEIGHT 16
#define ID_ANI_Brick_Questions	210
#define	ID_ANI_Brick_Tree	310

#define BRICK_OBJECT_QUESTION	10
#define BRICK_OBJECT_TREE	11

class CBrick_Questions : public CGameObject {
	int object;
public:
	CBrick_Questions(float x, float y, int object) : CGameObject(x, y) {
		this->x = x;
		this->y = y;
		this->object = object;
	}

	void Render();
	void Update(DWORD dt,vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);


	void Release();
};
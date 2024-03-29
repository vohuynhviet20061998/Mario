#pragma once

#include <Windows.h>
#include <d3d10.h>
#include <vector>

#include "Animation.h"
#include "Animations.h"
#include "Sprites.h"
#include "Collision.h"

using namespace std;

#define ID_TEX_BBOX -100		// special texture to draw object bounding box
#define BBOX_ALPHA 0.0f		// Bounding box transparency

class CGameObject
{
protected:

	float x;
	float y;

	float vx;
	float vy;

	int nx;
	int ny;

	int state;

	bool isDeleted;

	int object;

public:
	int get_object() { return this->object; }
	void set_X(float x) {
		this->x = x;
	}
	float get_X() { return this->x; }
	void set_Y(float y) {
		this->y = y;
	}
	float get_Y() { return this->y; }
	void set_NX(int nx) {
		this->nx = nx;
	}
	int get_NY() { return this->ny; }

	void set_NY(int ny) {
		this->ny = ny;
	}
	int get_NX() { return this->nx; }

	void GetDirection(float& nx, float& ny) {
		this->nx = nx;
		this->ny = ny;
	}

	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->vy = vy; }
	void GetPosition(float& x, float& y) { x = this->x; y = this->y; }
	void GetSpeed(float& vx, float& vy) { vx = this->vx; vy = this->vy; }

	int GetState() { return this->state; }
	virtual void Delete() { isDeleted = true; }
	bool IsDeleted() { return isDeleted; }

	void RenderBoundingBox();

	CGameObject();
	CGameObject(float x, float y) :CGameObject() { this->x = x; this->y = y; }


	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) = 0;
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects = NULL) {};
	virtual void Render() = 0;
	virtual void SetState(int state) { this->state = state; }

	//
	// Collision ON or OFF ? This can change depending on object's state. For example: die
	//
	virtual int IsCollidable() { return 0; };

	// When no collision has been detected (triggered by CCollision::Process)
	virtual void OnNoCollision(DWORD dt) {};

	// When collision with an object has been detected (triggered by CCollision::Process)
	virtual void OnCollisionWith(LPCOLLISIONEVENT e) {};

	// Is this object blocking other object? If YES, collision framework will automatically push the other object
	virtual int IsBlocking() { return 1; }
	virtual int IsDirectionColliable(float nx, float ny) { return 1; }
	

	~CGameObject();

	static bool IsDeleted(const LPGAMEOBJECT& o) { return o->isDeleted; }
	virtual void Release() = 0;


};

class CGameObject;
typedef CGameObject* LPGAMEOBJECT;

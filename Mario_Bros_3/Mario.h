#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define MARIO_WALKING_SPEED		0.1f
#define MARIO_RUNNING_SPEED		0.2f

#define MARIO_ACCEL_WALK_X	0.0005f
#define MARIO_ACCEL_RUN_X	0.0007f

#define MARIO_JUMP_SPEED_Y		0.5f
#define MARIO_JUMP_RUN_SPEED_Y	0.6f

#define MARIO_GRAVITY			0.002f

#define MARIO_JUMP_DEFLECT_SPEED  0.4f

#define MARIO_STATE_DIE				-10
#define MARIO_STATE_IDLE			0
#define MARIO_STATE_WALKING_RIGHT	100
#define MARIO_STATE_WALKING_LEFT	200

#define MARIO_STATE_JUMP			300
#define MARIO_STATE_RELEASE_JUMP    301

#define MARIO_STATE_RUNNING_RIGHT	400
#define MARIO_STATE_RUNNING_LEFT	500

#define MARIO_STATE_SIT				600
#define MARIO_STATE_SIT_RELEASE		601

#define MARIO_STATE_WALK_UP			700
#define MARIO_STATE_WALK_DOWN		701


#pragma region ANIMATION_ID

#define ID_ANI_MARIO_IDLE_RIGHT 400
#define ID_ANI_MARIO_IDLE_LEFT 401

#define ID_ANI_MARIO_WALKING_RIGHT 500
#define ID_ANI_MARIO_WALKING_LEFT 501

#define ID_ANI_MARIO_RUNNING_RIGHT 600
#define ID_ANI_MARIO_RUNNING_LEFT 601

#define ID_ANI_MARIO_JUMP_WALK_RIGHT 700
#define ID_ANI_MARIO_JUMP_WALK_LEFT 701

#define ID_ANI_MARIO_JUMP_RUN_RIGHT 800
#define ID_ANI_MARIO_JUMP_RUN_LEFT 801

#define ID_ANI_MARIO_SIT_RIGHT 900
#define ID_ANI_MARIO_SIT_LEFT 901

#define ID_ANI_MARIO_BRACE_RIGHT 1000
#define ID_ANI_MARIO_BRACE_LEFT 1001

#define ID_ANI_MARIO_DIE 999

// SMALL MARIO
#define ID_ANI_MARIO_SMALL_IDLE_RIGHT 1100
#define ID_ANI_MARIO_SMALL_IDLE_LEFT 1102

#define ID_ANI_MARIO_SMALL_WALKING_RIGHT 1200
#define ID_ANI_MARIO_SMALL_WALKING_LEFT 1201

#define ID_ANI_MARIO_SMALL_RUNNING_RIGHT 1300
#define ID_ANI_MARIO_SMALL_RUNNING_LEFT 1301

#define ID_ANI_MARIO_SMALL_BRACE_RIGHT 1400
#define ID_ANI_MARIO_SMALL_BRACE_LEFT 1401

#define ID_ANI_MARIO_SMALL_JUMP_WALK_RIGHT 1500
#define ID_ANI_MARIO_SMALL_JUMP_WALK_LEFT 1501

#define ID_ANI_MARIO_SMALL_JUMP_RUN_RIGHT 1600
#define ID_ANI_MARIO_SMALL_JUMP_RUN_LEFT 1601

#define ID_ANI_MARIO_SMALL_WALK_UP 1700
#define ID_ANI_MARIO_SMALL_WALK_DOWN 1701
//fire MARIO

#define ID_ANI_MARIO_FIRE_IDLE_RIGHT 51000
#define ID_ANI_MARIO_FIRE_IDLE_LEFT 52000

#define ID_ANI_MARIO_FIRE_WALKING_RIGHT 53000
#define ID_ANI_MARIO_FIRE_WALKING_LEFT 54000

#define ID_ANI_MARIO_FIRE_RUNNING_RIGHT 55000
#define ID_ANI_MARIO_FIRE_RUNNING_LEFT 56000

#define ID_ANI_MARIO_FIRE_BRACE_RIGHT 57000
#define ID_ANI_MARIO_FIRE_BRACE_LEFT 58000

#define ID_ANI_MARIO_FIRE_JUMP_WALK_RIGHT 59001
#define ID_ANI_MARIO_FIRE_JUMP_WALK_LEFT 60001

#define ID_ANI_MARIO_FIRE_JUMP_RUN_RIGHT 59000
#define ID_ANI_MARIO_FIRE_JUMP_RUN_LEFT 60000

#define ID_ANI_MARIO_FIRE_SIT_RIGHT 61000
#define ID_ANI_MARIO_FIRE_SIT_LEFT 62000

// fly MARIO
#define ID_ANI_MARIO_FLY_IDLE_RIGHT 71000
#define ID_ANI_MARIO_FLY_IDLE_LEFT 72000

#define ID_ANI_MARIO_FLY_WALKING_RIGHT 74000
#define ID_ANI_MARIO_FLY_WALKING_LEFT 73000

#define ID_ANI_MARIO_FLY_RUNNING_RIGHT 76000
#define ID_ANI_MARIO_FLY_RUNNING_LEFT 75000

#define ID_ANI_MARIO_FLY_BRACE_RIGHT 78000
#define ID_ANI_MARIO_FLY_BRACE_LEFT 77000

#define ID_ANI_MARIO_FLY_JUMP_WALK_RIGHT 80000
#define ID_ANI_MARIO_FLY_JUMP_WALK_LEFT 79000

#define ID_ANI_MARIO_FLY_JUMP_RUN_RIGHT 82000
#define ID_ANI_MARIO_FLY_JUMP_RUN_LEFT 81000

#define ID_ANI_MARIO_FLY_UP 83000
#define ID_ANI_MARIO_FLY_DOWN 84000

#define ID_ANI_MARIO_FLY_RIGHT 85000
#define ID_ANI_MARIO_FLY_LEFT 86000

#define ID_ANI_MARIO_FIRE_SIT_RIGHT 87000
#define ID_ANI_MARIO_FIRE_SIT_LEFT 88000

#pragma endregion

#define GROUND_Y 160.0f




#define	MARIO_LEVEL_SMALL	1
#define	MARIO_LEVEL_BIG		2
#define MARIO_LEVEL_FIRE	3

#define MARIO_BIG_BBOX_WIDTH  14
#define MARIO_BIG_BBOX_HEIGHT 24
#define MARIO_BIG_SITTING_BBOX_WIDTH  14
#define MARIO_BIG_SITTING_BBOX_HEIGHT 16

#define MARIO_SIT_HEIGHT_ADJUST ((MARIO_BIG_BBOX_HEIGHT-MARIO_BIG_SITTING_BBOX_HEIGHT)/2)

#define MARIO_SMALL_BBOX_WIDTH  13
#define MARIO_SMALL_BBOX_HEIGHT 12


#define MARIO_UNTOUCHABLE_TIME 2500

class CMario : public CGameObject
{
	BOOLEAN isSitting;
	float maxVx;
	float maxVy;
	float ax;				// acceleration on x 
	float ay;				// acceleration on y 

	int level;
	int untouchable;
	ULONGLONG untouchable_start;
	BOOLEAN isOnPlatform;
	int coin;
	BOOLEAN is_Eat;
	BOOLEAN is_Eat_leaf;
	BOOLEAN is_NO_GRAVITY;

	

	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithCoin(LPCOLLISIONEVENT e);
	void OnCollisionWithBrickQuestions(LPCOLLISIONEVENT e);
	void OnCollisionWithPowerup(LPCOLLISIONEVENT e);
	void OnCollisionWithLeaf(LPCOLLISIONEVENT e);
	void OnCollisionWithPortal(LPCOLLISIONEVENT e);

	int GetAniIdBig();
	int GetAniIdFire();
	int GetAniIdSmall();

public:
	CMario(float x, float y) : CGameObject(x, y)
	{
		isSitting = false;
		maxVx = 0.0f;
		ax = 0.0f;
		ay = MARIO_GRAVITY;

		level = MARIO_LEVEL_SMALL;
		untouchable = 0;
		untouchable_start = -1;
		isOnPlatform = false;
		coin = 0;
		is_Eat = false;
		is_NO_GRAVITY = false;
	}
	CMario(float x, float y, int ay) : CGameObject(x, y)
	{
		isSitting = false;
		maxVx = 0.0f;
		ax = 0.0f;
		this->ay = ay;

		level = MARIO_LEVEL_SMALL;
		untouchable = 0;
		untouchable_start = -1;
		isOnPlatform = false;
		coin = 0;
		is_Eat = false;
		is_NO_GRAVITY = true;
	}

	float get_ay() { return this->ay; }
	BOOLEAN is_No_Gravity() { return this->is_NO_GRAVITY; }
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void SetState(int state);

	int IsCollidable()
	{
		return (state != MARIO_STATE_DIE);
	}

	int IsBlocking() { return (state != MARIO_STATE_DIE && untouchable == 0); }

	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);

	void SetLevel(int l);
	int GetLevel() {
		return this->level;
	}
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount64(); }

	void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	void Release();

};
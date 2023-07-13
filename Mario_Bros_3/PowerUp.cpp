#include "PowerUp.h"

void CPowerUp::Render()
{
	CSprites* s = CSprites::GetInstance();

	s->Get(this->spriteId)->Draw(x, y);

	RenderBoundingBox();
}

void CPowerUp::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{


	if (GetTickCount64() - time_jump < TIME_JUMP) {
		this->vy += ay * dt;
	}
	else if ((GetTickCount64() - time_jump >= TIME_JUMP) && (GetTickCount64() - time_jump <= TIME_JUMP * 2)) {

		this->Delete();
	}
	else if (GetTickCount64() - time_jump > TIME_JUMP * 2) {
		SetState(PowerUp_STATE_IDLE);
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);


}

void CPowerUp::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CPowerUp::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - PowerUp_BBOX_WIDTH / 2;
	t = y - PowerUp_BBOX_HEIGHT / 2;
	r = l + PowerUp_BBOX_WIDTH;
	b = t + PowerUp_BBOX_HEIGHT;
}

void CPowerUp::SetState(int state)
{
	switch (state)
	{
	case PowerUp_STATE_IDLE:
		this->vy = 0;
		this->ay = 0;
		break;
	case PowerUp_STATE_JUMP:
		this->vy = -PowerUp_JUMP_Y;
		time_jump = GetTickCount64();
		break;
	}
}

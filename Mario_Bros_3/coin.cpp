#include "Coin.h"

void CCoin::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_COIN)->Render(x, y);

	RenderBoundingBox();
}

void CCoin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	
	
	if (GetTickCount64() - time_jump < TIME_JUMP) {
		this->vy += ay * dt;
	}
	else if ((GetTickCount64() - time_jump >= TIME_JUMP) && (GetTickCount64() - time_jump <= TIME_JUMP * 2)) {
		
		this->Delete();
	}
	else if (GetTickCount64() - time_jump > TIME_JUMP * 2) {
		SetState(COIN_STATE_IDLE);
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);


}

void CCoin::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CCoin::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - COIN_BBOX_WIDTH / 2;
	t = y - COIN_BBOX_HEIGHT / 2;
	r = l + COIN_BBOX_WIDTH;
	b = t + COIN_BBOX_HEIGHT;
}

void CCoin::SetState(int state)
{
	switch (state)
	{
	case COIN_STATE_IDLE:
		this->vy = 0;
		this->ay = 0;
		break;
	case COIN_STATE_JUMP:
		this->vy = -COIN_JUMP_Y;
		time_jump = GetTickCount64();
		break;
	}
}

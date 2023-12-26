#include "Koopas.h"
#include "Goomba.h"
#include "PlayScene.h"



LPGAME game = CGame::GetInstance();
CKoopas::CKoopas(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = KOOPAS_GRAVITY;
	die_start = -1;
	SetState(KOOPAS_STATE_WALKING);
	mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
}

void CKoopas::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == KOOPAS_STATE_DIE || state == KOOPAS_STATE_SLIDE || state == KOOPAS_STATE_GO)
	{
		left = x - KOOPAS_BBOX_WIDTH / 2;
		top = y - KOOPAS_BBOX_HEIGHT_DIE / 2;
		right = left + KOOPAS_BBOX_WIDTH;
		bottom = top + KOOPAS_BBOX_HEIGHT_DIE;
	}
	else
	{
		left = x - KOOPAS_BBOX_WIDTH / 2;
		top = y - KOOPAS_BBOX_HEIGHT / 2;
		right = left + KOOPAS_BBOX_WIDTH;
		bottom = top + KOOPAS_BBOX_HEIGHT;
	}
}

void CKoopas::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CKoopas::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CKoopas*>(e->obj)) return;
	


	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}

}






void CKoopas::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if ((state == KOOPAS_STATE_DIE) && (GetTickCount64() - die_start > KOOPAS_DIE_TIMEOUT) && isHandled != true)
	{
		SetState(KOOPAS_STATE_GO);
		startWakingTime();
	}

	
	if (state == KOOPAS_STATE_GO && (GetTickCount64() - waking_start > KOOPAS_WAKING_TIMEOUT)) {
		SetState(KOOPAS_STATE_WALKING);
		waking_start = 0;
	}
	if (isHandled == true) {
		if (game->IsKeyDown(DIK_A)) {
			setPositionByHandle();
		}
		else {
			HandledByMarioRelease();
			if (state == KOOPAS_STATE_DIE) {
				SetState(KOOPAS_STATE_SLIDE);
			}
		}
	}


	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CKoopas::Render()
{
	int aniId = 0;
	if (state == KOOPAS_STATE_WALKING) {
		if (vx > 0)
			aniId = ID_ANI_KOOPAS_WALKING_RIGHT;
		else
			aniId = ID_ANI_KOOPAS_WALKING_LEFT;
	}
	else if (state == KOOPAS_STATE_SLIDE) {
		aniId = ID_ANI_KOOPAS_SLIDE;
	}
	else if (state == KOOPAS_STATE_DIE)
	{
		aniId = ID_ANI_KOOPAS_DIE;
	}
	else if (state == KOOPAS_STATE_GO) {
		aniId = ID_ANI_KOOPAS_WAKING;
	}
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CKoopas::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case KOOPAS_STATE_DIE:
		die_start = GetTickCount64();
		vx = 0;
		vy = 0;
		if (isHandled == true) {
			ay = KOOPAS_GRAVITY;
		}
		else {
			ay = 0;
		}
		break;
	case KOOPAS_STATE_WALKING:
		if (waking_start > 0) {
			y -= (KOOPAS_BBOX_HEIGHT - KOOPAS_BBOX_HEIGHT_DIE) / 2;
		}
		vx = KOOPAS_WALKING_SPEED;
		ay = KOOPAS_GRAVITY;
		break;
	case KOOPAS_STATE_SLIDE:
		ay = KOOPAS_GRAVITY;
		setPositionSlide();
		break;
	case KOOPAS_STATE_GO:
		vx = 0;
		vy = 0;
		ax = 0;
		ay = 0;
		break;


	}
}

void CKoopas::setPositionSlide()
{
	float x_mario, y_mario, vx_mario, vy_mario;
	mario->GetPosition(x_mario, y_mario);
	if (x < x_mario)
		vx = -KOOPAS_SLIDE_SPEED;
	else
		vx = KOOPAS_SLIDE_SPEED;
}

void CKoopas::setPositionJump(int x_koopas, int y_koopas)
{
	this->x = x_koopas;

	this->y = y_koopas + (KOOPAS_BBOX_HEIGHT - KOOPAS_BBOX_HEIGHT_DIE) / 2;

}

void CKoopas::setPositionJumpSlide(int x_koopas, int y_koopas)
{
	this->x = x_koopas;
	this->y = y_koopas;
}


void CKoopas::HandledByMario()
{
	isHandled = true;
}


void CKoopas::HandledByMarioRelease()
{
	isHandled = false;
}

void CKoopas::setPositionByHandle()
{
	float x_mario, y_mario, nx_mario, ny_mario;
	mario->GetPosition(x_mario, y_mario);
	nx_mario = mario->get_NX();
	ny_mario = mario->get_NY();

	if (mario->GetLevel() == MARIO_LEVEL_SMALL) {
		if (nx_mario <= 0)
			SetPosition(x_mario - MARIO_SMALL_HANDLED_WIDTH, y_mario - MARIO_SMALL_HANDLED_HEIGHT);
		else if (nx_mario > 0)
			SetPosition(x_mario + MARIO_SMALL_HANDLED_WIDTH, y_mario - MARIO_SMALL_HANDLED_HEIGHT);
	}
	else if (mario->GetLevel() == MARIO_LEVEL_BIG) {
		if (nx_mario <= 0)
			SetPosition(x_mario - MARIO_BIG_HANDLED_WIDTH, y_mario + MARIO_BIG_HANDLED_HEIGHT);
		else if (nx_mario > 0)
			SetPosition(x_mario + MARIO_BIG_HANDLED_WIDTH, y_mario + MARIO_BIG_HANDLED_HEIGHT);
	}
	else {
		if (nx_mario <= 0)
			SetPosition(x_mario - MARIO_RACCOON_HANDLED_WIDTH, y_mario + MARIO_RACCOON_HANDLED_HEIGHT);
		else if (nx_mario > 0)
			SetPosition(x_mario + MARIO_RACCOON_HANDLED_WIDTH, y_mario + MARIO_RACCOON_HANDLED_HEIGHT);
	}
}

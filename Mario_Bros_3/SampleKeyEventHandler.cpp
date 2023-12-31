#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Mario.h"
#include "PlayScene.h"
#include "fireBall.h"
#include "GameObject.h"
#include "PlayScene.h"



void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();

	switch (KeyCode)
	{
	case DIK_X:
		mario->SetState(MARIO_STATE_SIT);
		break;
	case DIK_S:
		if (mario->GetLevel() == MARIO_LEVEL_RACCOON) 
			mario->SetState(MARIO_STATE_RACCOON);
		else {
			mario->SetState(MARIO_STATE_JUMP);
		}
		
		break;
	case DIK_1:
		mario->SetLevel(MARIO_LEVEL_SMALL);
		break;
	case DIK_2:
		mario->SetLevel(MARIO_LEVEL_BIG);
		break;
	case DIK_3:
		mario->SetLevel(MARIO_LEVEL_FIRE);
		break;
	case DIK_4:
		mario->SetLevel(MARIO_LEVEL_RACCOON);
		break;
	case DIK_0:
		mario->SetState(MARIO_STATE_DIE);
		break;
	case DIK_D:
		CGame* game = CGame::GetInstance();
		if (mario->GetLevel() == MARIO_LEVEL_FIRE) {

			fireBall* _fire;

			_fire = new fireBall(mario->get_X(), mario->get_Y() + FIREBALL_HEIGHT);

			if (game->IsKeyDown(DIK_RIGHT)) {
				_fire->SetSpeed(0.2f, 0);
			}
			else if (game->IsKeyDown(DIK_LEFT)) {
				_fire->SetSpeed(-0.2f, 0);
			}
			else if (mario->get_NX() >= 0) {
				_fire->SetSpeed(0.2f, 0);
			}
			else if (mario->get_NX() < 0) {
				_fire->SetSpeed(-0.2f, 0);
			}
			((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->set_Objects(_fire);
			break;

		}

	}

}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);

	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();


	switch (KeyCode)
	{
	case DIK_S:
		mario->SetState(MARIO_STATE_RELEASE_JUMP);
		break;
	case DIK_DOWN:
		mario->SetState(MARIO_STATE_SIT_RELEASE);
		break;

	}
}

void CSampleKeyHandler::KeyState(BYTE* states)
{
	LPGAME game = CGame::GetInstance();
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
		

	if (game->IsKeyDown(DIK_RIGHT))
	{
		if (game->IsKeyDown(DIK_A))
			mario->SetState(MARIO_STATE_RUNNING_RIGHT);
		else
			mario->SetState(MARIO_STATE_WALKING_RIGHT);
	}
	else if (game->IsKeyDown(DIK_LEFT))
	{
		if (game->IsKeyDown(DIK_A))
			mario->SetState(MARIO_STATE_RUNNING_LEFT);
		else
			mario->SetState(MARIO_STATE_WALKING_LEFT);
	}
	else if (mario->is_No_Gravity()) 
	{
		if (game->IsKeyDown(DIK_UP)) {
		mario->SetState(MARIO_STATE_WALK_UP);
		}
		else if (game->IsKeyDown(DIK_DOWN)) {
			mario->SetState(MARIO_STATE_WALK_DOWN);
		}

	}
	else
		mario->SetState(MARIO_STATE_IDLE);
}
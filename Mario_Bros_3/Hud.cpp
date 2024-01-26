#include "Hud.h"
#include "PlayScene.h"

Hud::Hud(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Hud::Update()
{

}

void Hud::Render()
{

	CGame::GetInstance()->GetCamPos(x, y);

	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_HUD)->Render(x , y );
}
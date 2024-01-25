#include "Hub.h"
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
	DebugOut(L"Render hud ne");

	CGame::GetInstance()->GetCamPos(x, y);

	CAnimations* animations = CAnimations::GetInstance();
}
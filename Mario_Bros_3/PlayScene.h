#pragma once
#include "Game.h"
#include "Textures.h"
#include "Scene.h"
#include "GameObject.h"
#include "Utils.h"
#include "Mario.h"
#include "camera.h"
#include "background.h"
//#include "Goomba.h"
//#include "Koopas.h"


class CPlayScene : public CScene
{
protected:
	// A play scene has to have player, right? 
	LPGAMEOBJECT player;
	

	

	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);

	void _ParseSection_ASSETS(string line);
	void _ParseSection_OBJECTS(string line);

	void LoadAssets(LPCWSTR assetFile);

public:
	vector<LPGAMEOBJECT> objects;
	vector<LPGAMEOBJECT> objects_NoCollision;
	vector<LPGAMEOBJECT> get_Objects() { return objects; }
	void set_Objects(LPGAMEOBJECT Object) {
		objects.push_back(Object);
	}
	CPlayScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();

	LPGAMEOBJECT GetPlayer() { return player; }
	

	void Clear();
	void PurgeDeletedObjects();

	static bool IsGameObjectDeleted(const LPGAMEOBJECT& o);
};

typedef CPlayScene* LPPLAYSCENE;


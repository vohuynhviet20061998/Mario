#pragma once

#include "GameObject.h"

class Background : public CGameObject {
private:
	static CTexture* _backgroundTexture;

	std::vector<std::pair<RECT, D3DXVECTOR2>> _activeSprites;
	std::vector<std::pair<RECT, D3DXVECTOR2>> _sprites;

	D3DXMATRIX _scaleMatrix;
	D3DX10_SPRITE _sprite;

	bool _IsInViewport(std::pair<RECT, D3DXVECTOR2>, RECTF);

	void _ScaleSprite(const RECT&);

public:
	Background(CTexture*&);
	~Background();

	void AddSprite(RECT, D3DXVECTOR2);

	void Update();
	void Render() override;
	
	void BruteForceRender();
	
	void GetBoundingBox(float& l, float& t, float& r, float& b);


	void Release() ;
};
#pragma once

#include "GameObject.h"
#include "Utils.h"


class Camera : public CGameObject {
private:
	static Camera* _cameraInstance ;

	unsigned int _cameraWidth, _cameraHeight;
	std::vector<float> _upVectors;
	std::vector<RECTF> _cameraBounds;

	Camera();
	~Camera();

	

public:

	static Camera* GetInstance() ;
	void SetCameraWidth(unsigned int);
	unsigned int GetCameraWidth() const;
	void SetCameraHeight(unsigned int);
	unsigned int GetCameraHeight() const;

	float GetUpVector(int = 0) const;
	void AddUpVector(float);

	RECTF GetViewport() const;
	RECTF GetCameraBound(int = 0) const;

	void Update(DWORD dt) {}
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void AddCameraBound(RECTF);
	

	void Update(DWORD, std::vector<CGameObject*>* = nullptr) override;

	void Release() ;
};
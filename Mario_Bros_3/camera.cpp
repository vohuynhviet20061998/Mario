#include "Utils.h"
#include "Camera.h"



Camera* Camera::_cameraInstance = nullptr;

Camera::Camera() {}

Camera::~Camera() {}

Camera* Camera::GetInstance() {
	if (_cameraInstance == nullptr) {
		_cameraInstance = new Camera;
	}
	return _cameraInstance;
}


void Camera::SetCameraWidth(unsigned int cameraWidth) {
	_cameraWidth = cameraWidth;
}

unsigned int Camera::GetCameraWidth() const {
	return _cameraWidth;
}

void Camera::SetCameraHeight(unsigned int cameraHeight) {
	_cameraHeight = cameraHeight;
}

unsigned int Camera::GetCameraHeight() const {
	return _cameraHeight;
}

float Camera::GetUpVector(int index) const {
	return _upVectors.at(index);
}

void Camera::AddUpVector(float upVector) {
	_upVectors.emplace_back(upVector);
}

RECTF Camera::GetViewport() const {
	const RECTF REGION_OFFSET(0.1f, 0.9f, 1.2f, 1.2f);

	RECTF viewport;
	viewport.left = this->x - GlobalUtil::SCREEN_WIDTH * REGION_OFFSET.left;
	viewport.top = this->y - GlobalUtil::SCREEN_HEIGHT * REGION_OFFSET.top;
	viewport.right =this->x+ GlobalUtil::SCREEN_WIDTH * REGION_OFFSET.right;
	viewport.bottom = this->y + GlobalUtil::SCREEN_HEIGHT * REGION_OFFSET.bottom;
	return viewport;
}

RECTF Camera::GetCameraBound(int index) const {
	return _cameraBounds.at(index);
}

void Camera::Render()
{
}

void Camera::GetBoundingBox(float& l, float& t, float& r, float& b)
{
}

void Camera::AddCameraBound(RECTF cameraBound) {
	_cameraBounds.emplace_back(cameraBound);
}

void Camera::Update(DWORD deltaTime, std::vector<CGameObject*>* collidableObjects) {
	this->y = 15.0f;
	this->vx = 0.035f;
	CGameObject::Update(deltaTime);

}

void Camera::Release() {
	_cameraBounds.clear();

}
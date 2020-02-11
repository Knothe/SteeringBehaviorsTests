#pragma once
#include "Platform.h"
#include "Image.h"

class ArriveAgent
{
public:
	ArriveAgent();
	void Update(MouseData* mouseData);
	void Draw();
	void Init();
	Vec2 GetPosition() {
		return position;
	}
private:
	Platform* platform;
	Vec2 position;
	Vec2 velocity;
	float maxSpeed;
	float slowDistance;
	float angle;
	Image texture;
	Vec2 objective;
};


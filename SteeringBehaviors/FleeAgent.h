#pragma once
#include "Vec2.h"
#include "Image.h"
#include "Platform.h"

class FleeAgent
{
public:
	FleeAgent();
	void Update(MouseData* mouseData);
	void Draw();
	void Init();

private:
	Platform* platform;
	Vec2 position;
	Vec2 velocity;
	float angle;
	float maxSpeed;
	float maxForce;
	Image texture;
};


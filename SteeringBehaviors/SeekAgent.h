#pragma once
#include "Vec2.h"
#include "Image.h"
#include "Platform.h"

class SeekAgent
{
public:
	SeekAgent();
	void Update(MouseData* mouseData);
	void Draw();
	void Init();
	Vec2 GetPosition();
	Vec2 GetVelocity();

private:
	Platform* platform;
	Vec2 position;
	Vec2 velocity;
	float angle;
	float maxSpeed;
	float maxForce;
	Image texture;
};


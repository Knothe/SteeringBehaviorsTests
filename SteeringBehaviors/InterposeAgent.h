#pragma once
#include "Vec2.h"
#include "Vector.h"
#include "Image.h"
#include "Platform.h"

class InterposeAgent
{
public:
	InterposeAgent();
	void Update(MouseData* mouseData, Vec2 pos2);
	void Draw();
	void Init();
private:
	Platform* platform;
	float maxSpeed;
	float maxForce;
	float speedReduce;
	float angle;
	Vec2 position;
	Vec2 velocity;
	Image texture;
	Vec2 Seek(Vec2 pointToSeek, Vec2 v);
};


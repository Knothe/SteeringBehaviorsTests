#pragma once
#include "Platform.h"
#include "Vec2.h"

class OffsetAgent
{
public:
	OffsetAgent();
	void Update(Vec2 pos, Vec2 vel);
	void Draw();
	void Init(Vec2 off, Vec2 pos);
private:
	Platform* platform;
	Vec2 position;
	Vec2 velocity;
	float angle;
	float maxSpeed;
	float maxForce;
	Vec2 offset;
	Image texture;
	Vec2 Seek(Vec2 pointToSeek, Vec2 v);
};


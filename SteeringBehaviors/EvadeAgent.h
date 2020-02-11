#pragma once
#include "Vec2.h"
#include "Image.h"
#include "Platform.h"

class EvadeAgent
{
public:
	EvadeAgent();
	void Update(Vec2 pos, Vec2 vel);
	void Draw();
	void Init();
	void RestartPosition();
private:
	Platform* platform;
	Vec2 position;
	Vec2 velocity;
	float angle;
	float maxSpeed;
	float maxForce;
	Image texture;
	Vec2 Seek(Vec2 pointToSeek, Vec2 v);
};


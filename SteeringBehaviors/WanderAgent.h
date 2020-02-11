#pragma once
#include "Vec2.h"
#include "Vector.h"
#include "Image.h"
#include "Platform.h"

class WanderAgent
{
public:
	WanderAgent();
	void Update(Vector<Vec2>* walls);
	void Draw();
	void Init();
private:
	Platform* platform;

	Vec2 position; 
	Vec2 velocity;
	int size;

	float maxSpeed;
	float maxForce;

	float wanderRadius;
	float wanderDistance;
	float angle;
	Vec2 nextCenter, nextObjective;

	Image texture;

	Vec2 Seek(Vec2 pointToSeek, Vec2 v);
	Vec2 CheckColision(Vec2 nextPoint, Vector<Vec2>* walls);
};


#pragma once
#include "Vec2.h"
#include "Vector.h"
#include "Image.h"
#include "Platform.h"

class PathAgent
{
public:
	PathAgent();
	void Update(Vector<Vec2>* path, float pathSize);
	void Draw();
	void Init();
private:
	Platform* platform;
	Vec2 position;
	Vec2 velocity;
	float maxSpeed;
	float maxForce;
	float viewAhead;
	float angle;
	Image texture;
	void CheckDistance(Vec2 p1, Vec2 p2, Vec2& projection, float pathSize);
	int point1, point2;
	Vec2 pointInLine, nextPosition;
	Vec2 Seek(Vec2 pointToSeek, Vec2 v);
};


#pragma once
#include "Vec2.h"
#include "Image.h"
#include "Platform.h"

struct Wall {
	Wall(Vec2 p1, Vec2 p2) : point1(p1), point2(p2) {
		wallVector = p1 - p2;
		d = wallVector.size();
	}
	Wall() {};
	Vec2 point1;
	Vec2 point2;
	Vec2 wallVector;
	float d;
};

class WallAgent
{
public:
	WallAgent();
	void Update(MouseData* mouseData, Vector<Wall>* walls);
	void Draw();
	void Init();

private:
	Platform* platform;
	Vec2 position;
	Vec2 velocity;
	Vec2 feelerPos;
	Vec2 feeler2;
	Vec2 feeler3;
	float angle;
	float maxSpeed;
	float maxForce;
	float feelerRange;
	float agentSize = 20;
	Image texture;
	Vec2 Seek(Vec2 pointToSeek, Vec2 v);
	Vec2 CheckWall(Wall w, Vec2 sensor);
};


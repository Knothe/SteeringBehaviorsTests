#pragma once
#include "Vec2.h"
#include "Image.h"
#include "Platform.h"
#include "Vector.h"

struct ObstacleValues {
	ObstacleValues(Vec2 pos, float s) : position(pos), scale(s) {

	}
	ObstacleValues() {
		position = Vec2(0, 0);
		scale = 1;
	}
	Vec2 position;
	float scale;
};

class CollisionAgent
{
public:
	CollisionAgent();
	void Update(MouseData* mouseData, Vector<ObstacleValues>* obstacles);
	void Draw();
	void Init();
private:
	Platform* platform;
	Vec2 position;
	Vec2 velocity;
	Vec2 p1, p2;
	float angle;
	float maxSpeed;
	float maxForce;
	float maxAvoidForce;
	float avoidRange;
	Image texture;
	Vec2 ApplyAvoidForce(Vector<ObstacleValues>* obstacles);
};


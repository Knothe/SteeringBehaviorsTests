#pragma once
#include "Vec2.h"
#include "Image.h"
#include "Platform.h"

struct Obstacle {
	Obstacle() {}
	Obstacle(Vec2 p, float s) : position(p), scale(s) {}
	Vec2 position;
	float scale;
};

class HideAgent
{
public:
	HideAgent();
	void Update(Vec2 hunterPosition, Vector<Obstacle>* obstacles);
	void Draw();
	void Init();
private:
	Platform* platform;
	Vec2 position;
	Vec2 velocity;
	Vec2 hidePoint;
	float angle;
	float maxSpeed;
	float maxForce;
	float arriveSize = 100;
	bool hiding = true;

	Image texture;
	Vec2 Seek(Vec2 pointToSeek, Vec2 v);
	bool WatchHunter(Vec2 hunterPosition, Vector<Obstacle>* obstacles);
	Vec2 HidePlaces(Vec2 hunterPosition, Vector<Obstacle>* obstacles);

};


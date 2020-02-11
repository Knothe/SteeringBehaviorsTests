#include "InterposeAgent.h"

InterposeAgent::InterposeAgent() {
	platform = Platform::GetPtr();
	position = Vec2(0, 0);
	maxSpeed = 3;
	speedReduce = 25;
	maxForce = .1f;
	angle = 0;
}

void InterposeAgent::Update(MouseData* mouseData, Vec2 pos2) {
	Vec2 middle = mouseData->position - pos2;
	middle = middle / 2;
	middle = pos2 + middle;
	velocity = Seek(middle, velocity);
	position = position + velocity;
	angle = velocity.GetAngle();
}

void InterposeAgent::Draw() {
	platform->RenderImage(&texture, position, angle);
}

void InterposeAgent::Init() {
	texture.LoadImage("ag");
}

Vec2 InterposeAgent::Seek(Vec2 pointToSeek, Vec2 v) {
	Vec2 desired = pointToSeek - position;
	float distance = desired.size();
	desired.SetSize(maxSpeed);
	Vec2 steering = desired - v;
	steering.Limit(maxForce);
	v = v + steering;
	distance = distance / speedReduce;
	if (distance > 1)
		v.Limit(maxSpeed);
	else
		v.Limit(maxSpeed * distance);
	return v;
}
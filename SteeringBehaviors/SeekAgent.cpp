#include "SeekAgent.h"

SeekAgent::SeekAgent() {
	platform = Platform::GetPtr();
	position = Vec2(0, 0);
	velocity = Vec2(1, 0);
	angle = 0;
	maxSpeed = 5;
	maxForce = .1f;
}

void SeekAgent::Update(MouseData* mouseData) {
	Vec2 desired = mouseData->position - position;
	desired.SetSize(maxSpeed);
	Vec2 steering = desired - velocity;
	steering.Limit(maxForce);
	velocity = velocity + steering;
	velocity.Limit(maxSpeed);
	angle = velocity.GetAngle();
	position = position + velocity;
}

void SeekAgent::Draw() {
	platform->RenderImage(&texture, position, angle);
}

void SeekAgent::Init() {
	texture.LoadImage("ag");
}

Vec2 SeekAgent::GetPosition() {
	return position;
}

Vec2 SeekAgent::GetVelocity() {
	return velocity;
}
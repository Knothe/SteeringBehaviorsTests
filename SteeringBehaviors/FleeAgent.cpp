#include "FleeAgent.h"

FleeAgent::FleeAgent() {
	platform = Platform::GetPtr();
	position = Vec2(500, 500);
	velocity = Vec2(1, 0);
	angle = 0;
	maxSpeed = 5;
	maxForce = .1f;
}

void FleeAgent::Update(MouseData* mouseData) {
	Vec2 desired = position - mouseData->position;
	desired.SetSize(maxSpeed);
	Vec2 steering = desired - velocity;
	steering.Limit(maxForce);
	velocity = velocity + steering;
	velocity.Limit(maxSpeed);
	angle = velocity.GetAngle();
	position = position + velocity;
}

void FleeAgent::Draw() {
	platform->RenderImage(&texture, position, angle);
}

void FleeAgent::Init() {
	texture.LoadImage("ag2");
}
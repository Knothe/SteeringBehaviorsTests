#include "EvadeAgent.h"

EvadeAgent::EvadeAgent() {
	platform = Platform::GetPtr();
	maxSpeed = 4;
	maxForce = .1f;
	RestartPosition();
}

void EvadeAgent::Update(Vec2 pos, Vec2 vel) {
	float T = (pos - position).size() / maxSpeed;
	Vec2 desired = pos + (vel * T);
	velocity = Seek(desired, velocity);
	position = position + velocity;
	angle = velocity.GetAngle();
}

void EvadeAgent::Draw() {
	platform->RenderImage(&texture, position, angle);
}

void EvadeAgent::Init() {
	texture.LoadImage("ag3");
}

void EvadeAgent::RestartPosition() {
	position = Vec2(432, 360);
	velocity = Vec2(0, 0);
	angle = 0;
}

Vec2 EvadeAgent::Seek(Vec2 pointToSeek, Vec2 v) {
	Vec2 desired = position - pointToSeek;
	desired.SetSize(maxSpeed);
	Vec2 steering = desired - v;
	steering.Limit(maxForce);
	v = v + steering;
	v.Limit(maxSpeed);
	return v;
}
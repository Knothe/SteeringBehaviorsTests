#include "PursuitAgent.h"

PursuitAgent::PursuitAgent() {
	platform = Platform::GetPtr();
	maxSpeed = 4;
	maxForce = .1f;
	RestartPosition();
}

void PursuitAgent::Update(Vec2 pos, Vec2 vel) {
	float T = (pos - position).size() / maxSpeed;
	Vec2 desired = pos + (vel * T);
	velocity = Seek(desired, velocity);
	position = position + velocity;
	angle = velocity.GetAngle();
}

void PursuitAgent::Draw() {
	platform->RenderImage(&texture, position, angle);

}

void PursuitAgent::Init() {
	texture.LoadImage("ag2");
}

void PursuitAgent::RestartPosition() {
	position = Vec2(0, 0);
	velocity = Vec2(0, 0);
	angle = 0;
}

Vec2 PursuitAgent::Seek(Vec2 pointToSeek, Vec2 v) {
	Vec2 desired = pointToSeek - position;
	desired.SetSize(maxSpeed);
	Vec2 steering = desired - v;
	steering.Limit(maxForce);
	v = v + steering;
	v.Limit(maxSpeed);
	return v;
}
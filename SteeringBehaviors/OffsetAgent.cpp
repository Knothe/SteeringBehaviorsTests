#include "OffsetAgent.h"

OffsetAgent::OffsetAgent(){
	platform = Platform::GetPtr();
	maxSpeed = 5;
	maxForce = .1f;
}

void OffsetAgent::Update(Vec2 pos, Vec2 vel) {
	float T = (pos - position).size() / maxSpeed;
	Vec2 desired = pos + (vel * 5) + offset.Rotate(pos.GetRadianAngle());
	velocity = Seek(desired, velocity);
	position = position + velocity;
	angle = velocity.GetAngle();
}

void OffsetAgent::Draw() {
	platform->RenderImage(&texture, position, angle);
}

void OffsetAgent::Init(Vec2 off, Vec2 pos) {
	texture.LoadImage("ag2");
	offset = off;
	position = pos;
}


Vec2 OffsetAgent::Seek(Vec2 pointToSeek, Vec2 v) {
	Vec2 desired = pointToSeek - position;
	desired.SetSize(maxSpeed);
	Vec2 steering = desired - v;
	steering.Limit(maxForce);
	v = v + steering;
	v.Limit(maxSpeed);
	return v;
}
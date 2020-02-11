#include "WallAgent.h"

WallAgent::WallAgent() {
	platform = Platform::GetPtr();
	position = Vec2(0, 0);
	angle = 0;
	maxSpeed = 5;
	maxForce = .2f;
	feelerRange = 80;
	feeler2 = Vec2(50, -50);
	feeler3 = Vec2(-50, -50);
}

void WallAgent::Update(MouseData* mouseData, Vector<Wall>* walls) {
	Vec2 v = Vec2(0, 0);
	Vec2 v1 = Vec2(0, 0);
	Vec2 v2 = Vec2(0, 0);
	Vec2 steering = Vec2(0, 0);
	for (int i = 0; i < walls->GetSize(); i++) {
		v1 = v1 + CheckWall(walls->GetAt(i), position + feeler2.Rotate(velocity.GetRadianAngle()));
		v2 = v2 + CheckWall(walls->GetAt(i), position + feeler3.Rotate(velocity.GetRadianAngle()));
		v = CheckWall(walls->GetAt(i), position + (velocity.normalize() * feelerRange));
		if (!(v == Vec2(0, 0))) {
			steering = steering + (v * 10);

		}
	}
	if (!(v1 == Vec2(0, 0) || !(v2 == Vec2(0, 0)))) {
		steering = steering + ((v1.Rotate(3.1416 / 2) + v2.Rotate(-3.1416 / 2)));
	}else if (steering == Vec2(0, 0)) {
		Vec2 desired = mouseData->position - position;
		desired.SetSize(maxSpeed);
		steering = desired - velocity;
	}
	
	steering = steering + v1 + v2;
	steering.Limit(maxForce);
	velocity = velocity + steering;
	velocity.Limit(maxSpeed);

	angle = velocity.GetAngle();
	position = position + velocity;
	std::cout << "(" << v.x << ", " << v.y << ")" << std::endl;
}

void WallAgent::Draw() {
	platform->RenderImage(&texture, position, angle);
	//platform->DrawLine(position, feelerPos);
	//platform->DrawLine(position, position + feeler2.Rotate(velocity.GetRadianAngle()));
	//platform->DrawLine(position, position + feeler3.Rotate(velocity.GetRadianAngle()));
}

void WallAgent::Init() {
	texture.LoadImage("ag");
}

Vec2 WallAgent::CheckWall(Wall w, Vec2 sensor) {
	feelerPos = sensor;
	Vec2 agentProjection, feelerProjection;
	
	Vec2 u = sensor - w.point2;
	float size = (u * w.wallVector) / (w.d * w.d);
	feelerProjection = (w.wallVector * size) + w.point2;
	feelerProjection = sensor - feelerProjection;
	feelerProjection.SetSize(feelerProjection.size() - agentSize);

	u = position - w.point2;
	size = (u * w.wallVector) / (w.d * w.d);
	if (size < 0 || size > 1) return Vec2(0, 0);
	agentProjection = (w.wallVector * size) + w.point2;
	agentProjection = position - agentProjection;

	if (agentProjection.normalize() == feelerProjection.normalize())
		return Vec2(0, 0);
	else
		return agentProjection;
}

Vec2 WallAgent::Seek(Vec2 pointToSeek, Vec2 v) {
	
	return v;
}
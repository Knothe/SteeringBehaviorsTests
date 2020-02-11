#include "WanderAgent.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

WanderAgent::WanderAgent() {
	platform = Platform::GetPtr();
	position = Vec2(432, 360);

	velocity = Vec2(0, -1);
	size = 48;
	maxSpeed = 3;
	maxForce = .05f;
	wanderRadius = 30;
	wanderDistance = 30;
}

void WanderAgent::Update(Vector<Vec2>* walls) {
	
	nextCenter = (velocity.normalize() * wanderDistance) + position;
	angle = (rand() % 628 + 0);
	angle = angle / 100;
	nextObjective = Vec2(cos(angle), sin(angle)) * wanderRadius;
	nextObjective = CheckColision(nextObjective, walls);

	velocity = Seek(nextObjective, velocity);
	position = position + velocity;
	angle = velocity.GetAngle();
}

void WanderAgent::Draw() {
	platform->RenderImage(&texture, position, angle);
	//platform->DrawLine(nextCenter, nextObjective);
}

void WanderAgent::Init() {
	texture.LoadImage("ag");	
}

Vec2 WanderAgent::Seek(Vec2 pointToSeek, Vec2 v) {
	Vec2 desired = pointToSeek - position;
	desired.SetSize(maxSpeed);
	Vec2 steering = desired - v;
	steering.Limit(maxForce);
	v = v + steering;
	v.Limit(maxSpeed);
	return v;
}

Vec2 WanderAgent::CheckColision(Vec2 nextPoint, Vector<Vec2>* walls) {
	Vec2 difference;
	Vec2 n = nextPoint + nextCenter;
	for (int i = 0; i < walls->GetSize(); i++) {
		difference = n - walls->GetAt(i);
		if (difference.size() <= size * 2)
			return position + difference;
	}
	return n;
}

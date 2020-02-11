#include "CollisionAgent.h"


CollisionAgent::CollisionAgent() {
	platform = Platform::GetPtr();
	position = Vec2(0, 0);
	velocity = Vec2(1, 0);
	angle = 0;
	maxSpeed = 4; 
	maxForce = .1f;
	maxAvoidForce = .25f;
	avoidRange = 100;
}

void CollisionAgent::Update(MouseData* mouseData, Vector<ObstacleValues>* obstacles) {
	Vec2 desired = mouseData->position - position;
	desired.SetSize(maxSpeed);
	Vec2 steering = desired - velocity;
	desired = ApplyAvoidForce(obstacles);

	if(desired == Vec2(0,0))
		steering.Limit(maxForce);
	else {
		steering = desired;
		steering.Limit(maxAvoidForce);
	}
	velocity = velocity + steering;
	velocity.Limit(maxSpeed);
	angle = velocity.GetAngle();
	position = position + velocity;
}

Vec2 CollisionAgent::ApplyAvoidForce(Vector<ObstacleValues>* obstacles) {
	float closest = 2, distance, closestObstacle = -1, obstacleSize;
	Vec2 v, u, closestPoint, t;
	float size = 16;
	ObstacleValues currentObstacle;
	v = velocity.normalize() * avoidRange;
	p1 = v + position;
	for (int i = 0; i < obstacles->GetSize(); i++) {
		currentObstacle = obstacles->GetAt(i);
		u = currentObstacle.position - position;
		distance = (u * v) / (avoidRange * avoidRange);
		if (distance <= 1 + ((currentObstacle.scale * 16)/ avoidRange) && distance >= 0) {
			t = (v * distance) - u;
			if (t.size() <= size + (currentObstacle.scale * 16)) {
				if (closest > distance) {
					std::cout << "Colision " << position.x  << std::endl;
					closest = distance;
					closestObstacle = i;
					closestPoint = t;
				}
			}
		}
	}
	if (closestObstacle == -1)
		return Vec2(0, 0);
	currentObstacle = obstacles->GetAt(closestObstacle);
	closest = 1 - closest;
	closestPoint = (closestPoint + position) - currentObstacle.position;
	closest = closest + (closestPoint.size() / (currentObstacle.scale * 16) + 16) + (velocity.size() / maxSpeed);
	closest = closest / 3;
	closestPoint = closestPoint.normalize();
	return closestPoint * (closest * maxAvoidForce);
}


void CollisionAgent::Draw() {
	platform->RenderImage(&texture, position, angle);
	platform->DrawLine(position, p1);
}

void CollisionAgent::Init() {
	texture.LoadImage("ag");
}

#include "PathAgent.h"

PathAgent::PathAgent() {
	platform = Platform::GetPtr();
	position = Vec2(100, 0);
	velocity = Vec2(1, 0);
	maxSpeed = 3;
	maxForce = .3f;
	viewAhead = 80;
	point1 = 0;
	point2 = 1;
	angle = 0;
}

void PathAgent::Update(Vector<Vec2>* path, float pathSize) {
	if (path->GetSize() < 2)
		return;
	nextPosition = position + (velocity.normalize() * viewAhead);
	CheckDistance(path->GetAt(point1), path->GetAt(point2), pointInLine, pathSize);
	velocity = Seek(pointInLine, velocity);
	position = position + velocity;
	angle = velocity.GetAngle();
	if (point1 >= path->GetSize())
		point1 = 0;
	if (point2 >= path->GetSize())
		point2 = 0;
}

Vec2 PathAgent::Seek(Vec2 pointToSeek, Vec2 v) {
	Vec2 desired = pointToSeek - position;
	desired.SetSize(maxSpeed);
	Vec2 steering = desired - v;
	steering.Limit(maxForce);
	v = v + steering;
	v.Limit(maxSpeed);
	return v;
}


void PathAgent::CheckDistance(Vec2 p1, Vec2 p2, Vec2& projection, float pathSize) {
	Vec2 v = p2 - p1;
	Vec2 u = nextPosition - p1;
	float sizeU = u.size();
	float sizeV = v.size();
	float d = (u * v) / sizeV;
	v = v.normalize();
	u = p1 + (v * d);
	if (d < 0)
		d = 0;
	if ((u - nextPosition).size() > pathSize || d > sizeV + pathSize) {
		d += viewAhead / 3;
		if (d >= sizeV) {
			point1++;
			point2++;
		}
		projection = p1 + (v.normalize() * d);
	}
	else 
		projection = nextPosition;
}

void PathAgent::Draw() {
	platform->RenderImage(&texture, position, angle);
	platform->DrawLine(position, nextPosition);
	platform->DrawLine(nextPosition, pointInLine);
}

void PathAgent::Init() {
	texture.LoadImage("ag");
}
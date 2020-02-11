#include "HideAgent.h"
HideAgent::HideAgent() {
	platform = Platform::GetPtr();
	position = Vec2(300, 300);
	velocity = Vec2(0, 0);
	maxSpeed = 4;
	maxForce = .2f;
}

void HideAgent::Update(Vec2 hunterPosition, Vector<Obstacle>* obstacles) {
	if (hiding && WatchHunter(hunterPosition, obstacles))
		hidePoint = HidePlaces(hunterPosition, obstacles);
	velocity = Seek(hidePoint, velocity);
	if(!hiding)
		position = velocity + position;
	angle = velocity.GetAngle();
}

void HideAgent::Draw() {
	platform->RenderImage(&texture, position, angle);
}

void HideAgent::Init() {
	texture.LoadImage("ag2");
}

Vec2 HideAgent::Seek(Vec2 pointToSeek, Vec2 v) {
	float distance;
	Vec2 desired = pointToSeek - position;
	distance = desired.size();
	distance = distance / arriveSize;
	Vec2 steering = desired - v;
	steering.Limit(maxForce);
	v = v + steering;
	if (distance > 1)
		v.SetSize(maxSpeed);
	else if (distance < .1f)
		hiding = true;
	else
		v.Limit(maxSpeed * distance);
	return v;
}

bool HideAgent::WatchHunter(Vec2 hunterPosition, Vector<Obstacle>* obstacles) {
	Vec2 v = hunterPosition - position;
	float vSize = v.size();
	Vec2 u, projection;
	for (int i = 0; i < obstacles->GetSize(); i++) {
		u = obstacles->GetAt(i).position - position;
		projection = v * ((u * v) / (vSize * vSize));
		projection = u - projection;
		if (projection.size() < (obstacles->GetAt(i).scale * 16)) {
			return false;
		}
	}
	hiding = false;
	return true;
}

Vec2 HideAgent::HidePlaces(Vec2 hunterPosition, Vector<Obstacle>* obstacles) {
	Vector<Vec2> hidePositions;
	Vec2 v;
	for (int i = 0; i < obstacles->GetSize(); i++) {
		v = obstacles->GetAt(i).position - hunterPosition;
		v.SetSize(v.size() + (16 * obstacles->GetAt(i).scale) + 16);
		hidePositions.PushBack(hunterPosition + v);
	}
	float temp, smallest = 1000;
	Vec2 small;
	for (int i = 0; i < hidePositions.GetSize(); i++) {
		v = hidePositions.GetAt(i) - position;
		temp = v.size();
		if (temp < smallest && temp > 100) {
			small = hidePositions.GetAt(i);

		}
	}
	return small;
}

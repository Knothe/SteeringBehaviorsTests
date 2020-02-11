#include "ArriveAgent.h"
ArriveAgent::ArriveAgent() {
	platform = Platform::GetPtr();
	position = Vec2(0, 0);
	velocity = Vec2(0, 0);
	maxSpeed = 5;
	slowDistance = 200;
	angle = 0;
	objective = Vec2(0, 0);
}

void ArriveAgent::Update(MouseData* mouseData) {
	float distance;
	if (mouseData->leftButton) {
		objective = mouseData->position;
	}
	velocity = objective - position;
	distance = velocity.size();
	distance = distance / slowDistance;
	if (distance > 1)
		velocity.Limit(maxSpeed);
	else
		velocity.Limit(maxSpeed * distance);
	angle = velocity.GetAngle();
	position = position + velocity;
}

void ArriveAgent::Draw(){
	platform->RenderImage(&texture, position, angle);

}

void ArriveAgent::Init() {
	texture.LoadImage("ag");
}
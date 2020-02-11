#pragma once
#include "State.h"
#include "CollisionAgent.h"

class CollisionAvoid : public State
{
public:
	CollisionAvoid();
	void Input() override;
	void Update() override;
	void Draw() override;
	void Init() override;
	void Close() override;
private:
	Platform* platform;
	CollisionAgent agent;
	MouseData mouseData;
	Vector<ObstacleValues> obstacles;
	Image obs;
};


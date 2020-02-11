#pragma once
#include "State.h"
#include "WallAgent.h"

class WallAvoid : public State
{
public:
	WallAvoid();
	void Input() override;
	void Update() override;
	void Draw() override;
	void Init() override;
	void Close() override;
private:
	Platform* platform;
	MouseData mouseData;
	WallAgent agent;
	Vector<Wall> walls;
};


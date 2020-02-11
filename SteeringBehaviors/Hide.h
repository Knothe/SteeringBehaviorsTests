#pragma once
#include "State.h"
#include "HideAgent.h"
#include "ArriveAgent.h"

class Hide : public State
{
public:
	Hide();
	void Input() override;
	void Update() override;
	void Draw() override;
	void Init() override;
	void Close() override;
private:
	Platform* platform;
	HideAgent agent2;
	ArriveAgent agent1;
	MouseData mouseData;
	Vector<Obstacle> obstacles;
	Image obstacle;
};


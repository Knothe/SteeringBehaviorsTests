#pragma once
#include "State.h"
#include "ArriveAgent.h"

class Arrive : public State
{
public:
	Arrive();
	void Input() override;
	void Update() override;
	void Draw() override;
	void Init() override;
	void Close() override;
	~Arrive();
private:
	Platform* platform;
	MouseData mouseData;
	ArriveAgent agent;
};


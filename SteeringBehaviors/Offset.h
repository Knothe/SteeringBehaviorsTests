#pragma once
#include "State.h"
#include "OffsetAgent.h"
#include "SeekAgent.h"


class Offset : public State
{
public:
	Offset();
	void Input() override;
	void Update() override;
	void Draw() override;
	void Init() override;
	void Close() override;
private:
	Platform* platform;
	SeekAgent agent1;
	OffsetAgent agent2;
	OffsetAgent agent3;
	MouseData mouseData;
};


#pragma once
#include "State.h"
#include "PursuitAgent.h"
#include "SeekAgent.h"
#include "EvadeAgent.h"

class Pursuit :	public State
{
public:
	Pursuit();
	void Input() override;
	void Update() override;
	void Draw() override;
	void Init() override;
	void Close() override;
private:
	Platform* platform;
	PursuitAgent agent1;
	SeekAgent agent2;
	MouseData mouseData;
	EvadeAgent agent3;
};


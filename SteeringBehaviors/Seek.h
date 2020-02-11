#pragma once
#include "State.h"
#include "AssetManager.h"
#include "SeekAgent.h"
#include "FleeAgent.h"

class Seek : public State
{
public:
	Seek();
	void Input() override;
	void Update() override;
	void Draw() override;
	void Init() override;
	void Close() override;
private:
	Platform* platform;
	MouseData mouseData;
	SeekAgent agent;
	FleeAgent agent2;
};
#pragma once
#include "State.h"
#include "AssetManager.h"
#include "InterposeAgent.h"

class Interpose : public State
{
public:
	Interpose();
	void Input() override;
	void Update() override;
	void Draw() override;
	void Init() override;
	void Close() override;
	~Interpose();
private:
	Platform* platform;
	MouseData mouseData;
	Vec2 secondPos;
	InterposeAgent agent;
};


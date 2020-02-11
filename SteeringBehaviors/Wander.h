#pragma once
#include "State.h"
#include "AssetManager.h"
#include "WanderAgent.h"

class Wander : public State
{
public:
	Wander();
	void Input() override;
	void Update() override;
	void Draw() override;
	void Init() override;
	void Close() override;
	~Wander();
private:
	Platform* platform;
	WanderAgent agent;
	Vector<Vec2> walls;
	Image wallTexture;
};


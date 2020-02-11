#pragma once
#include "State.h"
#include "AssetManager.h"
#include "PathAgent.h"

class FollowPath : public State
{
public:
	FollowPath();
	void Input() override;
	void Update() override;
	void Draw() override;
	void Init() override;
	void Close() override;
	~FollowPath();
private:
	Platform* platform;
	PathAgent agent;
	Vector<Vec2> path;
};


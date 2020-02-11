#pragma once
#include "State.h"
#include "AssetManager.h"
class Evade : public State
{
public:
	Evade();
	void Input() override;
	void Update() override;
	void Draw() override;
	void Init() override;
	void Close() override;
	~Evade();
private:
	Platform* platform;
	AssetManager* assetManager;
	MouseData mouseData;
	Vector<Vec2> mapPosition = Vector<Vec2>(10);
	Image wallTexture;
};


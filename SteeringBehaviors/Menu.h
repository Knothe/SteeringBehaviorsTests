#pragma once
#include "State.h"
#include "Button.h"

class Menu : public State
{
public:
	Menu();
	void Input() override;
	void Update() override;
	void Draw() override;
	void Init() override;
	void Close() override;
	~Menu();
private:
	Platform* platform;
	AssetManager* assetManager;
	MouseData mouseData;
	Button buttonList[12];
};


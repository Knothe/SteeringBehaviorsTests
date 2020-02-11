#pragma once
#include "State.h"
class Inicio : public State
{
public:
	Inicio();
	void Input();
	void Update();
	void Draw();
	void Init();
	void Close();
	~Inicio();
};


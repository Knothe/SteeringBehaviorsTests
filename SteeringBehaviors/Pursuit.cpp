#include "Pursuit.h"

Pursuit::Pursuit() {
	platform = Platform::GetPtr();
}

void Pursuit::Input() {
	mouseData.ResetClicks();
	Vector<int> input;
	platform->CheckEvent(&input, &mouseData);
	for (int i = 0; i < input.GetSize(); i++) {
		if (input.GetAt(i) == SDLK_ESCAPE)	state = false;
		if (input.GetAt(i) == SDLK_a) agent1.RestartPosition();
		if (input.GetAt(i) == SDLK_d) agent3.RestartPosition();
	}
}

void Pursuit::Update() {
	agent2.Update(&mouseData);
	agent1.Update(agent2.GetPosition(), agent2.GetVelocity());
	agent3.Update(agent2.GetPosition(), agent2.GetVelocity());
}

void Pursuit::Draw() {
	platform->RenderClear();
	agent1.Draw();
	agent2.Draw();
	agent3.Draw();
	platform->RenderPresent();
}

void Pursuit::Init() {
	agent1.Init();
	agent2.Init();
	agent3.Init();
}

void Pursuit::Close() {
	state = false;
}
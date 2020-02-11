#include "Offset.h"

Offset::Offset() {
	platform = Platform::GetPtr();
}

void Offset::Input() {
	mouseData.ResetClicks();
	Vector<int> input;
	platform->CheckEvent(&input, &mouseData);
	for (int i = 0; i < input.GetSize(); i++) {
		if (input.GetAt(i) == SDLK_ESCAPE)	state = false;
	}
}

void Offset::Update() {
	agent1.Update(&mouseData);
	agent2.Update(agent1.GetPosition(), agent1.GetVelocity());
	agent3.Update(agent1.GetPosition(), agent1.GetVelocity());
}

void Offset::Draw() {
	platform->RenderClear();
	agent1.Draw();
	agent2.Draw();
	agent3.Draw();
	platform->RenderPresent();
}

void Offset::Init() {
	agent1.Init();
	agent2.Init(Vec2(40, 50), Vec2(0, 0));
	agent3.Init(Vec2(-40, 50), Vec2(0, 0));
}

void Offset::Close() {
	state = false;
}
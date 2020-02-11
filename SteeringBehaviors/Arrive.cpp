#include "Arrive.h"

Arrive::Arrive() {
	platform = Platform::GetPtr();
}

void Arrive::Input() {
	mouseData.ResetClicks();
	Vector<int> input;
	platform->CheckEvent(&input, &mouseData);
	for (int i = 0; i < input.GetSize(); i++) {
		if (input.GetAt(i) == SDLK_ESCAPE)	state = false;
	}
}

void Arrive::Update() {
	agent.Update(&mouseData);
}

void Arrive::Draw() {
	platform->RenderClear();
	agent.Draw();
	platform->RenderPresent();
}

void Arrive::Init() {
	agent.Init();
}

void Arrive::Close() {
	state = false;
}

Arrive::~Arrive() {

}
#include "Seek.h"
/*
Starts Seek
*/
Seek::Seek() {
	platform = Platform::GetPtr();
}

void Seek::Input() {
	Vector<int> input;
	platform->CheckEvent(&input, &mouseData);
	for (int i = 0; i < input.GetSize(); i++) {
		if (input.GetAt(i) == SDLK_ESCAPE)	state = false;
	}
	mouseData.ResetClicks();

}

void Seek::Update() {
	agent.Update(&mouseData);
	agent2.Update(&mouseData);
}

void Seek::Draw() {
	platform->RenderClear();
	agent.Draw();
	agent2.Draw();
	platform->RenderPresent();
}

void Seek::Init() {
	agent.Init();
	agent2.Init();
}

void Seek::Close() {
	state = false;
}



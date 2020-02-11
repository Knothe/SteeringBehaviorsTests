#include "Interpose.h"

Interpose::Interpose() {
	platform = Platform::GetPtr();
	secondPos = Vec2(500, 500);
}

void Interpose::Input() {
	Vector<int> input;
	platform->CheckEvent(&input, &mouseData);
	for (int i = 0; i < input.GetSize(); i++) {
		if (input.GetAt(i) == SDLK_ESCAPE)	state = false;
		if (input.GetAt(i) == SDLK_w)	
			secondPos.y -= 10;
		if (input.GetAt(i) == SDLK_a)	
			secondPos.x -= 10;
		if (input.GetAt(i) == SDLK_s)	
			secondPos.y += 10;
		if (input.GetAt(i) == SDLK_d)	
			secondPos.x += 10;
	}
	mouseData.ResetClicks();
}

void Interpose::Update() {
	agent.Update(&mouseData, secondPos);
}

void Interpose::Draw() {
	platform->RenderClear();
	agent.Draw();
	platform->DrawLine(mouseData.position, secondPos);
	platform->RenderPresent();
}

void Interpose::Init() {
	agent.Init();
}

void Interpose::Close() {
	state = false;
}

Interpose::~Interpose() {

}
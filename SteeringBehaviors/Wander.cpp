#include "Wander.h"
Wander::Wander() {
	platform = Platform::GetPtr();
	for (int i = 0; i < 19; i++) {
		walls.PushBack(Vec2(i * 48 + 24, 0 + 24));
		walls.PushBack(Vec2(i * 48 + 24, 672 + 24));
	}
	for (int i = 1; i < 14; i++) {
		walls.PushBack(Vec2(0 + 24, i * 48 + 24));
		walls.PushBack(Vec2(816 + 24, i * 48 + 24));
	}

}

void Wander::Input() {
	Vector<int> input;
	platform->CheckEvent(&input);
	for (int i = 0; i < input.GetSize(); i++) {
		if (input.GetAt(i) == SDLK_ESCAPE)	state = false;
	}
}

void Wander::Update() {
	agent.Update(&walls);
}

void Wander::Draw() {
	platform->RenderClear();
	agent.Draw();
	for (int i = 0; i < walls.GetSize(); i++)
		platform->RenderImage(&wallTexture, walls.GetAt(i));
	platform->RenderPresent();
}

void Wander::Init() {
	agent.Init();
	wallTexture.LoadImage("wa");
}

void Wander::Close() {

}

Wander::~Wander() {

}
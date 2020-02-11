#include "WallAvoid.h"

WallAvoid::WallAvoid() {
	platform = Platform::GetPtr();
	walls.PushBack(Wall(Vec2(600, 0), Vec2(600, 500)));
	walls.PushBack(Wall(Vec2(100, 500), Vec2(400, 500)));
	//walls.PushBack(Wall(Vec2(500, 200), Vec2(700, 700)));
}

void WallAvoid::Input() {
	Vector<int> input;
	platform->CheckEvent(&input, &mouseData);
	for (int i = 0; i < input.GetSize(); i++) {
		if (input.GetAt(i) == SDLK_ESCAPE)	state = false;
	}
	mouseData.ResetClicks();
}

void WallAvoid::Update() {
	agent.Update(&mouseData, &walls);
}

void WallAvoid::Draw() {
	platform->RenderClear();
	agent.Draw();
	for (int i = 0; i < walls.GetSize(); i++)
		platform->DrawLine(walls.GetAt(i).point1, walls.GetAt(i).point2);
	platform->RenderPresent();
}

void WallAvoid::Init() {
	agent.Init();
}

void WallAvoid::Close() {

}
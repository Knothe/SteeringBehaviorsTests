#include "Hide.h"

Hide::Hide() {
	platform = Platform::GetPtr();
	obstacles.PushBack(Obstacle(Vec2(100, 100), 1));
	obstacles.PushBack(Obstacle(Vec2(400, 500), 3));
	obstacles.PushBack(Obstacle(Vec2(500, 200), 2));
	obstacles.PushBack(Obstacle(Vec2(200, 500), 2));
}

void Hide::Input() {
	mouseData.ResetClicks();
	Vector<int> input;
	platform->CheckEvent(&input, &mouseData);
	for (int i = 0; i < input.GetSize(); i++) {
		if (input.GetAt(i) == SDLK_ESCAPE)	state = false;
	}
}

void Hide::Update() {
	agent1.Update(&mouseData);
	agent2.Update(agent1.GetPosition(), &obstacles);
}

void Hide::Draw() {
	platform->RenderClear();
	for(int i = 0; i < obstacles.GetSize(); i++)
		platform->RenderImage(&obstacle, obstacles.GetAt(i).position, 0, obstacles.GetAt(i).scale);
	agent1.Draw();
	agent2.Draw();
	platform->RenderPresent();
}

void Hide::Init() {
	agent2.Init();
	agent1.Init();
	obstacle.LoadImage("wa");
}

void Hide::Close() {

}

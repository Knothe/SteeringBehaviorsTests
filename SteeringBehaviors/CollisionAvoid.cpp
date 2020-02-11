#include "CollisionAvoid.h"

CollisionAvoid::CollisionAvoid() {
	platform = Platform::GetPtr();
	obstacles.PushBack(ObstacleValues(Vec2(100, 100), 1));
	obstacles.PushBack(ObstacleValues(Vec2(100, 148), 1));
	obstacles.PushBack(ObstacleValues(Vec2(500, 500), 4));
	obstacles.PushBack(ObstacleValues(Vec2(500, 400), 4));
	obstacles.PushBack(ObstacleValues(Vec2(700, 100), 3));
}

void CollisionAvoid::Input() {
	mouseData.ResetClicks();
	Vector<int> input;
	platform->CheckEvent(&input, &mouseData);
	for (int i = 0; i < input.GetSize(); i++) {
		if (input.GetAt(i) == SDLK_ESCAPE)	state = false;
	}
}

void CollisionAvoid::Update() {
	agent.Update(&mouseData, &obstacles);
}

void CollisionAvoid::Draw() {
	platform->RenderClear();
	agent.Draw();
	for (int i = 0; i < obstacles.GetSize(); i++)
		platform->RenderImage(&obs, obstacles.GetAt(i).position, 0, obstacles.GetAt(i).scale);
	platform->RenderPresent();
}

void CollisionAvoid::Init() {
	agent.Init();
	obs.LoadImage("wa");
}

void CollisionAvoid::Close() {

}
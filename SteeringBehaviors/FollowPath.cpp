#include "FollowPath.h"
FollowPath::FollowPath() {
	platform = Platform::GetPtr();
	path.PushBack(Vec2(100, 50));
	path.PushBack(Vec2(100, 200));
	path.PushBack(Vec2(500, 50));
	path.PushBack(Vec2(500, 700));
}

void FollowPath::Input() {
	Vector<int> input;
	platform->CheckEvent(&input);
	for (int i = 0; i < input.GetSize(); i++) {
		if (input.GetAt(i) == SDLK_ESCAPE)	state = false;
	}
}

void FollowPath::Update() {
	agent.Update(&path, 10);
}

void FollowPath::Draw() {
	platform->RenderClear();
	agent.Draw();
	for (int i = 0; i < path.GetSize(); i++) {
		platform->DrawPoint(path.GetAt(i));
	}
	platform->RenderPresent();
}

void FollowPath::Init() {
	agent.Init();
}

void FollowPath::Close() {
	state = false;
}

FollowPath::~FollowPath() {

}
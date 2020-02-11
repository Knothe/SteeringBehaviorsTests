#include "Menu.h"
#include "Evade.h"
#include "Seek.h"
#include "Arrive.h"
#include "FollowPath.h"
#include "Interpose.h"
#include "Wander.h"
#include "Pursuit.h"
#include "Offset.h"
#include "CollisionAvoid.h"
#include "WallAvoid.h"
#include "Hide.h"

Menu::Menu() {
	platform = Platform::GetPtr();
	assetManager = AssetManager::getPtr();
	assetManager->AddTexture("Agent.png", "ag", 1);
	assetManager->AddTexture("Agent2.png", "ag2", 1);
	assetManager->AddTexture("Agent3.png", "ag3", 1);
	assetManager->AddTexture("wall.png", "wa", 1);

	assetManager->AddTexture("Seek.png", "seek", 1);
	assetManager->AddTexture("Evade.png", "evade", 1);
	assetManager->AddTexture("Arrive.png", "arrive", 1);
	assetManager->AddTexture("Flee.png", "flee", 1);
	assetManager->AddTexture("Interpose.png", "interpose", 1);
	assetManager->AddTexture("Obstacle.png", "obstacle", 1);
	assetManager->AddTexture("Offset.png", "offset", 1);
	assetManager->AddTexture("Path.png", "path", 1);
	assetManager->AddTexture("Pursuit.png", "pursuit", 1);
	assetManager->AddTexture("WallAvoid.png", "wallavoid", 1);
	assetManager->AddTexture("Wander.png", "wander", 1);
	assetManager->AddTexture("Hide.png", "hide", 1);
}

void Menu::Input() {
	Vector<int> input;
	platform->CheckEvent(&input, &mouseData);
	for (int i = 0; i < input.GetSize(); i++) 
		if (input.GetAt(i) == SDLK_ESCAPE)	state = false;
	if (buttonList[0].Update(&mouseData))
		GameManager::getPtr()->SetState(new Seek());
	else if (buttonList[3].Update(&mouseData))
		GameManager::getPtr()->SetState(new Seek());
	else if (buttonList[2].Update(&mouseData))
		GameManager::getPtr()->SetState(new Arrive());
	else if (buttonList[7].Update(&mouseData))
		GameManager::getPtr()->SetState(new FollowPath());
	else if (buttonList[4].Update(&mouseData))
		GameManager::getPtr()->SetState(new Interpose());
	else if (buttonList[10].Update(&mouseData))
		GameManager::getPtr()->SetState(new Wander());
	else if (buttonList[8].Update(&mouseData))
		GameManager::getPtr()->SetState(new Pursuit());
	else if (buttonList[1].Update(&mouseData))
		GameManager::getPtr()->SetState(new Pursuit());
	else if (buttonList[6].Update(&mouseData))
		GameManager::getPtr()->SetState(new Offset());
	else if (buttonList[5].Update(&mouseData))
		GameManager::getPtr()->SetState(new CollisionAvoid());
	else if (buttonList[9].Update(&mouseData))
		GameManager::getPtr()->SetState(new WallAvoid());
	else if (buttonList[11].Update(&mouseData))
		GameManager::getPtr()->SetState(new Hide());


	mouseData.ResetClicks();
}

void Menu::Update() {

}

void Menu::Draw() {
	platform->RenderClear();
	for (int i = 0; i < 12; i++)
		buttonList[i].Draw();
	
	platform->RenderPresent();
}

void Menu::Init() {
	buttonList[0].Init("seek", "seek", Vec2(24, 24));
	buttonList[1].Init("evade", "evade", Vec2(24, 114));
	buttonList[2].Init("arrive", "arrive", Vec2(24, 204));
	buttonList[3].Init("flee", "flee", Vec2(24, 294));
	buttonList[4].Init("interpose", "interpose", Vec2(24, 384));
	buttonList[5].Init("obstacle", "obstacle", Vec2(24, 474));

	buttonList[6].Init("offset", "offset", Vec2(400, 24));
	buttonList[7].Init("path", "path", Vec2(400, 114));
	buttonList[8].Init("pursuit", "pursuit", Vec2(400, 204));
	buttonList[9].Init("wallavoid", "wallavoid", Vec2(400, 294));
	buttonList[10].Init("wander", "wander", Vec2(400, 384));
	buttonList[11].Init("hide", "hide", Vec2(400, 474));
}

void Menu::Close() {

}

Menu::~Menu() {

}
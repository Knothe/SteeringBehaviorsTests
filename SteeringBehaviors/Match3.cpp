#include "GameManager.h"
#include "Menu.h"
#include "Seek.h"

int main() {
	GameManager* gameM;
	gameM = GameManager::getPtr();
	gameM->SetState(new Menu());
	gameM->GameLoop();
}

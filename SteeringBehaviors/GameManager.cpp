#include "GameManager.h"
GameManager* GameManager::ptr;
/*
Starts the gameManager
*/
GameManager::GameManager() {
	platform = Platform::GetPtr();
}
/*
@return pointer to this object
*/
GameManager* GameManager::getPtr() {
	if (!ptr)
		ptr = new GameManager();
	return ptr;
}
/*
Adds a new state to the stack
@param state: new State to add
*/
void GameManager::SetState(State* state) {
	state->Init();
	statesStack.Push(state);
}
/*
Executes the game loop while there are things in the stack
*/
void GameManager::GameLoop() {
	while (true) {
		try {
			if (statesStack.GetSize() == 0)
				throw 0;
			auto estado = statesStack.Top();
			estado->Input(); // Possible Modifications
			estado->Update();
			estado->Draw();
			if (!estado->GetState())
				ReleaseState();
		} catch (int e) {
			break;
		} catch (std::exception e) {
			std::cout << e.what() << std::endl;
		}
	}
}
/*
Takes a State out of the stack
*/
void GameManager::ReleaseState() {
	State* s = statesStack.Top();
	s->Close();
	statesStack.Pop();
}

GameManager::~GameManager() {

}
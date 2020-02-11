#ifndef _NODOG_H
#define _NODOG_H
#include "List.h"
#include "GameObject.h"

class GameObject;

class NodoG
{
public:
	GameObject* obj;
	bool visited;
	Vec2 position;
	List<NodoG*> list;
	Vector<NodoG*>* toDelete;


	NodoG(GameObject* o, Vec2 pos);
	NodoG(Vec2 pos);
	void SetNewObject(GameObject* o, Vec2 oldPos);
	bool CreateListObject();
	bool operator<(NodoG other);
};

#endif
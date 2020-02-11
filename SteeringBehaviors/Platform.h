#pragma once
#include <string>
#include <iostream>
#include <SDL.h>
#undef main
#include "SDL_image.h"
#include "Vector.h"
#include "MouseData.h"
#include "Vec2.h"
#include "Image.h"


class Platform
{
private: 
	int width;
	int height;
	int scale;
	SDL_Window* window;
	
	Platform();
	static Platform* ptr;

	Uint16 frameTime;
	void RenderTexture(Image* image, float x, float y, int frame, float angle, float s);
	void ReadInit();
public:
	static SDL_Renderer* renderer;
	void RenderClear();
	void RenderPresent();
	void RenderImage(Image* image, int x, int y);
	void RenderImage(Image* image, Vec2 pos);
	void RenderImage(Image* image, Vec2 pos, float angle);
	void RenderImage(Image* image, Vec2 pos, float angle, float s);
	void DrawRect(int x, int y, int w, int h);
	void DrawPoint(Vec2 v);
	void DrawLine(Vec2 v1, Vec2 v2);
	void CheckEvent(Vector<int>* keysDown, MouseData* mouseData);
	void CheckEvent(Vector<int>* keysDown);
	void CheckEvent(MouseData* mouseData);
	static Platform* GetPtr();
	int GetScale();
	Uint16 GetFrameTime();
	Vec2 GetSize();
	int GetWitdth();
	int GetHeight();
	~Platform();
};


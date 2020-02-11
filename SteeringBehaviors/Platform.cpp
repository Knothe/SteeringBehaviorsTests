#include "Platform.h"
#include "SDL_ttf.h"
#include "StackAllocator.h"
#include <iostream>
#include <fstream>

using std::ifstream;

Platform* Platform::ptr;
SDL_Renderer* Platform::renderer;
/*
If the object isn't started, starts it
@return this pointer
*/
Platform* Platform::GetPtr() {
	if (!ptr) {
		//void* buf = StackAllocator::GetPtr()->alloc(sizeof(Platform));
		ptr = new Platform();
	}
	return ptr;
}
/*
Sets up the Window
*/
Platform::Platform()  {
	std::string name = "Match3";
	ReadInit();
	scale = 2;
	frameTime = 70; // 1000 = 1 seg

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
		std::cout << "SDL_INIT";
		return;
	}
	
	window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		std::cout << "CreateWindow";
		SDL_Quit();
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		std::cout << "CreateRenderer";
		SDL_Quit();
		return;
	}

}

void Platform::ReadInit() {
	ifstream file;
	/*file.open("matchEngine.ini", std::ios::out);
	if (!file.fail()) {
		file >> width >> height;
	}
	else {
		std::cout << ".ini file not found" << std::endl;
		std::cout << "Starting with default values" << std::endl;
		width = 864;
		height = 640;
	}
	file.close();*/
	width = 864; // 18
	height = 720; // 13
	std::cout << "Width: " << width << std::endl;
	std::cout << "Height: " << height << std::endl;
}

/*
Draws an empty rectangle
@param x: position in x
@param y: position in y
@param w: width of the rect
@param h: height of the rect
*/
void Platform::DrawRect(int x, int y, int w, int h) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawRect(renderer, &rect);
}
/*
Draws a point on screen
@param v: position
*/
void Platform::DrawPoint(Vec2 v){
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawPoint(renderer, v.x, v.y);
}

void Platform::DrawLine(Vec2 v1, Vec2 v2) {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLine(renderer, v1.x, v1.y, v2.x, v2.y);
}


/*
Clears the Screen
*/
void Platform::RenderClear() {
	SDL_SetRenderDrawColor(renderer, 9, 0, 0, 255);
	SDL_RenderClear(renderer);
}
/*
Presents everything rendered on screen
*/
void Platform::RenderPresent() {
	SDL_RenderPresent(renderer);
}
/*
Translates data for RenderTexture
@param image: pointer to image to render
@param x: position in x
@param y: position in y
*/
void Platform::RenderImage(Image* image, int x, int y) {
	RenderTexture(image, x, y, image->GetFrame(), 0, 1);
}
/*
Translates data for RenderTexture
@param image: pointer to image to render
@param pos: position
*/
void Platform::RenderImage(Image* image, Vec2 pos) {
	RenderTexture(image, pos.x, pos.y, image->GetFrame(), 0, 1);
}
/*
Translates data for RenderTexture
@param image: pointer to image to render
@param pos: position
@param angle: angle of rotation
*/
void Platform::RenderImage(Image* image, Vec2 pos, float angle) {
	RenderTexture(image, pos.x, pos.y, image->GetFrame(), angle, 1);
}

void Platform::RenderImage(Image* image, Vec2 pos, float angle, float s) {
	RenderTexture(image, pos.x, pos.y, image->GetFrame(), angle, s);
}
/*
Translates data for RenderTexture
@param image: pointer to image to render
@param pos: position
@param frame: frame to draw
*/
//void Platform::RenderImage(Image* image, Vec2 pos, int frame) {
//	RenderTexture(image, pos.x, pos.y, frame, 0);
//}
/*
Renders the texture with RenderCopyEx
@param image: pointer to image to render
@param x: position in x
@param y: position in y
@param frame: frame to draw
*/
void Platform::RenderTexture(Image* image, float x, float y, int frame, float angle, float s) {
	SDL_Point p;
	p.x = 8 * scale * s;
	p.y = 8 * scale * s;
	SDL_Rect dstrect;
	dstrect.x = x - p.x;
	dstrect.y = y - p.y;
	dstrect.w = image->GetWidth() * scale * s;
	dstrect.h = image->GetHeight() * scale * s;
	SDL_Rect srcrect;
	srcrect.x = frame * image->GetWidth();
	srcrect.y = 0;
	srcrect.w = image->GetWidth();
	srcrect.h = image->GetHeight();
	SDL_RenderCopyEx(renderer, image->GetTexture(), &srcrect, &dstrect, angle, &p, SDL_FLIP_NONE);
}
/*
Checks Event for keyboard and mouse
@param keysDown: pointer for vector for all the keys pressed
@param keysDown: pointer for vector for all the keys up
@param mouseData: pointer to mouse data
*/
void Platform::CheckEvent(Vector<int>* keysDown, MouseData* mouseData) {
	mouseData->ResetClicks();
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_KEYDOWN:
			if (e.key.keysym.sym == SDLK_p) keysDown->PushBack(SDLK_p);
			if (e.key.keysym.sym == SDLK_ESCAPE) keysDown->PushBack(SDLK_ESCAPE);
			if (e.key.keysym.sym == SDLK_w) keysDown->PushBack(SDLK_w);
			if (e.key.keysym.sym == SDLK_a) keysDown->PushBack(SDLK_a);
			if (e.key.keysym.sym == SDLK_s) keysDown->PushBack(SDLK_s);
			if (e.key.keysym.sym == SDLK_d) keysDown->PushBack(SDLK_d);
			break;
		case SDL_MOUSEMOTION:
			mouseData->position.x = e.motion.x;
			mouseData->position.y = e.motion.y;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (e.button.button == SDL_BUTTON_LEFT)		mouseData->leftButton = true;
			if (e.button.button == SDL_BUTTON_RIGHT)	mouseData->rightButton = true;
			break;
		}
	}
}
/*
Checks keyboard events
@param keysDown: pointer for vector for all the keys pressed
*/

void Platform::CheckEvent(Vector<int>* keysDown) {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if(e.type == SDL_KEYDOWN)
			if (e.key.keysym.sym == SDLK_p) keysDown->PushBack(SDLK_p);
			if (e.key.keysym.sym == SDLK_ESCAPE) keysDown->PushBack(SDLK_ESCAPE);
	}
}
/*
Checks Event for mose
@param mouseData: pointer to mouse data
*/
void Platform::CheckEvent(MouseData* mouseData) {
	SDL_Event e;
	mouseData->ResetClicks();
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_MOUSEMOTION:
			mouseData->position.x = e.motion.x;
			mouseData->position.y = e.motion.y;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (e.button.button == SDL_BUTTON_LEFT)		mouseData->leftButton = true;
			if (e.button.button == SDL_BUTTON_RIGHT)	mouseData->rightButton = true;
			break;
		case SDL_MOUSEBUTTONUP:
			if (e.button.button == SDL_BUTTON_LEFT)		mouseData->leftButton = false;
			if (e.button.button == SDL_BUTTON_RIGHT)	mouseData->rightButton = false;
		}
	}
}
/*
@return scale for every image
*/
int Platform::GetScale() {
	return scale;
}
/*
@return time each frame draws
*/
Uint16 Platform::GetFrameTime() {
	return frameTime;
}
/*
@return size of the screen
*/
Vec2 Platform::GetSize() {
	return Vec2(width, height);
}
/*
@return width of the screen
*/
int Platform::GetWitdth() {
	return width;
}
/*
@return height of the screen
*/
int Platform::GetHeight() {
	return height;
}

Platform::~Platform() {

}
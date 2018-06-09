#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Box2D\Box2D.h"
#include <iostream>

class Sprite
{
public:
	Sprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h);
	Sprite(SDL_Renderer* passed_renderer, std::string FilePath, int x, int y, int w, int h, int framesX, int framesY);
	~Sprite(void);

	SDL_Rect rect;

	void Draw();
	void Draw(int x, int y);
	void Draw(b2Vec2 newPos);
	void Draw(b2Vec2 newPos, float angle);
	void DrawAnimation(b2Vec2 newPos, float angle);
	void PlayAnimation(int BeginFrame, int EndFrame, float Speed);
	void DrawSling(b2Vec2 birdPos, b2Vec2 slingPos, double angle);

private:
	SDL_Texture* image;
	
	SDL_Rect crop;

	int image_width;
	int image_height;

	int currentframe;
	int animationdelay;

	int Frame_Amount_X;
	int Frame_Amount_Y;

	SDL_Renderer* renderer;
};


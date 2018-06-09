#pragma once
#include "SDL.h"
#include "SDL_mixer.h"

class CSDL_Setup
{
public:
	CSDL_Setup(bool* quit, int ScreenWidth, int SCreenHeight);
	~CSDL_Setup();

	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();

	Mix_Music* bgm;
	Mix_Chunk* rubberband;
	Mix_Chunk* pigcollide;
	Mix_Chunk* birdflying;
	Mix_Chunk* levelstart;
	Mix_Chunk* levelfailed;
	Mix_Chunk* levelvictory;
	Mix_Chunk* levelcomplete;


	void Begin();
	void End();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;
};


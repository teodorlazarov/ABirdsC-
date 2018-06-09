#pragma once
#include "CSDL_Setup.h"
#include "Sprite.h"
#include "Birds.h"
#include "Pigs.h"
#include "PigWalls.h"

#undef main

class Game
{
public:
	Game(int passed_ScreenWidth, int passed_ScreenHeight);
	~Game();
	void GameLoop();

private:
	enum GameState {
		MainMenu,
		Level1,
		Level2,
		Level3,
		EndGame
	};

	int ScreenWidth;
	int ScreenHeight;
	Uint32 starting_tick;
	Uint32 pigScoreStart_tick;
	Uint32 startWaitForLoadLevel;
	bool quit;
	bool isButtonDown = false;
	bool isBirdFlying = false;
	bool loadNextBird = false;
	bool isNextLevel = true;
	bool isMenuImageLoaded = false;
	bool isGameOver = false;
	bool restrictUserInput = false;
	bool isScoreStored = false;
	bool startGame = false;
	bool isLevelLoaded = false;

	int worldbodycount = 0;
	int currentLvl = 0;
	int currentBird = 0;
	int maxBirds = NULL;
	int maxPigs = NULL;
	int pigsKilled = 0;

	int userDataDead = 4;
	int userDataPigDying = 6;


	int score = 0;

	void cap_framerate(Uint32 starting_tick);
	void drawWithPhysics(b2Body* currBody, Sprite* currSprite, float xCorrection, float yCorrection);
	void drawWithPhysicsAndAnim(b2Body* currBody, Sprite* currSprite, float xCorrection, float yCorrection);
	void drawSlingshot(b2Body* birdBody, b2Body* slingbody, Sprite* rubberband);
	void drawLeftSlingshot(b2Body* birdBody, Sprite* leftSprite, Sprite* rubberband);
	void drawMenu();
	void resetLevel();
	void prepForNextLevel();
	void loadNextLevel();
	void drawLevel();
	void loadFromFile();
	void DrawScore();
	void getScoreVector();
	


	Sprite* background;
	Sprite* exitButton;
	Sprite* playButton;
	Sprite* replayButton;
	Sprite* nextLevelButton;
	Sprite* ground;
	Sprite* slingshotA;
	Sprite* slingshotB;
	Sprite* rubberA;
	Sprite* rubberB;
	Sprite* gameOver;
	Sprite* piggyShot;
	CSDL_Setup* csdl_setup;

	BoxPhysics* physics;

	b2Vec2 pigtemp;

	GameState gameState;

	std::vector<Pigs*> pigObj;
	std::vector<Birds*> birdObj;
	std::vector<PigWalls*> pigWallObj;
	std::vector<Sprite*> scoreVector;
	std::vector<int> scoreDigits;
};


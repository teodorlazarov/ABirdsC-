#pragma once
#include "BoxPhysics.h"
#include "CSDL_Setup.h"
#include "Sprite.h"

class PigWalls
{
public:
	PigWalls(b2World & world, CSDL_Setup* csdl_setup, int xpos, int ypos, int width, int height );
	~PigWalls();

	int m_h;
	int m_w;


	int pigWallUserData = 5;

	b2Body* m_pigWallBody;
	Sprite* m_pigWallSprite;

private:
	void createPigWall(b2World& world, int xpos, int ypos);
};


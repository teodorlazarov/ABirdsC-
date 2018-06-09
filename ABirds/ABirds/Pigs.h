#pragma once
#include "BoxPhysics.h"
#include "CSDL_Setup.h"
#include "Sprite.h"

class Pigs : BoxPhysics
{
public:
	Pigs(b2World& world, CSDL_Setup* csdl_setup, int xpos, int ypos);
	~Pigs();

	b2Body* m_pigBody;
	Sprite* m_pigIdleAnimation;
	Sprite* m_pigDeathAnimation;

	int pigUserData = 2;

	int m_beginFrame[2];
	int m_endFrame[2];
	int m_speed[2];

private:
	std::string filename[2];
	int m_framesX[2];
	int m_framesY[2];
	int animCounter = 0;

	void createPig(b2World& world, int xpos, int ypos);
	void readAnimationData();
};


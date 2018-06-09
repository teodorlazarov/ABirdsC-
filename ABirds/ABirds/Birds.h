#pragma once
#include "BoxPhysics.h"
#include "CSDL_Setup.h"
#include "Sprite.h"


class Birds
{
public:
	Birds(b2World& world, CSDL_Setup* csdl_setup, int xpos, int ypos);
	~Birds();

	int birdUserData = 1;

	b2Body* m_birdBody;
	Sprite* m_birdSprite;
	Sprite* m_birdSpriteAnimation;

	
	int m_beginFrame;
	int m_endFrame;
	int m_speed;

private: 
	std::string filename;
	int m_framesX;
	int m_framesY;

	void createBird(b2World& world, int xpos, int ypos);
	void readAnimationData();
};


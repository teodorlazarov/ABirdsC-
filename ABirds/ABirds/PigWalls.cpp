#include "PigWalls.h"



PigWalls::PigWalls(b2World & world, CSDL_Setup* csdl_setup, int xpos, int ypos, int width, int height)
{
	m_w = width;
	m_h = height;
	
	createPigWall(world, xpos, ypos);
	m_pigWallSprite = new Sprite(csdl_setup->GetRenderer(), "images/PigWall.png", 500, 500, width, height);
}


PigWalls::~PigWalls()
{
	delete m_pigWallSprite;
}

void PigWalls::createPigWall(b2World & world, int xpos, int ypos)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(xpos * P2M, ypos * P2M);

	m_pigWallBody = world.CreateBody(&bodyDef);
	m_pigWallBody->SetUserData(&pigWallUserData);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(P2M * m_w, P2M * m_h);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	fixtureDef.restitution = 0.0f;
	m_pigWallBody->CreateFixture(&fixtureDef);
}

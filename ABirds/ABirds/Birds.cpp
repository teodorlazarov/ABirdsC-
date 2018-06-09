#include "Birds.h"
#include <fstream>
#include <sstream>


Birds::Birds(b2World& world, CSDL_Setup* csdl_setup, int xpos, int ypos)
{
	readAnimationData();
	createBird(world, xpos, ypos);
	m_birdSprite = new Sprite(csdl_setup->GetRenderer(), "images/newbird.png", xpos, ypos, 25, 25);
	m_birdSpriteAnimation = new Sprite(csdl_setup->GetRenderer(), filename, xpos, ypos, 25, 25, m_framesX, m_framesY);
}


Birds::~Birds()
{
	delete m_birdSprite;
	delete m_birdSpriteAnimation;
}

void Birds::createBird(b2World & world, int xpos, int ypos)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(xpos * P2M, ypos * P2M);
	m_birdBody = world.CreateBody(&bodyDef);
	m_birdBody->SetAngularDamping(8.0f);
	m_birdBody->SetUserData(&birdUserData);

	b2CircleShape circleShape;
	circleShape.m_p.Set(0, 0);
	circleShape.m_radius = 25 * P2M;
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circleShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	fixtureDef.restitution = 0.1f;
	m_birdBody->CreateFixture(&fixtureDef);
}


void Birds::readAnimationData()
{
	std::ifstream loadedFile("config/birdAnim.txt");
	std::string line;

	enum ObjectType
	{
		TypeNone,
		TypeAnim
	};

	int currentType = TypeNone;

	if (loadedFile.is_open()) {
		while (loadedFile.good()) {
			std::getline(loadedFile, line);

			if (line == "---===Begin_Anim===---") {
				currentType = TypeAnim;
			}
			else if (line == "---===End_Anim===---") {
				currentType = TypeNone;
			}
			else {
				if (currentType == TypeAnim) {
					std::istringstream iss(line);
					while (iss) {
						std::string word;
						iss >> word;
						if (word == "file:") {
							iss >> filename;
						}
						if (word == "framesX:") {
							iss >> m_framesX;
						}
						if (word == "framesY:") {
							iss >> m_framesY;
						}
						if (word == "beginFrame:") {
							iss >> m_beginFrame;
						}
						if (word == "endFrame:") {
							iss >> m_endFrame;
						}
						if (word == "speed:") {
							iss >> m_speed;
						}
					}
				}
			}
		}
	}
}

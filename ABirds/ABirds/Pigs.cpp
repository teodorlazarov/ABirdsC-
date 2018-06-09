#include "Pigs.h"
#include <fstream>
#include <sstream>

Pigs::Pigs(b2World& world, CSDL_Setup* csdl_setup, int xpos, int ypos)
{
	createPig(world, xpos, ypos);
	readAnimationData();
	m_pigIdleAnimation = new Sprite(csdl_setup->GetRenderer(), filename[0], xpos, ypos, 25, 25, m_framesX[0], m_framesY[0]);
	m_pigDeathAnimation = new Sprite(csdl_setup->GetRenderer(), filename[1], xpos, ypos, 25, 25, m_framesX[1], m_framesY[1]);
}


Pigs::~Pigs()
{
	delete m_pigIdleAnimation;
	delete m_pigDeathAnimation;
}

void Pigs::createPig(b2World& world, int xpos, int ypos)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(xpos * P2M, ypos * P2M);
	m_pigBody = world.CreateBody(&bodyDef);
	m_pigBody->SetAngularDamping(5.0f);
	m_pigBody->SetUserData(&pigUserData);

	b2CircleShape circleShape;
	circleShape.m_p.Set(0, 0);
	circleShape.m_radius = 25 * P2M;
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circleShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	fixtureDef.restitution = 0.0f;
	m_pigBody->CreateFixture(&fixtureDef);
}

void Pigs::readAnimationData()
{
	std::ifstream loadedFile("config/pigAnim.txt");
	std::string line;

	enum ObjectType
	{
		TypeNone,
		TypeIdle,
		TypeDeath
	};

	int currentType = TypeNone;

	if (loadedFile.is_open()) {
		while (loadedFile.good()) {
			std::getline(loadedFile, line);

			if (line == "---===Begin_Idle===---") {
				currentType = TypeIdle;
			}
			else if (line == "---===End_Idle===---") {
				currentType = TypeNone;
			}
			if (line == "---===Begin_Death===---") {
				animCounter++;
				currentType = TypeDeath;
			}
			else if (line == "---===End_Death===---") {
				currentType = TypeNone;
			}

			else {
				if (currentType == TypeIdle) {
					std::istringstream iss(line);
					while (iss) {
						std::string word;
						iss >> word;
						if (word == "file:") {
							iss >> filename[animCounter];
						}
						if (word == "framesX:") {
							iss >> m_framesX[animCounter];
						}
						if (word == "framesY:") {
							iss >> m_framesY[animCounter];
						}
						if (word == "beginFrame:") {
							iss >> m_beginFrame[animCounter];
						}
						if (word == "endFrame:") {
							iss >> m_endFrame[animCounter];
						}
						if (word == "speed:") {
							iss >> m_speed[animCounter];
						}
					}					
				}
				else if (currentType == TypeDeath) {
					std::istringstream iss(line);
					while (iss) {
						std::string word;
						iss >> word;
						if (word == "file:") {
							iss >> filename[animCounter];
						}
						if (word == "framesX:") {
							iss >> m_framesX[animCounter];
						}
						if (word == "framesY:") {
							iss >> m_framesY[animCounter];
						}
						if (word == "beginFrame:") {
							iss >> m_beginFrame[animCounter];
						}
						if (word == "endFrame:") {
							iss >> m_endFrame[animCounter];
						}
						if (word == "speed:") {
							iss >> m_speed[animCounter];
						}
					}
				}
			}
		}
	}
}

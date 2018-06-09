#pragma once
#include "Box2D\Box2D.h"
#include <vector>
#include "myContactListener.h"

const float M2P = 100;
const float P2M = 1 / M2P;
const float DEGTORAD =  0.0174532925199432957f;
const float RADTODEG = 57.295779513082320876f;


class BoxPhysics
{
public:
	BoxPhysics();
	~BoxPhysics();

	b2World* world;


	b2Body* slingshotBody;
	b2Body *boundries[4];
	b2RopeJoint* ropeJoint;

	int numOfWalls = 0;

	int slingshotUserData = 3;
	int wallUserData = 6;


	void createslingshotBody();
	void createEdge(b2Body *body, float xpos, float ypos, float x1, float y1, float x2, float y2);
	void createRopeJoint(b2Body* body1, b2Body* body2);
};


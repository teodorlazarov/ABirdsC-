#include "BoxPhysics.h"

myContactListener myContactListenerInstance;

BoxPhysics::BoxPhysics()
{
	b2Vec2 gravity(0.0f, 9.8f);
	world = new b2World(gravity);

	world->SetContactListener(&myContactListenerInstance);

	//Creates bottom, left, right and top edges
	createEdge(boundries[0], 0, 675, 0, 0, 1600, 0);
	createEdge(boundries[1], -25, 0, 0, 0, 0, 700);
	createEdge(boundries[2], 1575, 0, 0, 0, 0, 700);
	createEdge(boundries[3], 0, 0, 0, 0, 1600, 0);
	
	createslingshotBody();
}


BoxPhysics::~BoxPhysics()
{
	
}

void BoxPhysics::createEdge(b2Body *body, float xpos, float ypos, float x1, float y1, float x2, float y2) {
	b2BodyDef edgeDef;
	edgeDef.type = b2_staticBody;
	edgeDef.position.Set(xpos * P2M, ypos * P2M);
	body = world->CreateBody(&edgeDef);
	body->SetUserData(&wallUserData);

	b2EdgeShape edgeShape;
	edgeShape.Set(b2Vec2(x1 * P2M, y1 * P2M), b2Vec2(x2 * P2M, y2 * P2M));

	body->CreateFixture(&edgeShape, 0.0f);
	
}

void BoxPhysics::createslingshotBody()
{
	b2BodyDef middleWallDef;
	middleWallDef.type = b2_staticBody;
	middleWallDef.position.Set(500 * P2M, 500 * P2M);
	slingshotBody = world->CreateBody(&middleWallDef);
	slingshotBody->SetUserData(&slingshotUserData);

	b2PolygonShape staticBody;
	staticBody.SetAsBox(P2M * 25, P2M * 25);
	b2FixtureDef sfixtureDef;
	sfixtureDef.filter.maskBits = 0x0000;
	sfixtureDef.shape = &staticBody;
	sfixtureDef.density = 1.0f;
	slingshotBody->CreateFixture(&sfixtureDef);
}

void BoxPhysics::createRopeJoint(b2Body* body1, b2Body* body2)
{
	b2RopeJointDef ropeDef;
	ropeDef.bodyA = body1;
	ropeDef.bodyB = body2;
	ropeDef.maxLength = 0.5f * P2M;
	ropeDef.collideConnected = true;
	ropeDef.localAnchorA.Set(0.0f, 0.0f);
	ropeDef.localAnchorB.Set(-0.2f, 0.0f);
	ropeJoint = (b2RopeJoint*) (world->CreateJoint(&ropeDef));
}

#include "myContactListener.h"
#include "CSDL_Setup.h"

myContactListener::myContactListener()
{
}

myContactListener::~myContactListener()
{
}

void myContactListener::BeginContact(b2Contact * contact)
{

}

void myContactListener::PostSolve(b2Contact * contact, const b2ContactImpulse * impulse)
{
	if (contact->GetFixtureA() != NULL && contact->GetFixtureA()->GetBody()->GetUserData() != NULL && *(int*)contact->GetFixtureA()->GetBody()->GetUserData() == 2) {
		if (*impulse->normalImpulses > 0.5f) {
			std::cout << "bird x pig" << std::endl;
			contact->GetFixtureA()->GetBody()->SetUserData(&pigIsDying);
		}
	}


	if (contact->GetFixtureB() != NULL && contact->GetFixtureB()->GetBody()->GetUserData() != NULL && *(int*)contact->GetFixtureB()->GetBody()->GetUserData() == 2)
	{
		if (*impulse->normalImpulses > 0.5f) {
			std::cout << "pig x bird" << std::endl;
			contact->GetFixtureB()->GetBody()->SetUserData(&pigIsDying);
		}
	}

	/*if (*(int*)contact->GetFixtureA()->GetBody()->GetUserData() == 5 || *(int*)contact->GetFixtureB()->GetBody()->GetUserData() == 5) {
		if (*impulse->normalImpulses > 0.7f) {
			std::cout << "Wall made contact!" << std::endl;
		}
	}*/

}

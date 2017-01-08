#include "Wheel_ph.h"

Wheel_ph::Wheel_ph()
{
}

Wheel_ph::~Wheel_ph()
{
}


void Wheel_ph::createWheel(b2World & world, float x, float y, float radius, float density, float speed)
{
	b2BodyDef circleDefinition;
	circleDefinition.type = b2_dynamicBody;
	circleDefinition.position.Set(x, y);

	b2Body * circle = world.CreateBody(&circleDefinition);

	b2CircleShape circleShape;
	circleShape.m_radius = radius;

	b2FixtureDef circleFixture;
	circleFixture.shape = &circleShape;
	circleFixture.density = density;
	circleFixture.friction = 0.3f;
	circleFixture.filter.categoryBits = 0x0002;
	circleFixture.filter.maskBits = 0x0001;

	circle->CreateFixture(&circleFixture);
	circle->SetAngularVelocity(Velocity);
	
	this->setDensity(density);
	this->setBody(circle);
}



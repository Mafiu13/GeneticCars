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
	circleDefinition.position.Set(x / SCALE, y / SCALE);

	b2Body* circle = world.CreateBody(&circleDefinition);

	b2CircleShape circleShape;
	circleShape.m_radius = radius / SCALE;

	b2FixtureDef circleFixture;
	circleFixture.shape = &circleShape;
	circleFixture.density = density;
	circleFixture.friction = 0.3f;

	circle->CreateFixture(&circleFixture);
	circle->SetAngularVelocity(speed);

	this->body = circle;
}

b2Body * Wheel_ph::getBody()
{
	return body;
}

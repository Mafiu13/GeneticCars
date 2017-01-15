#include "Wheel_ph.h"

Wheel_ph::Wheel_ph()
{
}

Wheel_ph::~Wheel_ph()
{
}

float Wheel_ph::getRadius()
{
	return radius;
}

ShapePoint Wheel_ph::getJointPoint()
{
	return jointPoint;
}

void Wheel_ph::setRadius(float r)
{
	radius = r;
}

void Wheel_ph::setJointPoint(ShapePoint & p)
{
	jointPoint.setX(p.getX());
	jointPoint.setY(p.getY());
}


void Wheel_ph::createWheel(b2World & world)
{
	b2BodyDef circleDefinition;
	circleDefinition.type = b2_dynamicBody;
	circleDefinition.position.Set(jointPoint.getX(), jointPoint.getY());

	b2Body * circle =  world.CreateBody(&circleDefinition);

	b2CircleShape circleShape;
	circleShape.m_radius = this->radius;

	b2FixtureDef circleFixture;
	circleFixture.shape = &circleShape;
	circleFixture.density = this->getDensity();
	circleFixture.friction = 0.3f;
	circleFixture.filter.categoryBits = 0x0002;
	circleFixture.filter.maskBits = 0x0001;

	circle->CreateFixture(&circleFixture);
	circle->SetAngularVelocity(Velocity);
	
	this->setBody(circle);
}

void Wheel_ph::updateVelocity()
{
	this->getBody()->SetAngularVelocity(Velocity);
}


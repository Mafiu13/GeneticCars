#include "PhysWheel.h"

PhysWheel::PhysWheel()
{
}

PhysWheel::~PhysWheel()
{
}

//------------------metody [get]------------------

float PhysWheel::getRadius() const
{
	return radius_;
}

ShapePoint PhysWheel::getJointPoint() const
{
	return jointPoint_;
}

//-----------------metody [set]------------------

void PhysWheel::setRadius(const float& radius)
{
	radius_ = radius;
}

void PhysWheel::setJointPoint(ShapePoint point)
{
	jointPoint_.setX(point.getX());
	jointPoint_.setY(point.getY());
}

void PhysWheel::updateVelocity(const float& value)
{
    this->getBody()->SetAngularVelocity(value);
}

void PhysWheel::createWheel(b2World & world)
{
	b2BodyDef circleDefinition;
	circleDefinition.type = b2_dynamicBody;
	circleDefinition.position.Set(jointPoint_.getX(), jointPoint_.getY());

	b2Body * circle =  world.CreateBody(&circleDefinition);

	b2CircleShape circleShape;
	circleShape.m_radius = this->radius_;

	b2FixtureDef circleFixture;
	circleFixture.shape = &circleShape;
	circleFixture.density = this->getDensity();
	circleFixture.friction = 0.3f;
	circleFixture.filter.categoryBits = 0x0002;
	circleFixture.filter.maskBits = 0x0001;

	circle->CreateFixture(&circleFixture);
	
	this->setBody(circle);
}


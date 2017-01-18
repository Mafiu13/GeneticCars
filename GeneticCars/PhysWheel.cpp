#include "PhysWheel.h"

PhysWheel::PhysWheel()
{
}

PhysWheel::~PhysWheel()
{
}

float PhysWheel::getRadius() const
{
	return radius_;
}

ShapePoint PhysWheel::getJointPoint() const
{
	return jointPoint_;
}

void PhysWheel::setRadius(float r)
{
	radius_ = r;
}

void PhysWheel::setJointPoint(ShapePoint p)
{
	jointPoint_.setX(p.getX());
	jointPoint_.setY(p.getY());
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
	circle->SetAngularVelocity(Velocity);
	
	this->setBody(circle);
}

void PhysWheel::updateVelocity()
{
	this->getBody()->SetAngularVelocity(Velocity);
}


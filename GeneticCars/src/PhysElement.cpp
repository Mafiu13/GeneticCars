#include "PhysElement.h"



PhysElement::PhysElement()
{
}


PhysElement::~PhysElement()
{
}

b2Body * PhysElement::getBody()
{
	return body_;
}

float PhysElement::getDensity() const
{
	return density_;
}

void PhysElement::setBody(b2Body * b)
{
	body_ = b;
}

void PhysElement::setDensity(float d)
{
	density_ = d;
}



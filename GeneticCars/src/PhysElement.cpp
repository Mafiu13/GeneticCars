#include "PhysElement.h"



PhysElement::PhysElement()
{
}

PhysElement::~PhysElement()
{
}
//---------------- metody [get]--------------
b2Body * PhysElement::getBody()
{
	return body_;
}

float PhysElement::getDensity() const
{
	return density_;
}

//----------------S metody [set]-----------------

void PhysElement::setBody(b2Body * b)
{
	body_ = b;
}

void PhysElement::setDensity(float const& d)
{
	density_ = d;
}



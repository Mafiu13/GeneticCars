#include "PhysElement.h"



PhysElement::PhysElement()
{
}


PhysElement::~PhysElement()
{
}

b2Body * PhysElement::getBody()
{
	return body;
}

float PhysElement::getDensity()
{
	return density;
}

void PhysElement::setBody(b2Body * b)
{
	body = b;
}

void PhysElement::setDensity(float d)
{
	density = d;
}



#include "Element_ph.h"



Element_ph::Element_ph()
{
}


Element_ph::~Element_ph()
{
	//body->GetWorld()->DestroyBody(body);
}

b2Body * Element_ph::getBody()
{
	return body;
}

float Element_ph::getDensity()
{
	return density;
}

void Element_ph::setBody(b2Body * b)
{
	body = b;
}

void Element_ph::setDensity(float d)
{
	density = d;
}



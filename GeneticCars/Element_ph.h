#ifndef ELEMENT_PH_H 
#define ELEMENT_PH_H

#include<Box2D\Box2D.h>
#include "const.h"

class Element_ph
{
	b2Body * body;
	float density;
public:
	Element_ph();
	~Element_ph();
	b2Body * getBody();
	float getDensity();
	void setBody(b2Body *);
	void setDensity(float);
	void updateVelocity();
};

#endif
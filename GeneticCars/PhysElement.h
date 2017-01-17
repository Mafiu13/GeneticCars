#ifndef PHYSELEMENT_H 
#define PHYSELEMENT_H

#include<Box2D/Box2D.h>
#include "const.h"

class PhysElement
{
	b2Body * body;
	float density;
public:
	PhysElement();
	~PhysElement();
	b2Body * getBody();
	float getDensity();
	void setBody(b2Body *);
	void setDensity(float);

};

#endif
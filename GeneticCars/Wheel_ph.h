#ifndef WHEEL_PH_H 
#define WHEEL_PH_H

#include <Box2D\Box2D.h>
#include "const.h"
#include "Element_ph.h"

class Wheel_ph: public Element_ph
{
	float radius;
public:
	Wheel_ph();
	~Wheel_ph();
	float getRadius();
	void setRadius(float);
	void updateVelocity();
	void createWheel(b2World &, float, float);
};

#endif
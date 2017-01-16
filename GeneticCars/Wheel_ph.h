#ifndef WHEEL_PH_H 
#define WHEEL_PH_H

#include <Box2D\Box2D.h>
#include "const.h"
#include "Element_ph.h"
#include "ShapePoint.h"

class Wheel_ph: public Element_ph
{
	float radius;
	ShapePoint jointPoint;
public:
	Wheel_ph();
	~Wheel_ph();
	float getRadius();
	ShapePoint getJointPoint();
	void setRadius(float);
	void setJointPoint(ShapePoint);
	void updateVelocity();
	void createWheel(b2World &);
};

#endif
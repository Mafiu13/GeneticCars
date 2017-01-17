#ifndef PHYSWHEEL_H 
#define PHYSWHEEL_H

#include <Box2D\Box2D.h>
#include "const.h"
#include "PhysElement.h"
#include "ShapePoint.h"

class PhysWheel : public PhysElement
{
	float radius;
	ShapePoint jointPoint;
public:
	PhysWheel();
	~PhysWheel();
	float getRadius();
	ShapePoint getJointPoint();
	void setRadius(float);
	void setJointPoint(ShapePoint);
	void updateVelocity();
	void createWheel(b2World &);
};

#endif
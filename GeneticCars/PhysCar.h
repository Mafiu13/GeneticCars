#ifndef PHYSCAR_H 
#define PHYSCAR_H

#include <Box2D/Box2D.h>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include "ShapePoint.h"
#include "PhysBodyShape.h"
#include "PhysWheel.h"
#include "const.h"

typedef boost::shared_ptr <PhysWheel> WheelSh;
typedef boost::shared_ptr <PhysBodyShape> BodyShapeSh;

class PhysCar
{
	std::vector<WheelSh> wheels;
	BodyShapeSh bodyShape;
	std::vector<b2RevoluteJoint*> joints;

public:
	PhysCar();
	~PhysCar();
	std::vector<boost::shared_ptr <PhysWheel>> getWheels();
	PhysBodyShape * getBodyShape();
	void setBodyShape(BodyShapeSh);
	void setWheels(std::vector<WheelSh>);
	void setParts(std::vector<WheelSh>, BodyShapeSh);
	void createJoint(b2World&, WheelSh);
	void createJoints(b2World&);
	void updateVelocity();
};

#endif
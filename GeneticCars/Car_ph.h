#ifndef CAR_PH_H 
#define CAR_PH_H

#include <Box2D\Box2D.h>
#include <boost\shared_ptr.hpp>
#include <boost\make_shared.hpp>
#include "ShapePoint.h"
#include "BodyShape_ph.h"
#include "Wheel_ph.h"
#include "const.h"

typedef boost::shared_ptr <Wheel_ph> WheelSh;
typedef boost::shared_ptr <BodyShape_ph> BodyShapeSh;

class Car_ph
{
	std::vector<WheelSh> wheels;
	BodyShapeSh bodyShape;
	std::vector<b2RevoluteJoint*> joints;

public:
	Car_ph();
	~Car_ph();
	std::vector<boost::shared_ptr <Wheel_ph>> getWheels();
	BodyShape_ph * getBodyShape();
	void setBodyShape(BodyShapeSh);
	void setWheels(std::vector<WheelSh>);
	void setParts(std::vector<WheelSh>, BodyShapeSh);
	void createJoint(b2World&, WheelSh);
	void createJoints(b2World&);
	void updateVelocity();
};

#endif
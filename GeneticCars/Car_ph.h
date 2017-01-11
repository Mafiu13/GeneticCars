#ifndef CAR_PH_H 
#define CAR_PH_H

#include <Box2D\Box2D.h>
#include <boost\shared_ptr.hpp>
#include "ShapePoint.h"
#include "BodyShape_ph.h"
#include "Wheel_ph.h"
#include "const.h"

class Car_ph
{
	boost::shared_ptr <Wheel_ph> wheel_1;
	boost::shared_ptr <Wheel_ph> wheel_2;
	boost::shared_ptr <BodyShape_ph> bodyShape;
	std::unique_ptr<b2Vec2> jointPoint_1;
	std::unique_ptr<b2Vec2> jointPoint_2;

public:
	Car_ph();

	~Car_ph();
	Wheel_ph * getWheel_1();
	Wheel_ph * getWheel_2();
	BodyShape_ph * getBodyShape();
	b2Vec2 * getJointPoint1();
	b2Vec2 * getJointPoint2();
	void setBodyShape(boost::shared_ptr <BodyShape_ph>);
	void setWheel(boost::shared_ptr <Wheel_ph>, int);
	void setJointPoints(float, float, float, float);
	void setParts(boost::shared_ptr <Wheel_ph>, boost::shared_ptr <Wheel_ph>, boost::shared_ptr <BodyShape_ph>);
	void createJoints(b2World&);
	void updateVelocity();
};

#endif
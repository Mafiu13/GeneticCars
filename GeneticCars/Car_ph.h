#pragma once
#include <Box2D\Box2D.h>
#include "ShapePoint.h"
#include "BodyShape_ph.h"
#include "Wheel_ph.h"
#include "const.h"


class Car_ph
{
	Wheel_ph * wheel_1;
	Wheel_ph * wheel_2;
	BodyShape_ph * bodyShape;

public:
	Car_ph(Wheel_ph*, Wheel_ph *, BodyShape_ph *);
	~Car_ph();
	void createJoint(b2World& World, b2Body *a, b2Body *b, ShapePoint p1, ShapePoint p2);
};


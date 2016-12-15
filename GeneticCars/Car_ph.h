#pragma once
#include <Box2D\Box2D.h>
#include "ShapePoint.h"
#include "const.h"


class Car_ph
{
	b2Body * bodies[3];

public:
	Car_ph(b2Body*, b2Body *, b2Body *);
	~Car_ph();
	void createJoint(b2World& World, b2Body *a, b2Body *b, ShapePoint p1, ShapePoint p2);
};


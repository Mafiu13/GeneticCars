#pragma once
#include <Box2D\Box2D.h>
#include "const.h"

class Wheel_ph
{
	b2Body * body;
public:
	Wheel_ph();
	~Wheel_ph();
	void createWheel(b2World & world, float x, float y, float radius, float density, float speed);
	b2Body * getBody();
};


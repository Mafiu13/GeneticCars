#pragma once
#include <Box2D\Box2D.h>
#include "ShapePoint.h"
#include "const.h"


class BodyShape_ph
{
	b2Body * body;
	ShapePoint vertices[8];

public:
	BodyShape_ph();
	~BodyShape_ph();
	void createBodyShape(b2World & world, float x, float y, ShapePoint w[8], float density);
	b2Body * getBody();
	ShapePoint * getVertices();
};


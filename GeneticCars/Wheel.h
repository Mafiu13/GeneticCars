#pragma once
#include "ShapePoint.h"

class Wheel
{
public:
	Wheel(float, float, int, ShapePoint);
	~Wheel();
	float getRadius();
	float getDensity();
	int getShapePointsIndex();
	ShapePoint getShapePoint();
private:
	float radius;
	float density;
	int shapePointsIndex;
	ShapePoint shapePoint;
};


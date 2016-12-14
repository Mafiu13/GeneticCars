#include "Wheel.h"


Wheel::Wheel(float radius, float density, int index, ShapePoint shapePoint)
	:shapePoint(shapePoint)
{
	this->radius = radius;
	this->density = density;
	this->shapePointsIndex = index;
}


Wheel::~Wheel()
{
}

float Wheel::getRadius()
{
	return radius;
}
float Wheel::getDensity()
{
	return density;
}
int Wheel::getShapePointsIndex()
{
	return shapePointsIndex;
}
ShapePoint Wheel::getShapePoint()
{
	return shapePoint;
}
#include "ShapePoint.h"



ShapePoint::ShapePoint(float x, float y)
{
	this->x = x;
	this->y = y;
}


ShapePoint::~ShapePoint()
{
}

float ShapePoint::getX()
{
	return x;
}

float ShapePoint::getY()
{
	return y;
}
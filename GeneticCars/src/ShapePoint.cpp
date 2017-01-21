#include "ShapePoint.h"



ShapePoint::ShapePoint(float x, float y)
{
	this->x = x;
	this->y = y;
}

ShapePoint::ShapePoint()
{
}


ShapePoint::~ShapePoint()
{
}

float ShapePoint::getX() const
{
	return x;
}

float ShapePoint::getY() const
{
	return y;
}

void ShapePoint::setX(float a)
{
	x = a;
}

void ShapePoint::setY(float b)
{
	y = b;
}

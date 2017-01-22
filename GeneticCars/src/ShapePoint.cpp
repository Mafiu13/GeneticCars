#include "ShapePoint.h"



ShapePoint::ShapePoint(const float& x, const float& y)
{
	this->x_ = x;
	this->y_ = y;
}

ShapePoint::ShapePoint()
{
}


ShapePoint::~ShapePoint()
{
}

float ShapePoint::getX() const
{
	return x_;
}

float ShapePoint::getY() const
{
	return y_;
}

void ShapePoint::setX(const float& a)
{
	x_ = a;
}

void ShapePoint::setY(const float& b)
{
	y_ = b;
}

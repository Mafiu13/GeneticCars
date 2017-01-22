#include "Wheel.h"


Wheel::Wheel(const float& radius, const float& density, const int& index, const ShapePoint& shapePoint)
	:shapePoint_(shapePoint)
{
	this->radius_ = radius;
	this->density_ = density;
	this->shapePointsIndex_ = index;
}


Wheel::~Wheel()
{
}

float Wheel::getRadius() const
{
	return radius_;
}
float Wheel::getDensity() const
{
	return density_;
}
int Wheel::getShapePointsIndex() const
{
	return shapePointsIndex_;
}
ShapePoint Wheel::getShapePoint()const
{
	return shapePoint_;
}
#include "BodyShape.h"


BodyShape::BodyShape(const std::vector<ShapePoint>& shapePoints, const float& density)
{
	this->shapePoints_ = shapePoints;
	this->density_ = density;
}


BodyShape::~BodyShape()
{
}

std::vector<ShapePoint> BodyShape::getShapePoints() const
{
	return shapePoints_;
}

float BodyShape::getDensity() const
{
	return density_;
}
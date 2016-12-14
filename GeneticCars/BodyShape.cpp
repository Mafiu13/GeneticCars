#include "BodyShape.h"




BodyShape::BodyShape(std::vector<ShapePoint> shapePoints, float density)
{
	this->shapePoints = shapePoints;
	this->density = density;
}


BodyShape::~BodyShape()
{
}

std::vector<ShapePoint> BodyShape::getShapePoints()
{
	return shapePoints;
}

float BodyShape::getDensity()
{
	return density;
}
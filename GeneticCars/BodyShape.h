#pragma once
#include "ShapePoint.h"
#include <vector>

class BodyShape
{
public:
	BodyShape(std::vector<ShapePoint>, float);
	~BodyShape();
	std::vector<ShapePoint> getShapePoints();
	float getDensity();
private:
	std::vector<ShapePoint> shapePoints;
	float density;
};


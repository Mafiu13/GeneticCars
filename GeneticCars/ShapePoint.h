#pragma once
class ShapePoint
{
public:
	ShapePoint(float, float);
	~ShapePoint();
	float getX();
	float getY();
private:
	float x;
	float y;
};


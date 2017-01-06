#pragma once
class ShapePoint
{
	float x;
	float y;
public:
	ShapePoint(float, float);
	ShapePoint();
	~ShapePoint();
	float getX();
	float getY();
	void setX(float);
	void setY(float);
};

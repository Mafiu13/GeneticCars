#pragma once
class ShapePoint
{
public:
	ShapePoint(int, int);
	~ShapePoint();
	int getX();
	int getY();
private:
	int x;
	int y;
};


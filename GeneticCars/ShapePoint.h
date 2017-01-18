#ifndef SHAPEPOINT_H 
#define SHAPEPOINT_H

/**
* \class ShapePoint
*
* \brief Punkt w przestrzeni o wspolrzednych x, y
*
*/
class ShapePoint
{
	float x;
	float y;
public:
	/**
	* Konstruktor ShapePoint
	* \param x wspolrzedna x punktu
	* \param y wsporzedna y punktu
	*
	*/
	ShapePoint(float x, float y);
	ShapePoint();
	~ShapePoint();
	float getX() const;
	float getY() const;
	void setX(float);
	void setY(float);
};

#endif
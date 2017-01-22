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
	float x_;
	float y_;
public:
	/**
	* Konstruktor ShapePoint
	* \param x wspolrzedna x punktu
	* \param y wsporzedna y punktu
	*
	*/
	ShapePoint(const float& x, const float& y);
	ShapePoint();
	~ShapePoint();
	float getX() const;
	float getY() const;
	void setX(const float& x);
	void setY(const float& y);
};

#endif
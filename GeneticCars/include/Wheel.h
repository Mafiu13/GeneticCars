#ifndef WHEEL_H 
#define WHEEL_H

#include "ShapePoint.h"

/**
* \class Wheel
*
* \brief Kolo pojazdu
*
*/
class Wheel
{
public:
	/**
	* Konstruktor Wheel
	* \param radius promien kola
	* \param density gestosc kola
	* \param shapePoint punkt okreslajacy srodek kola
	*
	*/
	Wheel(float radius, float density, int index, ShapePoint shapePoint);
	~Wheel();
	float getRadius();
	float getDensity();

	/**
	* Metoda zwraca index punktu nadwozia pojazdu, ktory jest punktem zaczepienia srodka kola
	*
	*/
	int getShapePointsIndex();
	ShapePoint getShapePoint();
private:
	float radius;
	float density;
	int shapePointsIndex;
	ShapePoint shapePoint;
};

#endif

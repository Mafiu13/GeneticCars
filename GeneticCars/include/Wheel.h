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
	Wheel(const float& radius, const float& density, const int& index, const ShapePoint& shapePoint);
	~Wheel();
	float getRadius() const;
	float getDensity() const;

	/**
	* Metoda zwraca index punktu nadwozia pojazdu, ktory jest punktem zaczepienia srodka kola
	*
	*/
	int getShapePointsIndex() const;
	ShapePoint getShapePoint() const;
private:
	float radius_;
	float density_;
	int shapePointsIndex_;
	ShapePoint shapePoint_;
};

#endif

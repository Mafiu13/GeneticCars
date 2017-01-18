#ifndef BODYSHAPE_H 
#define BODYSHAPE_H

#include "ShapePoint.h"
#include <vector>

/**
* \class BodyShape
*
* \brief Nadwozie pojazdu
*
*/
class BodyShape
{
public:
	/**
	* Konstruktor BodyShape
	* \param shapePoints punkty okreslajace ksztalt nadwozia
	* \param density gestosc nadwozia
	*
	*/
	BodyShape(std::vector<ShapePoint> shapePoints, float density);
	~BodyShape();
	std::vector<ShapePoint> getShapePoints() const;
	float getDensity();
private:
	std::vector<ShapePoint> shapePoints;
	float density;
};

#endif
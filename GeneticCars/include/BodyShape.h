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
	BodyShape(const std::vector<ShapePoint>& shapePoints, const float& density);
	~BodyShape();
	std::vector<ShapePoint> getShapePoints() const;
	float getDensity() const;
private:
	std::vector<ShapePoint> shapePoints_;
	float density_;
};

#endif
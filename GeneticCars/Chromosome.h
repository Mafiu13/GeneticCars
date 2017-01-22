#ifndef CHROMOSOME_H 
#define CHROMOSOME_H

#include "BodyShape.h"
#include "Wheel.h"

/**
* \class Chromosome
*
* \brief Chromosom
*
*/
class Chromosome
{
public:
	Chromosome(const BodyShape& bodyShape, const std::vector<Wheel>& wheels);
	~Chromosome();
	BodyShape getBodyShape() const;
	std::vector<Wheel> getWheels() const;
private:
	BodyShape bodyShape_;
	std::vector<Wheel> wheels_;
};

#endif
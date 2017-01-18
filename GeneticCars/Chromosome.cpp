#include "Chromosome.h"



Chromosome::Chromosome(BodyShape bodyShape, std::vector<Wheel> wheels)
	:bodyShape(bodyShape)
{
	this->wheels = wheels;
}


Chromosome::~Chromosome()
{
}

BodyShape Chromosome::getBodyShape() const
{
	return bodyShape;
}

std::vector<Wheel> Chromosome::getWheels() const
{
	return wheels;
}
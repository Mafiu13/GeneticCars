#include "Chromosome.h"



Chromosome::Chromosome(BodyShape bodyShape, std::vector<Wheel> wheels)
	:bodyShape(bodyShape)
{
	this->wheels = wheels;
}


Chromosome::~Chromosome()
{
}

BodyShape Chromosome::getBodyShape()
{
	return bodyShape;
}

std::vector<Wheel> Chromosome::getWheels()
{
	return wheels;
}
#include "Chromosome.h"



Chromosome::Chromosome(const BodyShape& bodyShape, const std::vector<Wheel>& wheels)
	:bodyShape_(bodyShape)
{
	this->wheels_ = wheels;
}


Chromosome::~Chromosome()
{
}

BodyShape Chromosome::getBodyShape() const
{
	return bodyShape_;
}

std::vector<Wheel> Chromosome::getWheels() const
{
	return wheels_;
}
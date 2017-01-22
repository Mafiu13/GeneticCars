#include "Car.h"



Car::Car(const Chromosome& chromosome)
	:chromosome_(chromosome)
{
	this->distance_ = -1;
}

Car::~Car()
{
}

Chromosome Car::getChromosome() const
{
	return chromosome_;
}

float Car::getDistance() const
{
	return distance_;
}

void Car::setDistance(const float& distance)
{
	this->distance_ = distance;
}
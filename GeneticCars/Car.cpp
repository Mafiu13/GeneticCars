#include "Car.h"



Car::Car(Chromosome chromosome)
	:chromosome(chromosome)
{
	this->distance = -1;
}

Car::~Car()
{
}

Chromosome Car::getChromosome()
{
	return chromosome;
}

float Car::getDistance()
{
	return distance;
}

void Car::setDistance(float distance)
{
	this->distance = distance;
}
#include "Car.h"



Car::Car(Chromosome chromosome)
	:chromosome(chromosome)
{
	this->fitness = -1;
}


Car::~Car()
{
}

Chromosome Car::getChromosome()
{
	return chromosome;
}

float Car::getFitness()
{
	return fitness;
}

void Car::setFitness(float fitness)
{
	this->fitness = fitness;
}
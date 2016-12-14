#pragma once
#include "Chromosome.h"

class Car
{
public:
	Car(Chromosome);
	~Car();
	Chromosome getChromosome();
	float getFitness();
	void setFitness(float);
private:
	Chromosome chromosome;
	float fitness;
};


#pragma once
#include "CarConst.h"
#include "Chromosome.h"

class Car
{
public:
	Car(Chromosome);
	~Car();
	Chromosome getChromosome();
	float getDistance();
	void setDistance(float);
private:
	Chromosome chromosome;
	float distance;
};


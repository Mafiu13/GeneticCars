#pragma once
#include "BodyShape.h"
#include "Wheel.h"

class Chromosome
{
public:
	Chromosome(BodyShape, std::vector<Wheel>);
	~Chromosome();
	BodyShape getBodyShape();
	std::vector<Wheel> getWheels();
private:
	BodyShape bodyShape;
	std::vector<Wheel> wheels;
};


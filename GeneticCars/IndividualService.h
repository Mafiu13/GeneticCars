#pragma once
#include "Car.h"
#include <random>
#include "EvolutionaryConst.h"

using namespace std;

class IndividualService
{
public:
	IndividualService(float const);
	~IndividualService();

	Car getRandomCar();
	vector<Car> getCrossoveredCars(Car parentA, Car parentB);
	Car getMutatedCar(Car car);

private:
	const float mutationRate;
	const int  nrPoints = 2 * NR_OF_POINTS_IN_BODYSHAPE + 2 * NR_OF_WHEELS;
	const int nrDensity = 1 + NR_OF_WHEELS;
	const int nrRadius = NR_OF_WHEELS;

	random_device randomDevice;
	mt19937 randomEngine;

	bool checkIfMutate();
	Chromosome getRandomChromosome();
	BodyShape getRandomBodyShape();
	Wheel getRandomWheel(int wheelIndex);
	ShapePoint getRandomShapePoint();
	float getRandomPoint();
	float getRandomDensity();
	float getRandomRadius();
	float getRandomFloat(float min, float max);
	double getRandomMutationValue();
	double getRandomDouble(double min, double max);
	int getRandomInt(int min, int max);

	Car convertVectorToCar(vector<float> chromosomeVector);
	vector<float> convertCarToVector(Car car);
};


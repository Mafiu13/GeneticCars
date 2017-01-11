#pragma once
#include "Car.h"
#include "EvolutionaryConst.h"
#include "RandomService.h"

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

	RandomService randomService;

	const float mutationRate;
	const int  nrPointsBS = 2 * NR_OF_POINTS_IN_BODYSHAPE;
	const int nrOfWheels = NR_OF_WHEELS;
	const int nrDensity = 1 + NR_OF_WHEELS;
	const int nrRadius = NR_OF_WHEELS;

	bool checkIfMutate();
	Chromosome getRandomChromosome();
	BodyShape getRandomBodyShape();
	Wheel getRandomWheel(BodyShape bs, vector<Wheel> wheels);
	int getRandomShapePointIndexFromBodyShape(BodyShape bs, vector<Wheel> wheels);
	bool isBodyShapeIndexUsedInAnotherWheel(vector<int> usedIndexes, int index);
	ShapePoint getRandomShapePoint();
	float getRandomPoint();
	float getRandomDensity();
	float getRandomRadius();
	double getRandomMutationValue();

	Car convertVectorToCar(vector<float> chromosomeVector);
	vector<float> convertCarToVector(Car car);
};
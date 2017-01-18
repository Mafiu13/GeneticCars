#ifndef INDIVIDUALSERVICE_H 
#define INDIVIDUALSERVICE_H

#include "Car.h"
#include "EvolutionaryConst.h"
#include "RandomService.h"
#include <map>

using namespace std;
/**
* \class IndividualService
*
* \brief Serwis zarzadzajacy cechami pojazdu
*
*/
class IndividualService
{
public:
	/**
	* Konstruktor IndividualService
	* \param mutationRate stopien mutacji
	*
	*/
	IndividualService(float const mutationRate);
	~IndividualService();

	/**
	* Metoda zwraca pojazd o randomowych cechach
	*
	*/
	Car getRandomCar();

	/**
	* Metoda zwraca pojazd posiadajacy skrzyzowanie cechu dwoch rodzicow-pojazdow
	* \param parentA pierwszy z rodizcow
	* \param parentA drugi z rodizcow
	*
	*/
	vector<Car> getCrossoveredCars(Car parentA, Car parentB);

	/**
	* Metoda mutuj i zwraca pojazd o zmutowanych cechach
	* \param pojazd ktorego cechy maja byc zmutowane
	*
	*/
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

	vector<ShapePoint> sortBodyShapesByAngle(vector<ShapePoint> shapePoints);
	Car convertVectorToCar(vector<float> chromosomeVector);
	vector<float> convertCarToVector(Car car);
};

#endif
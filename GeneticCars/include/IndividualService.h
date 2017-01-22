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
	IndividualService(const float& mutationRate);
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
	vector<Car> getCrossoveredCars(const Car& parentA, const Car& parentB);

	/**
	* Metoda mutuj i zwraca pojazd o zmutowanych cechach
	* \param pojazd ktorego cechy maja byc zmutowane
	*
	*/
	Car getMutatedCar(const Car& car);

private:

	RandomService randomService_;

	const float mutationRate_;
	const int  nrPointsBS_ = 2 * NR_OF_POINTS_IN_BODYSHAPE;
	const int nrOfWheels_ = NR_OF_WHEELS;
	const int nrDensity_ = 1 + NR_OF_WHEELS;
	const int nrRadius_ = NR_OF_WHEELS;

	bool checkIfMutate();
	Chromosome getRandomChromosome();
	BodyShape getRandomBodyShape();
	Wheel getRandomWheel(const BodyShape& bs, const vector<Wheel>& wheels);
	int getRandomShapePointIndexFromBodyShape( const BodyShape& bs, const vector<Wheel>& wheels);
	bool isBodyShapeIndexUsedInAnotherWheel(const vector<int>& usedIndexes, const int& index);
	ShapePoint getRandomShapePoint();
	float getRandomPoint();
	float getRandomDensity();
	float getRandomRadius();
	double getRandomMutationValue();

	vector<ShapePoint> sortBodyShapesByAngle(const vector<ShapePoint>& shapePoints);
	Car convertVectorToCar(const vector<float>& chromosomeVector);
	vector<float> convertCarToVector(const Car& car);
};

#endif
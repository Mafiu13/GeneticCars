#include "IndividualService.h"



IndividualService::IndividualService(float const mutationRate)
	:randomService(),
	mutationRate(mutationRate)
{
}


IndividualService::~IndividualService()
{
}

Car IndividualService::getRandomCar()
{
	Chromosome randomChromosome = getRandomChromosome();
	Car randomCar = Car(randomChromosome);
	return randomCar;
}

vector<Car> IndividualService::getCrossoveredCars(Car parentA, Car parentB)
{
	vector<float> chromosomeVectorA = convertCarToVector(parentA);
	vector<float> chromosomeVectorB = convertCarToVector(parentB);
	int chromosomeVecotrSize = chromosomeVectorA.size();
	vector<float> chromosomeVectorAB(chromosomeVecotrSize);
	vector<float> chromosomeVectorBA(chromosomeVecotrSize);
	int splitIndex = randomService.getRandomInt(1, chromosomeVecotrSize - 1);
	for (int i = 0; i < chromosomeVecotrSize; ++i)
	{
		if (i < splitIndex) 
		{
			chromosomeVectorAB[i] = chromosomeVectorA[i];
			chromosomeVectorBA[i] = chromosomeVectorB[i];
		}
		else {
			chromosomeVectorAB[i] = chromosomeVectorB[i];
			chromosomeVectorBA[i] = chromosomeVectorA[i];
		}
	}
	vector<Car> crossoveredCars;
	Car childAB = convertVectorToCar(chromosomeVectorAB);
	Car childBA = convertVectorToCar(chromosomeVectorBA);
	crossoveredCars.push_back(childAB);
	crossoveredCars.push_back(childBA);
	return crossoveredCars;
}

Car IndividualService::getMutatedCar(Car car)
{
	vector<float> chromosomeVector = convertCarToVector(car);
	for (int i = 0; i < nrPointsBS; ++i)
	{
		if (checkIfMutate())
		{
			chromosomeVector[i] = getRandomPoint();
		}
	}
	// No mutation for wheels position index
	for (int i = nrPointsBS + nrOfWheels; i < nrPointsBS + nrOfWheels + nrDensity; ++i)
	{
		if (checkIfMutate())
		{
			chromosomeVector[i] = getRandomDensity();
		}
	}
	for (int i = nrPointsBS + nrOfWheels + nrDensity; i < nrPointsBS + nrOfWheels + nrDensity + nrRadius; ++i)
	{
		if (checkIfMutate())
		{
			chromosomeVector[i] = getRandomRadius();
		}
	}
	Car mutatedCar = convertVectorToCar(chromosomeVector);
	return mutatedCar;
}

bool IndividualService::checkIfMutate()
{
	double mutationValue = getRandomMutationValue();
	return (mutationRate > mutationValue);
}

Chromosome IndividualService::getRandomChromosome()
{
	BodyShape randomBodyShape = getRandomBodyShape();
	vector<Wheel> wheels;
	for (int i = 0; i < NR_OF_WHEELS; ++i)
	{
		Wheel randomWheel = getRandomWheel(randomBodyShape, wheels);
		wheels.push_back(randomWheel);
	}
	Chromosome randomChromosome = Chromosome(randomBodyShape, wheels);
	return randomChromosome;
}

BodyShape IndividualService::getRandomBodyShape()
{
	float randomDensity = getRandomDensity();
	vector<ShapePoint> shapePoints;
	for(int i = 0; i < NR_OF_POINTS_IN_BODYSHAPE; ++i)
	{
		ShapePoint randomShapePoint = getRandomShapePoint();
		shapePoints.push_back(randomShapePoint);
	}
	vector<ShapePoint> sotedShapePoints = sortBodyShapesByAngle(shapePoints);
	BodyShape randomBodyShape = BodyShape(sotedShapePoints, randomDensity);
	return randomBodyShape;
}

Wheel IndividualService::getRandomWheel(BodyShape bs, vector<Wheel> wheels)
{
	float randomRadius = getRandomRadius();
	float randomDensity = getRandomDensity();
	int index = getRandomShapePointIndexFromBodyShape(bs, wheels);
	ShapePoint randomShapePoint = bs.getShapePoints()[index];
	Wheel randomWheel = Wheel(randomRadius, randomDensity, index, randomShapePoint);
	return randomWheel;
}

int IndividualService::getRandomShapePointIndexFromBodyShape(BodyShape bs, vector<Wheel> wheels)
{
	vector<int> bsIndexes;
	for (Wheel wheel : wheels)
	{
		bsIndexes.push_back(wheel.getShapePointsIndex());
	}
	vector<ShapePoint> shapePoints = bs.getShapePoints();
	int index = randomService.getRandomInt(0, shapePoints.size() - 1);
	while (isBodyShapeIndexUsedInAnotherWheel(bsIndexes, index))
	{
		index = randomService.getRandomInt(0, shapePoints.size() - 1);
	}
	return index;
}

bool IndividualService::isBodyShapeIndexUsedInAnotherWheel(vector<int> usedIndexes, int index)
{
	for (int usedIndex : usedIndexes)
	{
		if (usedIndex == index)
			return true;
	}
	return false;
}

ShapePoint IndividualService::getRandomShapePoint()
{
	float x = getRandomPoint();
	float y = getRandomPoint();
	ShapePoint randomShapePoint = ShapePoint(x, y);
	return randomShapePoint;
}

float IndividualService::getRandomPoint()
{
	float randomPoint = randomService.getRandomFloat(POINT_MIN, POINT_MAX);
	return randomPoint;
}

float IndividualService::getRandomDensity()
{
	float randomDensity = randomService.getRandomFloat(DENSITY_MIN, DENSITY_MAX);
	return randomDensity;
}

float IndividualService::getRandomRadius()
{
	float randomRadius = randomService.getRandomFloat(RADIUS_MIN, RADIUS_MAX);
	return randomRadius;
}

double IndividualService::getRandomMutationValue()
{
	double randomMutationValue = randomService.getRandomDouble(MUTATION_RATE_MIN, MUTATION_RATE_MAX);
	return randomMutationValue;
}

vector<ShapePoint> IndividualService::sortBodyShapesByAngle(vector<ShapePoint> shapePoints)
{
	vector<ShapePoint> sortedShapePoints;
	map<float, int> angles;
	for (int i = 0; i < shapePoints.size(); ++i)
	{
		float angle = atan2(shapePoints[i].getY(), shapePoints[i].getX());
		angles[angle] = i;
	}
	for (auto angle : angles)
	{
		int index = angle.second;
		sortedShapePoints.push_back(shapePoints[index]);
	}
	while (sortedShapePoints.size() != shapePoints.size())
	{
		sortedShapePoints.push_back(sortedShapePoints.back());
	}
	return sortedShapePoints;
}

Car IndividualService::convertVectorToCar(vector<float> chromosomeVector)
{
	// BodyShape
	vector<ShapePoint> bsShapePoints;
	for (int i = 0; i < NR_OF_POINTS_IN_BODYSHAPE; ++i)
	{
		int index = i * 2;
		float x = chromosomeVector[index];
		float y = chromosomeVector[++index];
		ShapePoint sp = ShapePoint(x, y);
		bsShapePoints.push_back(sp);
	}
	float bsDensity = chromosomeVector[nrPointsBS + nrOfWheels];
	vector<ShapePoint> sortedShapePoints = sortBodyShapesByAngle(bsShapePoints);
	BodyShape bs = BodyShape(sortedShapePoints, bsDensity);

	// Wheels
	vector<Wheel> wheels;
	vector<ShapePoint> whShapePoints;
	vector<int> indexes;
	vector<float> whDensities;
	vector<float> whRadiuses;
	for (int i = nrPointsBS; i < nrPointsBS + nrOfWheels; ++i)
	{
		int index = chromosomeVector[i];
		indexes.push_back(index);
		ShapePoint sp = sortedShapePoints[index];
		whShapePoints.push_back(sp);
	}
	for (int i = nrPointsBS + nrOfWheels + 1; i < nrPointsBS + nrOfWheels + nrDensity; ++i)
	{
		float whDensity = chromosomeVector[i];
		whDensities.push_back(whDensity);
	}
	for (int i = nrPointsBS + nrOfWheels + nrDensity; i < nrPointsBS + nrOfWheels + nrDensity + nrRadius; ++i)
	{
		float whRadius = chromosomeVector[i];
		whRadiuses.push_back(whRadius);
	}
	for (int i = 0; i < NR_OF_WHEELS; ++i)
	{
		Wheel wh = Wheel(
			whRadiuses[i],
			whDensities[i],
			indexes[i],
			whShapePoints[i]
		);
		wheels.push_back(wh);
	}

	// Car
	Chromosome chromosome = Chromosome(bs, wheels);
	Car car = Car(chromosome);
	return car;
}

vector<float> IndividualService::convertCarToVector(Car car)
{
	vector<float> chromosomeVector;

	Chromosome chromosome = car.getChromosome();
	BodyShape bodyShape = chromosome.getBodyShape();

	// POINTS
	for (ShapePoint sp : bodyShape.getShapePoints())
	{
		float x = sp.getX();
		float y = sp.getY();
		chromosomeVector.push_back(x);
		chromosomeVector.push_back(y);
	}
	// POINTS INDEXES - Wheels
	vector<Wheel> wheels = chromosome.getWheels();
	for (Wheel wh : wheels)
	{
		float index = wh.getShapePointsIndex();
		chromosomeVector.push_back(index);
	}
	
	// DENSITIES
	float bsDensity = bodyShape.getDensity();
	chromosomeVector.push_back(bsDensity);
	for (Wheel wh : wheels)
	{
		float whDensity = wh.getDensity();
		chromosomeVector.push_back(whDensity);
	}

	// RADIUSES
	for (Wheel wh : wheels)
	{
		float whRadius = wh.getRadius();
		chromosomeVector.push_back(whRadius);
	}
	return chromosomeVector;
}
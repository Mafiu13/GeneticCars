#include "EvolutionaryService.h"



EvolutionaryService::EvolutionaryService(const int& populationSize, const float& mutationRate)
	:populationSize_(populationSize),
	individualService_(mutationRate),
	randomService_()
{
}


EvolutionaryService::~EvolutionaryService()
{
}

vector<Car> EvolutionaryService::createFirstPopulation()
{
	vector<Car> firstPopulation;
	for (int i = 0; i < populationSize_; ++i)
	{
		Car randomCar = individualService_.getRandomCar();
		firstPopulation.push_back(randomCar);
	}
	return firstPopulation;
}

vector<Car> EvolutionaryService::createNextPopulation(const vector<Car>& previousPopulation)
{
	vector<Car> nextPopulation;
	generateParentsForNextPopulation(previousPopulation);
	nextPopulation = crossoverParents();
	nextPopulation = mutateNewPopulation(nextPopulation);
	return nextPopulation;
}

float EvolutionaryService::getBestCarDistanceInPopulation(const vector<Car>& population)
{
	float longestDistance = 0.0;
	for (Car car : population)
	{
		float distance = car.getDistance();
		if (longestDistance < distance)
		{
			longestDistance = distance;

		}
	}
	return longestDistance;
}

void EvolutionaryService::generateParentsForNextPopulation(const vector<Car>& previousPopulation)
{
	vector<Car> parentsA;
	vector<Car> parentsB;

	vector<Car> tempPopulation;
	vector<float> roulletteWheel = getPopulationScores(previousPopulation);
	vector<float> tempRoulletteWheel;

	int indexA;
	int indexB;
	for (int i = 0; i < populationSize_ / 2; ++i)
	{
		indexA = getCarIndexFromRoulletteWheel(roulletteWheel);
		parentsA.push_back(previousPopulation[indexA]);

		tempPopulation = previousPopulation;
		tempPopulation.erase(tempPopulation.begin() + indexA);
		tempRoulletteWheel = getPopulationScores(tempPopulation);
		indexB = getCarIndexFromRoulletteWheel(tempRoulletteWheel);
		parentsB.push_back(tempPopulation[indexB]);	
	}
	// TODO - jezeli populationSize nieparzysty to losujemy jednego ziomka i dajemy go 2x na koniec

	this->parentsA_ = parentsA;
	this->parentsB_ = parentsB;
}

vector<float> EvolutionaryService::getPopulationScores(const vector<Car>& population)
{
	vector<float> scores;
	float distanceSum = 0.0;
	float scoreSum = 0.0;
	for (Car car : population)
	{
		distanceSum += car.getDistance();
	}
	if (distanceSum == 0) {
		distanceSum = 0.1;
	}
	for (Car car : population)
	{
		float score = car.getDistance() / distanceSum;
		scoreSum += score;
		scores.push_back(scoreSum);
	}
	return scores;
}

int EvolutionaryService::getCarIndexFromRoulletteWheel(const vector<float>& roulletteWheel)
{
	float maxPocket = *max_element(roulletteWheel.begin(), roulletteWheel.end());
	float randomPocket = randomService_.getRandomFloat(0.0, 1.0);
	for (int i = 0; i < roulletteWheel.size(); ++i)
	{
		float pocket = roulletteWheel[i];
		if (pocket >= randomPocket)
		{
			return i;
		}
	}
}

vector<Car> EvolutionaryService::crossoverParents()
{
	vector<Car> newPopulation;
	for (int i = 0; i < populationSize_ / 2; ++i)
	{
		Car parentA = parentsA_[i];
		Car parentB = parentsB_[i];
		vector<Car> crossoveredCars = individualService_.getCrossoveredCars(parentA, parentB);
		for (Car childCar : crossoveredCars)
		{
			newPopulation.push_back(childCar);
		}
	}
	return newPopulation;
}

vector<Car> EvolutionaryService::mutateNewPopulation(const vector<Car>& newPopulation)
{
	vector<Car> mutatedPopulation;
	for (Car childCar : newPopulation)
	{
		Car mutatedCar = individualService_.getMutatedCar(childCar);
		mutatedPopulation.push_back(mutatedCar);
	}
	return mutatedPopulation;
}
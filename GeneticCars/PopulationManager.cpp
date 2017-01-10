#include "PopulationManager.h"



PopulationManager::PopulationManager(int const populationSize, float const mutationRate)
	: populationSize(populationSize),
	evolutionaryService(populationSize, mutationRate)
{
}


PopulationManager::~PopulationManager()
{
}


vector<Car> PopulationManager::generateInitialPopulation()
{
	vector<Car> initialPopulation;
	initialPopulation = evolutionaryService.createFirstPopulation();
	return initialPopulation;
}

vector<Car> PopulationManager::generateNextPopulation(const vector<Car> currentPopulation)
{
	vector<Car> nextPopulation;
	nextPopulation = evolutionaryService.createNextPopulation(currentPopulation);
	return nextPopulation;
}

Car PopulationManager::getBestCar(const vector<Car> populationWithDistance)
{
	Car newBestCar = evolutionaryService.getBestCarInPopulation(populationWithDistance);
	if (bestCar) {
		Car bc = *bestCar;
		if (newBestCar.getDistance() > bc.getDistance())
		{
			*bestCar = newBestCar;
		}
	}
	else {
		*bestCar = newBestCar;
	}
	return *bestCar;
}

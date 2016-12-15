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

	// TODO - generate and return initital population 

	return initialPopulation;
}

vector<Car> PopulationManager::generateNextPopulation(const vector<Car> currentPopulation)
{
	vector<Car> nextPopulation;
	findBestCar();
	nextPopulation = evolutionaryService.createNextPopulation(currentPopulation);
	return nextPopulation;
}

void PopulationManager::findBestCar()
{
	// TODO - find best Car by distance
}

Car PopulationManager::getBestCar()
{
	return *bestCar;
}



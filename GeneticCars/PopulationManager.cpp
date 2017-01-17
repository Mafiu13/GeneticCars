#include "PopulationManager.h"



PopulationManager::PopulationManager(int const populationSize, float const mutationRate)
	: populationSize(populationSize),
	evolutionaryService(populationSize, mutationRate),
	currentPopulationNr(0),
	bestCarInfo(0.0, 0)
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
	++currentPopulationNr;
	return nextPopulation;
}

pair<float, int> PopulationManager::getBestCarInfo(const vector<Car> populationWithDistance)
{
	float distance = evolutionaryService.getBestCarDistanceInPopulation(populationWithDistance);
	if (bestCarInfo.first < distance)
	{
		bestCarInfo.first = distance;
		bestCarInfo.second = currentPopulationNr;
	}
	return bestCarInfo;
}

#include "PopulationManager.h"



PopulationManager::PopulationManager(const int& populationSize, const float& mutationRate)
	: populationSize_(populationSize),
	evolutionaryService_(populationSize, mutationRate),
	currentPopulationNr_(0),
	bestCarInfo_(0.0, 0)
{
}


PopulationManager::~PopulationManager()
{
}


vector<Car> PopulationManager::generateInitialPopulation()
{
	vector<Car> initialPopulation;
	initialPopulation = evolutionaryService_.createFirstPopulation();
	return initialPopulation;
}

vector<Car> PopulationManager::generateNextPopulation(const vector<Car>& currentPopulation)
{
	vector<Car> nextPopulation;
	nextPopulation = evolutionaryService_.createNextPopulation(currentPopulation);
	++currentPopulationNr_;
	return nextPopulation;
}

pair<float, int> PopulationManager::getBestCarInfo(const vector<Car>& populationWithDistance)
{
	float distance = evolutionaryService_.getBestCarDistanceInPopulation(populationWithDistance);
	if (bestCarInfo_.first < distance)
	{
		bestCarInfo_.first = distance;
		bestCarInfo_.second = currentPopulationNr_;
	}
	return bestCarInfo_;
}

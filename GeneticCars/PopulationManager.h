#ifndef POPULATIONMANAGER_H 
#define POPULATIONMANAGER_H

#include "EvolutionaryService.h"

class PopulationManager
{
public:
	PopulationManager(int const, float const );
	~PopulationManager();

	vector<Car> generateInitialPopulation();
	vector<Car> generateNextPopulation(const vector<Car> currentPopulation);
	Car getBestCar(const vector<Car> populationWithDistance);

private:
	const int populationSize;

	EvolutionaryService evolutionaryService;

	shared_ptr<Car> bestCar;
};

#endif
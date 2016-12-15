#pragma once
#include "Car.h"
#include "EvolutionaryService.h"

class PopulationManager
{
public:
	PopulationManager(int const, float const);
	~PopulationManager();

	vector<Car> generateInitialPopulation();
	vector<Car> generateNextPopulation(const vector<Car>);
	Car getBestCar();

private:
	const int populationSize;

	EvolutionaryService evolutionaryService;

	vector<Car> population;
	auto_ptr<Car> bestCar;

	void findBestCar();
};


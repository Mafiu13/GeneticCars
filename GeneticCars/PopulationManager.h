#ifndef POPULATIONMANAGER_H 
#define POPULATIONMANAGER_H

#include "EvolutionaryService.h"
class PopulationManager;
typedef boost::shared_ptr <PopulationManager> PPopulationManager;

class PopulationManager
{
public:
	PopulationManager(int const, float const );
	~PopulationManager();

	vector<Car> generateInitialPopulation();
	vector<Car> generateNextPopulation(const vector<Car> currentPopulation);
	pair<float, int> getBestCarInfo(const vector<Car> populationWithDistance);

private:
	const int populationSize;

	EvolutionaryService evolutionaryService;

	pair<float, int> bestCarInfo;
	int currentPopulationNr;
};

#endif
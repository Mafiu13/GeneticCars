#ifndef EVOLUTIONARYSERVICE_H 
#define EVOLUTIONARYSERVICE_H

#include "IndividualService.h"
#include <memory>

using namespace std;

class EvolutionaryService
{
public:
	EvolutionaryService(int const, float const);
	~EvolutionaryService();

	vector<Car> createFirstPopulation();
	vector<Car> createNextPopulation(const vector<Car> previousPopulation);
	float getBestCarDistanceInPopulation(const vector<Car> population);

private:

	const int populationSize;
	
	IndividualService individualService;
	RandomService randomService;

	vector<Car> parentsA;
	vector<Car> parentsB;

	void generateParentsForNextPopulation(const vector<Car> previousPopulation);
	vector<float> getPopulationScores(const vector<Car> population);
	int getCarIndexFromRoulletteWheel(vector<float> roulletteWheel);
	vector<Car> crossoverParents();
	vector<Car> mutateNewPopulation(vector<Car> newPopulation);
};

#endif
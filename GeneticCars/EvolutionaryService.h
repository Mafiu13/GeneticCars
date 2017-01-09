#pragma once
#include "IndividualService.h"

using namespace std;

class EvolutionaryService
{
public:
	EvolutionaryService(int const, float const);
	~EvolutionaryService();

	vector<Car> createNextPopulation(const vector<Car> previousPopulation);

private:

	const int populationSize;
	
	IndividualService individualService;

	vector<Car> parentsA;
	vector<Car> parentsB;

	void generateParentsForNextPopulation(const vector<Car> previousPopulation);
	vector<Car> crossoverParents();
	vector<Car> mutateNewPopulation(vector<Car> newPopulation);
};


#include "EvolutionaryService.h"



EvolutionaryService::EvolutionaryService(int const populationSize, float const mutationRate)
	:populationSize(populationSize),
	 mutationRate(mutationRate)
{
}


EvolutionaryService::~EvolutionaryService()
{
}

vector<Car> EvolutionaryService::createNextPopulation(const vector<Car> previousPopulation)
{
	vector<Car> nextPopulation;

	generateParentsForNextPopulation(previousPopulation);
	nextPopulation = crossoverParents();
	nextPopulation = mutateNewPopulation(nextPopulation);

	return nextPopulation;
}


void EvolutionaryService::generateParentsForNextPopulation(const vector<Car> previousPopulation)
{
	vector<Car> parentsA;
	vector<Car> parentsB;

	// TODO - choose best parents from population(roulette-wheel)

	this->parentsA = parentsA;
	this->parentsB = parentsB;
}

vector<Car> EvolutionaryService::crossoverParents()
{
	vector<Car> newPopulation;

	// TODO - crossover parentsA and parentsB and generate newPopulation

	return newPopulation;
}

vector<Car> EvolutionaryService::mutateNewPopulation(vector<Car> newPopulation) 
{
	vector<Car> mutatedPopulation;

	// TODO - mutate newPopualtion and return mutatedPopulation

	return mutatedPopulation;
}

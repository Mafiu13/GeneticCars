#ifndef EVOLUTIONARYSERVICE_H 
#define EVOLUTIONARYSERVICE_H

#include "IndividualService.h"
#include <memory>
#include <iostream>

using namespace std;
/**
* \class EvolutionaryService
*
* \brief Serwis implementujacy algorytm ewolucyjny
*
*/
class EvolutionaryService
{
public:
	/**
	* Konstruktor EvolutionaryService
	* \param populationSize rozmiar populacji
	* \param mutationRate stopien mutacji
	*
	*/
	EvolutionaryService(int const populationSize, float const mutationRate);
	~EvolutionaryService();

	/**
	* Metoda tworzy pierwsza populacje
	*
	*/
	vector<Car> createFirstPopulation();

	/**
	* Metoda tworzy nastepna populacje na podstawie poprzedniej
	* \param previousPopulation poprzednia populacja
	*
	*/
	vector<Car> createNextPopulation(const vector<Car> previousPopulation);

	/**
	* Metoda zwraca najdluzsza przejechana trase w podanej populacji
	* \param population populacja w ktorej szukamy najdluzszej trasy
	*
	*/
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
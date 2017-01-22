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
	EvolutionaryService(const int& populationSize, const float& mutationRate);
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
	vector<Car> createNextPopulation(const vector<Car>& previousPopulation);

	/**
	* Metoda zwraca najdluzsza przejechana trase w podanej populacji
	* \param population populacja w ktorej szukamy najdluzszej trasy
	*
	*/
	float getBestCarDistanceInPopulation(const vector<Car>& population);

private:

	const int populationSize_;
	
	IndividualService individualService_;
	RandomService randomService_;

	vector<Car> parentsA_;
	vector<Car> parentsB_;

	void generateParentsForNextPopulation(const vector<Car>& previousPopulation);
	vector<float> getPopulationScores(const vector<Car>& population);
	int getCarIndexFromRoulletteWheel(const vector<float>& roulletteWheel);
	vector<Car> crossoverParents();
	vector<Car> mutateNewPopulation(const vector<Car>& newPopulation);
};

#endif
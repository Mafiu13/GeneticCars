#ifndef POPULATIONMANAGER_H 
#define POPULATIONMANAGER_H

#include "EvolutionaryService.h"
class PopulationManager;
typedef boost::shared_ptr <PopulationManager> PPopulationManager;

/**
* \class PopulationManager
*
* \brief Menadzer populacji
*
*/
class PopulationManager
{
public:
	/**
	* Konstruktor PopulationManager
	* \param populationSize rozmiar populacji
	* \param mutationRate stopien mutacji
	*
	*/
	PopulationManager(int const populationSize, float const mutationRate);
	~PopulationManager();

	/**
	* Metoda zwraca pierwsza populacje
	*
	*/
	vector<Car> generateInitialPopulation();

	/**
	* Metoda zwraca nastepna populacje na podstwie aktualnej
	* \param currentPopulation aktualna populacja 
	*
	*/
	vector<Car> generateNextPopulation(const vector<Car> currentPopulation);

	/**
	* Metoda zwraca najlepszy dotychczas przejechany dystnas ze wszystkich poprzednich populacji oraz 
	* nr populacji w ktorej on wystapil
	* \param populationWithDistance aktualna populacja z pojazdami ktore przebyly juz trase
	*
	*/
	pair<float, int> getBestCarInfo(const vector<Car> populationWithDistance);

private:
	const int populationSize;

	EvolutionaryService evolutionaryService;

	pair<float, int> bestCarInfo;
	int currentPopulationNr;
};

#endif
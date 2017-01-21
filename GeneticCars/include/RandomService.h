#ifndef RANDOMSERVICE_H 
#define RANDOMSERVICE_H

#include <random>

using namespace std;

/**
* \class RandomService
*
* \brief Serwis generujacy losowe wartosci
*
*/
class RandomService
{
public:
	/**
	* Konstruktor RandomService
	*
	*/
	RandomService();
	~RandomService();

	/**
	* Metoda zwraca losowego intigera
	*
	*/
	int getRandomInt(int min, int max);

	/**
	* Metoda zwraca losowego double
	*
	*/
	double getRandomDouble(double min, double max);

	/**
	* Metoda zwraca losowego floata
	*
	*/
	float getRandomFloat(float min, float max);

private:
	random_device randomDevice;
	mt19937 randomEngine;
};

#endif
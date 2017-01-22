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
	int getRandomInt(const int& min, const int& max);

	/**
	* Metoda zwraca losowego double
	*
	*/
	double getRandomDouble(const double& min, const double& max);

	/**
	* Metoda zwraca losowego floata
	*
	*/
	float getRandomFloat(const float& min, const float& max);

private:
	random_device randomDevice_;
	mt19937 randomEngine_;
};

#endif
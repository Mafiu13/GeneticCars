#ifndef CAR_H 
#define CAR_H

#include "CarConst.h"
#include "Chromosome.h"

/**
* \class Car
*
* \brief Pojazd
*
*/
class Car
{
public:
	/**
	* Konstruktor Car
	* \param chromosome chromosom pojazdu
	*
	*/
	Car(const Chromosome& chromosome);
	~Car();
	Chromosome getChromosome() const;
	float getDistance() const;
	void setDistance(const float& distance);
private:
	Chromosome chromosome_;
	float distance_;
};

#endif
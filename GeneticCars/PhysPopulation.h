#ifndef PHYSPOPULATION_H 
#define PHYSPOPULATION_H

#include<Box2D/Box2D.h>
#include "CarConst.h"
#include "PhysCar.h"
#include "Car.h"
#include "PhysTrack.h"
#include <iostream>
/**
* \class PhysPopulation
* Klasa odpowiadajaca populacji pojazdow,
*
*/
typedef boost::shared_ptr <PhysCar> PPhysCar;

class PhysPopulation
{
	/**
	* Wektor sprytnych wskaznikow na pojazdy
	*/
	std::vector<PPhysCar> cars_;
	/**
	* ilosc wierzcholkow pojazdow
	*/
	int vec_;

public:
	PhysPopulation();
	~PhysPopulation();
	std::vector<PPhysCar> getCars() const;
	void setCars(std::vector<PPhysCar>);
	/**
	* Metoda zwracajaca polozenie najszybszego pojazdu
	*/
	float getTheFastestX() const;
	/**
	* Metoda zwracajaca auto do sledzenia
	*/
	float getFollowX() const;
	/**
	* Metoda uaktualniajaca predkosc aut
	*/
	void updateVelocity();
	/**
	* Metoda tworzaca auta w silniku fizycznym
	*/
	void createCars(b2World&);
};

#endif
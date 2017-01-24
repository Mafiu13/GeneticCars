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
class PhysPopulation;
typedef boost::shared_ptr <PhysPopulation> PPhysPopulation;

class PhysPopulation
{
	/**
	* Wektor sprytnych wskaznikow na pojazdy
	*/
	std::vector<PPhysCar> cars_;
        /**
	* Wartosc predkosci obrotowej kol pojazdow
	*/
        float velocity_;

public:
	PhysPopulation();
	~PhysPopulation();
        /**
	* Metoda zwracajaca wektor wskznikow na pojazdy
	*/
	std::vector<PPhysCar> getCars() const;
        /**
	* Metoda ustawiajaca wektor wskaznikow pojazdow
	* @param cars - wektor wskaznikow na auta
	*/
	void setCars(std::vector<PPhysCar> cars);
        /**
	* Metoda ustawiajaca predkosc katowa kol pojazdow
	* @param vaule - wartosc predkosci obrotowej
	*/
        void setVelocity(const float& value);
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
	* @param world - symulowany swiat fizyczny
	*/
	void createCars(b2World* world);
        /**
	* Metoda usuwajaca pojazdy z symulowanego swiata fizycznego
	* @param world - referencja na symulowany swia
	*/
        void destroyCars(b2World* world);
};

#endif

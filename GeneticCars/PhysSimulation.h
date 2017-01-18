#ifndef PHYSSIMULATION_H 
#define PHYSSIMULATION_H
#include <boost/shared_ptr.hpp>

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <boost/smart_ptr/make_unique.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include "PhysWheel.h"
#include "PhysTrack.h"
#include "PhysBodyShape.h"
#include "ShapePoint.h"
#include "PhysCar.h"
#include "Drawing.h"
#include "const.h"
#include "PhysPopulation.h"
#include "Car.h"

/**
*\class PhysSimulation
* Klasa odpowiadajaca symululowanemu swiatu fizycznego, w ktorym istnieja pojazdy i trasa
*
*/
typedef boost::shared_ptr<PhysPopulation> PPhysPopulation;
typedef boost::shared_ptr<PhysTrack> PPhysTrack;
typedef boost::shared_ptr<b2World> Pb2World;
typedef boost::shared_ptr<Drawing> PDrawing;
class PhysSimulation
{
	/**
	* Sprytny wskaznik na populacje pojazdow
	*/
	PPhysPopulation population_;
	/**
	* Sprytny wskaznik na wygenerowana trase
	*/
	PPhysTrack track_;
	/**
	* Sprytny wskaznik na swiat silnika fizycznego
	*/
	Pb2World world_;
	/**
	* Sprytny wskaznik na obiekt rysunku, przechowujacego rysunki dla pojazdow
	*/
	PDrawing drawing_;
	/**
	* Parametry silnika fizycznego: czas symulacji swiata i ilosc krokow symulacji swiata
	*/
	float simTime_;
	int simSteps_;
	/**
	* te dwie wartosci maja wplyw na dokladnosc symulacji. Im wieksze wartosci, tym fizyka bedzie dokladniejsza, ale wolniejsza
	*/
	int velocityIt_;
	int positionIt_;
	/**
	* grawitacja w silniku
	*/
	float gravity_;
	/**
	* parametry trasy: h1 - przedzial wysokosci, h0 - wysokosc poczatkowa, d - dlugosc odcinka
	*/
	int h1_;
	int h2_;
	int d_;
	int n_;
	/**
	* parametry trasy: h1 - przedzial wysokosci, h0 - wysokosc poczatkowa, d - dlugosc odcinka
	*/
public:
	PhysSimulation();
	~PhysSimulation();
	PhysPopulation* getPopulation() const;
	PDrawing getDrawing() const;
	b2World* getWorld() const;
	int getSimSteps() const;
	void setPopulation(PPhysPopulation);
	void setWorldParams(float, float, int, int, int);
	void setTrackParams(int, int, int, int);
	/**
	* metoda tworzaca trase 
	*/
	void createTrack();
	/**
	* Metoda tworzaca ssilnik fizyczny i wszystkie jego ciala
	*/
	void createSimulation();
	/**
	* uaktualnienie obiektow symulacji
	*/
	void updateSimulation();
};

#endif
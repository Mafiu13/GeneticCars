#ifndef PHYSSIMULATION_H
#define PHYSSIMULATION_H
#include <boost/shared_ptr.hpp>

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <memory>
#include <boost/smart_ptr/make_unique.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include "PhysWheel.h"
#include "PhysTrack.h"
#include "PhysBodyShape.h"
#include "ShapePoint.h"
#include "PhysCar.h"
#include "Drawing.h"
#include "CarConst.h"
#include "PhysPopulation.h"
#include "Car.h"

/**
*\class PhysSimulation
* Klasa odpowiadajaca symululowanemu swiatu fizycznego, w ktorym istnieja pojazdy i trasa
*
*/
class PhysSimulation;
typedef boost::shared_ptr <PhysSimulation> PPhysSimulation;
typedef boost::shared_ptr <b2World> Pb2World;

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
	* parametry trasy: h1 - przedzial wysokosci, h0 - wysokosc poczatkowa, d - dlugosc odcinka, n - ilosc odcinkow
	*/
	int h1_;
	int h2_;
	int d_;
	int n_;

public:
	PhysSimulation();
	~PhysSimulation();
	PhysPopulation* getPopulation() const;
	PDrawing getDrawing() const;
	b2World* getWorld() const;
	int getSimSteps() const;
	void setPopulation(PPhysPopulation);
	void setWorldParams(float g, float time, int steps, int vel, int pos);
	/**
	* ustawienie parametrow trasy
	* @param delta_h - wysokosc uskokow
	* @param h0 - wysokosc bazowa
	* @param d - dlugosc odcinkow trasy
	* @param n - liczba odcinkow trasy (dlugosc trasy n*d)
	*/
	void setTrackParams(int delta_h, int h0, int d, int n);
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

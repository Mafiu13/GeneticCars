#ifndef PHYSTRACK_H
#define PHYSTRACK_H

#include <boost/smart_ptr/make_unique.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <Box2D/Box2D.h>
#include <ctime>
#include <random>
#include <memory>
#include "CarConst.h"
#include "PhysElement.h"

/**
* \class PhysTrack
* Klasa odpowiadajaca trasie, po ktorej poruszaja sie pojazdy
*
*/
class PhysTrack;
typedef boost::shared_ptr <PhysTrack> PPhysTrack;

class PhysTrack : public PhysElement
{
	/**
	* tablica sprytnych wskaznikow na wierzcholki trasy
	*/
	std::unique_ptr<b2Vec2[]> arr_;
	/**
	* liczba wierzcholkow
	*/
	int n_;

public:
        PhysTrack(const int& n);
	~PhysTrack();
        /**
        * metoda zwracajaca tablice wierzcholkow trasy
        */
	b2Vec2 * getArr() const;
        /**
        * metoda zwracajaca liczbe wierzcholkow trasy
        */
	int getN() const;
	/**
	* metoda generujaca generujaca trase na podstawie podanych parametrow
	* @param delta_h - przedzial wysokosci / maksymalna wysokosc uskokow trasy
	* @param h0 - wysokosc bazowa podloza
	* @param d - dlugosc tworzonego odcinka drogi
	*/
	void generateTrack(int delta_h, int h0, int d);
	/**
	* metoda tworzaca trase w silniku fizycznym
	*/
	void createTrack(b2World & world, int n);
};

#endif

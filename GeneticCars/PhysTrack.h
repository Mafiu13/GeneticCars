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
	PhysTrack(int);
	~PhysTrack();
	b2Vec2 * getArr() const;
	int getN() const;
	/**
	* metoda generujaca generujaca trase na podstawie podanych parametrow
	*/
	void generateTrack(int, int, int, int);
	/**
	* metoda tworzaca trase w silniku fizycznym
	*/
	void createTrack(b2World &, int);
};

#endif
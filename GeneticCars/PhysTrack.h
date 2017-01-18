#ifndef PHYSTRACK_H 
#define PHYSTRACK_H

#include <boost/smart_ptr/make_unique.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <Box2D/Box2D.h>
#include <ctime>
#include <random>
#include <memory>
#include "const.h"
#include "PhysElement.h"

class PhysTrack : public PhysElement
{
	//tablica sprytnych wskaznikow do stworzenia trasy
	//tablica, a nie wektor bo tablicy wymaga konstruktor obiektu z biblioteki box2d
	std::unique_ptr<b2Vec2[]> arr;

public:
	PhysTrack();
	~PhysTrack();

	b2Vec2 * getArr();

	void createTrack(b2World &);
	void generateTrack(int, int, int);
};

#endif
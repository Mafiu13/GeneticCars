#ifndef TRACK_PH_H 
#define TRACK_PH_H

#include <boost\smart_ptr\make_unique.hpp>
#include <boost\smart_ptr\shared_ptr.hpp>
#include <Box2D\Box2D.h>
#include <ctime>
#include <random>
#include <memory>
#include "const.h"
#include "Element_ph.h"

class Track_ph: public Element_ph
{
	//tablica sprytnych wskaznikow do stworzenia trasy
	//tablica, a nie wektor bo tablicy wymaga konstruktor obiektu z biblioteki box2d
	std::unique_ptr<b2Vec2[]> arr;

public:
	Track_ph();
	~Track_ph();

	b2Vec2 * getArr();

	void createTrack(b2World &);
	void generateTrack(int h1, int h2, int d);
};

#endif
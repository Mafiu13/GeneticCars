#ifndef DRAWING_H 
#define DRAWING_H

#include <SFML/Graphics.hpp>
#include "PhysCar.h"
#include "PhysTrack.h"
#include "PhysWheel.h"
#include "PhysBodyShape.h"
#include "CarConst.h"

/**
*\class Drawing
* Klasa odpowiadajaca wszelkich rysowanym obiektom
*
*/
class Drawing;
typedef boost::shared_ptr <Drawing> PDrawing;

class Drawing
{
	/**
	* wektor rysowanych kol
	*/
	std::vector<sf::CircleShape> circles_;
	/**
	* wektor rysowanych wielokatow
	*/
	std::vector<sf::ConvexShape> polygons_;
	/**
	* Obiekt odpowiadajcy wygenerowanej trasie
	*/
	sf::VertexArray line_;

public:
	Drawing();
	~Drawing();
	std::vector<sf::CircleShape> getCircle() const;
	std::vector<sf::ConvexShape> getPolygons() const;
	sf::VertexArray getLine() const;
	/**
	* Metoda rysujaca obiekt odpowiadajacy trasie
	*/
	void drawTrack(PhysTrack * track);
	/**
	* Metoda rysujaca kola pojazdow
	* @param ko³o do narysowania
	*/
	sf::CircleShape drawCircle(PhysWheel * wheel);
	/**
	* Metoda rysujaca nadwozia pojazdow
	* @param nadwozie do narysowania
	*/
	sf::ConvexShape drawPolygon(PhysBodyShape * bodyShape);
	/**
	* Metoda rysujaca pojedynczy pojazd
	*/
	void drawCar(PhysCar * car);
	/**
	* Metoda rysujaca pojazdy z calej populacji
	* @param wektor pokazdow
	*/
	void drawCars(std::vector<PPhysCar> cars);
};

#endif
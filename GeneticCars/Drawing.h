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

typedef boost::shared_ptr <PhysCar> PPhysCar;
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
	void drawTrack(PhysTrack *);
	/**
	* Metoda rysujaca kola pojazdow
	*/
	sf::CircleShape drawCircle(PhysWheel *);
	/**
	* Metoda rysujaca nadwozia pojazdow
	*/
	sf::ConvexShape drawPolygon(PhysBodyShape *);
	/**
	* Metoda rysujaca pojedynczy pojazd
	*/
	void drawCar(PhysCar *);
	/**
	* Metoda rysujaca pojazdy z calej populacji
	*/
	void drawCars(std::vector<PPhysCar>);
};

#endif
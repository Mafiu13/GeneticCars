#ifndef DRAWING_H 
#define DRAWING_H

#include <SFML/Graphics.hpp>
#include "PhysCar.h"
#include "PhysTrack.h"
#include "PhysWheel.h"
#include "PhysBodyShape.h"
#include "const.h"

typedef boost::shared_ptr <PhysCar> CarSh;
class Drawing
{
	std::vector<sf::CircleShape> circles;
	std::vector<sf::ConvexShape> polygons;
	sf::VertexArray line;

public:
	Drawing();
	~Drawing();
	std::vector<sf::CircleShape> getCircle();
	std::vector<sf::ConvexShape> getPolygons();
	sf::VertexArray getLine();
	void drawTrack(PhysTrack *);
	sf::CircleShape drawCircle(PhysWheel *);
	sf::ConvexShape drawPolygon(PhysBodyShape *);
	void drawCar(PhysCar *);
	void drawCars(std::vector<CarSh>);
};

#endif
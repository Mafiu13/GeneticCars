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
public:
	Drawing();
	~Drawing();
	
	void drawTrack(PhysTrack *, sf::RenderWindow &);
	sf::CircleShape drawCircle(PhysWheel *);
	sf::ConvexShape drawPolygon(PhysBodyShape *);
	void drawCar(PhysCar *, sf::RenderWindow &);
	void drawCars(std::vector<CarSh>, sf::RenderWindow &);
};

#endif
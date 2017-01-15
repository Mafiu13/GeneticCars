#ifndef DRAWING_H 
#define DRAWING_H

#include <SFML/Graphics.hpp>
#include "Car_ph.h"
#include "Track_ph.h"
#include "Wheel_ph.h"
#include "BodyShape_ph.h"
#include "const.h"

typedef boost::shared_ptr <Car_ph> CarSh;
class Drawing
{
public:
	Drawing();
	~Drawing();
	
	void drawTrack(Track_ph *, sf::RenderWindow &);
	sf::CircleShape drawCircle(Wheel_ph *);
	sf::ConvexShape drawPolygon(BodyShape_ph *);
	void drawCar(Car_ph *, sf::RenderWindow &);
	void drawCars(std::vector<CarSh>, sf::RenderWindow &);
};

#endif
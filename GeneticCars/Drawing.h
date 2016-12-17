#pragma once
#include <SFML/Graphics.hpp>
#include "Track_ph.h"
#include "Wheel_ph.h"
#include "BodyShape_ph.h"

class Drawing
{
public:
	Drawing();
	~Drawing();

	sf::VertexArray drawTrack(Track_ph * track);
	sf::CircleShape drawCircle(Wheel_ph * circle, sf::Color col);
	sf::ConvexShape drawPolygon(BodyShape_ph * polygon, sf::Color col);
};


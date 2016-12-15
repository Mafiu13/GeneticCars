#include "Drawing.h"

const int SCALE = 50;

Drawing::Drawing()
{
}


Drawing::~Drawing()
{
}

sf::VertexArray Drawing::drawTrack(Track_ph * track)
{
	sf::VertexArray track_drawing(sf::Lines, 2 * N);
	int j = 0;

	for (int i = 0; i < 2 * N; i += 2) {
		j = i / 2;
		track_drawing[i].position = sf::Vector2f(track->getTab()[j].x * SCALE, track->getTab()[j].y * SCALE);
		track_drawing[i].color = sf::Color::Black;
	}
	for (int i = 1; i < 2 * N; i += 2) {
		j = (i + 1) / 2;
		track_drawing[i].position = sf::Vector2f(track->getTab()[j].x * SCALE, track->getTab()[j].y * SCALE);
		track_drawing[i].color = sf::Color::Black;
	}

	return track_drawing;
}

sf::CircleShape Drawing::drawCircle(BodyShape_ph * circle, sf::Color col)
{
	float r = circle->getBody()->GetFixtureList()->GetShape()->m_radius * SCALE;
	sf::CircleShape sf_circle(r);
	sf_circle.setOrigin(r, r);
	sf_circle.setPosition(circle->getBody()->GetPosition().x * SCALE, circle->getBody()->GetPosition().y * SCALE);
	sf_circle.setFillColor(col);

	return sf_circle;
}

sf::ConvexShape Drawing::drawPolygon(BodyShape_ph * bodyShape, sf::Color col)
{
	sf::ConvexShape polygon;
	polygon.setPointCount(8);
	for (int i = 0; i < 8; ++i) {
		polygon.setPoint(i, sf::Vector2f(bodyShape->getVertices()[i].x, bodyShape->getVertices()[i].y));
	}
	polygon.setOrigin(0, 0);
	polygon.setFillColor(col);

	return polygon;
}

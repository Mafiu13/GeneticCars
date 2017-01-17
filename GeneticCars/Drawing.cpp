#include "Drawing.h"

Drawing::Drawing()
{
}

Drawing::~Drawing()
{
}

std::vector<sf::CircleShape> Drawing::getCircle()
{
	return circles;
}

std::vector<sf::ConvexShape> Drawing::getPolygons()
{
	return polygons;
}

void Drawing::drawCar(PhysCar * car)
{
	b2Vec2 pos;
	sf::CircleShape circle;
	for (WheelSh wheel : car->getWheels()) {
		circle = this->drawCircle(wheel.get());
		pos = wheel->getBody()->GetPosition();
		circle.setPosition(pos.x*SCALE, pos.y*SCALE);
		circles.push_back(circle);
	}

	sf::ConvexShape polygon = this->drawPolygon(car->getBodyShape());

	pos = car->getBodyShape()->getBody()->GetPosition();
	polygon.setPosition(pos.x*SCALE, pos.y*SCALE);
	
	polygons.push_back(polygon);
}

void Drawing::drawCars(std::vector<CarSh> cars)
{
	circles.clear();
	polygons.clear();
	for (CarSh car : cars) {
		this->drawCar(car.get());
	}
}

sf::VertexArray Drawing::getLine()
{
	return line;
}

void Drawing::drawTrack(PhysTrack * track)
{
	sf::VertexArray track_drawing(sf::Lines, 2 * N);
	int j = 0;

	for (int i = 0; i < 2 * N; i += 2) {
		j = i / 2;
		track_drawing[i].position = sf::Vector2f(track->getArr()[j].x * SCALE, track->getArr()[j].y * SCALE);
		track_drawing[i].color = sf::Color::Black;
	}
	for (int i = 1; i < 2 * N; i += 2) {
		j = (i + 1) / 2;
		track_drawing[i].position = sf::Vector2f(track->getArr()[j].x * SCALE, track->getArr()[j].y * SCALE);
		track_drawing[i].color = sf::Color::Black;
	}

	line = track_drawing;
}

sf::CircleShape Drawing::drawCircle(PhysWheel * circle)
{
	int transparency = (int)(200 * (circle->getDensity()) + 50);
	float r = circle->getRadius() * SCALE;
	sf::CircleShape sf_circle(r);
	sf_circle.setOrigin(r, r);
	sf_circle.setPosition(circle->getBody()->GetPosition().x * SCALE, circle->getBody()->GetPosition().y * SCALE);
	sf_circle.setFillColor(sf::Color(0,0,200,transparency));

	return sf_circle;
}

sf::ConvexShape Drawing::drawPolygon(PhysBodyShape * bodyShape)
{
	int transparency = (int)(200 * (bodyShape->getDensity()) + 50);
	sf::ConvexShape polygon;
	polygon.setPointCount(V);
	for (int i = 0; i < V; ++i) {
		polygon.setPoint(i, sf::Vector2f(bodyShape->getVertices()[i].x * SCALE, bodyShape->getVertices()[i].y * SCALE));
	}
	polygon.setOrigin(0, 0);
	polygon.setRotation(bodyShape->getBody()->GetAngle()*RADDEG);
	polygon.setFillColor(sf::Color(200, 0, 0,transparency));

	return polygon;
}

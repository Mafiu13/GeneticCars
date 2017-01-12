#include "Drawing.h"

Drawing::Drawing()
{
}

Drawing::~Drawing()
{
}

void Drawing::drawCar(Car_ph * car, sf::RenderWindow & app)
{
	sf::CircleShape circle_1 = this->drawCircle(car->getWheel_1());
	sf::CircleShape circle_2 = this->drawCircle(car->getWheel_2());
	sf::ConvexShape polygon = this->drawPolygon(car->getBodyShape());

	b2Vec2 pos;

	pos = car->getWheel_1()->getBody()->GetPosition();
	circle_1.setPosition(pos.x*SCALE, pos.y*SCALE);
	app.draw(circle_1);

	pos = car->getWheel_2()->getBody()->GetPosition();
	circle_2.setPosition(pos.x*SCALE, pos.y*SCALE);
	app.draw(circle_2);
	
	pos = car->getBodyShape()->getBody()->GetPosition();
	polygon.setPosition(pos.x*SCALE, pos.y*SCALE);
	app.draw(polygon);
}

void Drawing::drawCars(std::vector<std::shared_ptr<Car_ph>> vec, sf::RenderWindow & app)
{
	for (int i = 0; i < vec.size(); ++i) {
		this->drawCar(vec[i].get(), app);
	}
}

void Drawing::drawTrack(Track_ph * track, sf::RenderWindow & app)
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

	app.draw(track_drawing);
}

sf::CircleShape Drawing::drawCircle(Wheel_ph * circle)
{
	int transparency = (int)(200 * (circle->getDensity()) + 50);
	float r = circle->getRadius() * SCALE;
	sf::CircleShape sf_circle(r);
	sf_circle.setOrigin(r, r);
	sf_circle.setPosition(circle->getBody()->GetPosition().x * SCALE, circle->getBody()->GetPosition().y * SCALE);
	sf_circle.setFillColor(sf::Color(0,0,200,transparency));

	return sf_circle;
}

sf::ConvexShape Drawing::drawPolygon(BodyShape_ph * bodyShape)
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

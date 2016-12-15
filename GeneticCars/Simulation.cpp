#include "Simulation.h"

Simulation::Simulation()
{
}


Simulation::~Simulation()
{
}
//testowa symulacja
void Simulation::createSimulation()
{
	float time = 1.0f; // nasz œwiat bêdziemy symulowaæ przez sekundê
	int steps = 100; // podzielenie symulacji na 100 krokow
	float timeStep = time / steps; // aktualizacja fizyki co 1/100 sekundy.
								   // te dwie wartosci maja wplyw na dokladnosc symulacji. Im wieksze wartosci, tym fizyka bedzie dokladniejsza, ale wolniejsza
	int velocityIt = 8, positionIt = 3; // autor Box2d zaleca wartoœci 8 i 3

	b2Vec2 Gravity(0.f, 1.0f); // wektor grawitacji o wartosci 0.05
	b2World World(Gravity); // tworzenie siata

	Track_ph * track = new Track_ph();
	track->generateTrack(50, 300, 50);
	track->createTrack(World);

	Wheel_ph * wheel_1 = new Wheel_ph();
	wheel_1->createWheel(World, 150, 50, 24, 1, 100);

	Wheel_ph * wheel_2 = new Wheel_ph();
	wheel_2->createWheel(World, 250, 50, 24, 1, 100);

	ShapePoint w[8];
	w[0].x = -50;
	w[0].y = 50;
	w[1].x = 50;
	w[1].y = 50;
	w[2].x = 50;
	w[2].y = 50;
	w[3].x = 60;
	w[3].y = 20;
	w[4].x = 30;
	w[4].y = 10;
	w[5].x = -20;
	w[5].y = 10;
	w[6].x = -40;
	w[6].y = 10;
	w[7].x = -10;
	w[7].y = 40;


	BodyShape_ph * bodyShape = new BodyShape_ph();
	bodyShape->createBodyShape(World, 200, 0, w, 1);

	Car_ph *car = new Car_ph(wheel_1, wheel_2, bodyShape);
	ShapePoint a;
	a.x = 0;
	a.y = 0;

	car->createJoint(World, bodyShape->getBody(), wheel_1->getBody(), w[0], a);
	car->createJoint(World, bodyShape->getBody(), wheel_2->getBody(), w[2], a);

	Drawing * drawing = new Drawing();
	sf::CircleShape circle_1 = drawing->drawCircle(wheel_1, sf::Color::Blue);
	sf::CircleShape circle_2 = drawing->drawCircle(wheel_2, sf::Color::Blue);
	sf::ConvexShape polygon = drawing->drawPolygon(bodyShape, sf::Color::Red);
	sf::VertexArray lines = drawing->drawTrack(track);

	sf::RenderWindow oknoAplikacji(sf::VideoMode(800, 600, 32), "SFML - test"); //definicja okna aplikacji
	sf::View view(sf::Vector2f(400, 300), sf::Vector2f(800, 600)); //definicja podgladu view. podglad na srodku ekranu o okreslonej wielkosci
	oknoAplikacji.setView(view);

	b2Vec2 pos;
	while (oknoAplikacji.isOpen())
	{
		for (int i = 0; i < steps; i++)
		{
			World.Step(timeStep, velocityIt, positionIt); // Symulacja swiata			  
			sf::Event zdarzenie;
			oknoAplikacji.clear(sf::Color::White);
			while (oknoAplikacji.pollEvent(zdarzenie))
			{
				if (zdarzenie.type == sf::Event::Closed)
				{
					oknoAplikacji.close();
				}
				if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				{
					//obsluga zdarzenia wcisniecia ESC
					oknoAplikacji.close();
				}
			}


			//	pos = triangle->getBody()->GetPosition();
			//sf_triangle.setPosition(pos.x*SCALE, pos.y*SCALE);
			//	oknoAplikacji.draw(sf_triangle);

			pos = wheel_1->getBody()->GetPosition();
			circle_1.setPosition(pos.x*SCALE, pos.y*SCALE);
			oknoAplikacji.draw(circle_1);

			pos = wheel_2->getBody()->GetPosition();
			circle_2.setPosition(pos.x*SCALE, pos.y*SCALE);
			oknoAplikacji.draw(circle_2);

			pos = bodyShape->getBody()->GetPosition();
			polygon.setPosition(pos.x*SCALE, pos.y*SCALE);
			oknoAplikacji.draw(polygon);


			oknoAplikacji.draw(lines);

			oknoAplikacji.display();

			view.setCenter(pos.x*SCALE, 300);
			oknoAplikacji.setView(view);
		}
	}
}

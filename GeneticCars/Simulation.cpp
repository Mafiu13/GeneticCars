#include "Simulation.h"


Simulation::Simulation()
{
}

Simulation::~Simulation()
{
}
std::vector<std::shared_ptr<Car_ph>> Simulation::getCars()
{
	return cars;
}


//testowa symulacja
void Simulation::createSimulation()
{
	//-----------------------parametry silnika fizycznego---------------------------------
	float time = 1.0f; // nasz œwiat bêdziemy symulowaæ przez sekundê
	int steps = 100; // podzielenie symulacji na 100 krokow
	float timeStep = time / steps; // aktualizacja fizyki co 1/100 sekundy.
								   // te dwie wartosci maja wplyw na dokladnosc symulacji. Im wieksze wartosci, tym fizyka bedzie dokladniejsza, ale wolniejsza
	int velocityIt = 8, positionIt = 3; // autor Box2d zaleca wartoœci 8 i 3

	b2Vec2 Gravity(0.f, 1.0f); // wektor grawitacji o wartosci 0.05
	b2World World(Gravity); // tworzenie siata
	//-----------------------tworzenie obiektow swiata------------------------------------
	std::unique_ptr<Track_ph> track (new Track_ph());
	track->generateTrack(50, 300, 50);
	track->createTrack(World);

	boost::shared_ptr<Wheel_ph> wheel_1 (new Wheel_ph());
	wheel_1->createWheel(World, 3, 1, 0.5, 0.8, 100);
	boost::shared_ptr<Wheel_ph> wheel_2 (new Wheel_ph());
	wheel_2->createWheel(World, 5, 1, 0.5, 0.8, 100);

	boost::shared_ptr<Wheel_ph> wheel_3(new Wheel_ph());
	wheel_3->createWheel(World, 3, 1, 0.5, 0.1, 5);
	boost::shared_ptr<Wheel_ph> wheel_4(new Wheel_ph());
	wheel_4->createWheel(World, 5, 1, 0.5, 0.1, 5);

	//-----------------tablica z punktami nadwozia ---------------------------------------
	std::vector<std::unique_ptr<b2Vec2>> tab;
	tab.push_back(std::make_unique<b2Vec2>(-1, 1));
	tab.push_back(std::make_unique<b2Vec2>(1, 1));
	tab.push_back(std::make_unique<b2Vec2>(1, 1));
	tab.push_back(std::make_unique<b2Vec2>(1.2, 0.4));
	tab.push_back(std::make_unique<b2Vec2>(0.6, 0.2));
	tab.push_back(std::make_unique<b2Vec2>(-0.4, 0.2));
	tab.push_back(std::make_unique<b2Vec2>(-0.8, 0.2));
	tab.push_back(std::make_unique<b2Vec2>(-0.2, 0.8));

	boost::shared_ptr<BodyShape_ph> bodyShape (new BodyShape_ph());
	bodyShape->setVertices(tab);
	bodyShape->createBodyShape(World, 4, 0, 0.2);

	boost::shared_ptr<BodyShape_ph> bodyShape_2(new BodyShape_ph());
	bodyShape_2->setVertices(tab);
	bodyShape_2->createBodyShape(World, 4, 0, 0.7);

	std::shared_ptr<Car_ph> car (new Car_ph());
	car->setParts(wheel_1, wheel_2, bodyShape);
	car->setJointPoints(-1, 1, 1, 1);
	car->createJoints(World);

	std::shared_ptr<Car_ph> car_2(new Car_ph());
	car_2->setParts(wheel_3, wheel_4, bodyShape_2);
	car_2->setJointPoints(-1, 1, 1, 1);
	car_2->createJoints(World);
	
	this->cars.push_back(car);
	this->cars.push_back(car_2);

	Drawing * drawing = new Drawing();
	

	sf::RenderWindow oknoAplikacji(sf::VideoMode(800, 600, 32), "SFML - test"); //definicja okna aplikacji
	sf::View view(sf::Vector2f(400, 300), sf::Vector2f(800, 600)); //definicja podgladu view. podglad na srodku ekranu o okreslonej wielkosci
	oknoAplikacji.setView(view);
	

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

			//drawing->drawCar(car.get(), oknoAplikacji);
			drawing->drawCars(cars, oknoAplikacji);

			drawing->drawTrack(track.get(), oknoAplikacji);

			oknoAplikacji.display();

			view.setCenter(this->getTheFastestX() * SCALE, 300);
			oknoAplikacji.setView(view);
		}
	}
}

float Simulation::getTheFastestX()
{
	float first = 0;
	for (int i = 0; i < cars.size(); ++i) {
		if (cars[i].get()->getBodyShape()->getBody()->GetPosition().x > first && cars[i].get()->getBodyShape()->getBody()->GetPosition().y < 20) {
			first = cars[i].get()->getBodyShape()->getBody()->GetPosition().x;
		}
	}
	return first;
}

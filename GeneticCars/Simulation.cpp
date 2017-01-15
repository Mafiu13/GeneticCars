#include "Simulation.h"


Simulation::Simulation()
{
	world = std::shared_ptr<World_ph>(new World_ph());
}

Simulation::~Simulation()
{
}

World_ph * Simulation::getWorld_ph()
{
	return world.get();
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

	//b2Vec2 Gravity(0.f, 1.0f); // wektor grawitacji o wartosci 0.05
	//b2World World(Gravity); // tworzenie siata
	//-----------------------tworzenie obiektow swiata------------------------------------
	b2World *world = this->getWorld_ph()->getWorld();
	std::unique_ptr<Track_ph> track (new Track_ph());
	track->generateTrack(50, 300, 50);

	track->createTrack(*world);


	Drawing * drawing = new Drawing();
	
	sf::RenderWindow oknoAplikacji(sf::VideoMode(800, 600, 32), "SFML - test"); //definicja okna aplikacji
	sf::View view(sf::Vector2f(400, 300), sf::Vector2f(800, 600)); //definicja podgladu view. podglad na srodku ekranu o okreslonej wielkosci
	oknoAplikacji.setView(view);
	
	while (oknoAplikacji.isOpen())
	{
		for (int i = 0; i < steps; i++)
		{
			world->Step(timeStep, velocityIt, positionIt); // Symulacja swiata			  
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

			this->getWorld_ph()->updateVelocity();

			//drawing->drawCar(car.get(), oknoAplikacji);
			drawing->drawCars(this->getWorld_ph()->getCars(), oknoAplikacji);

			drawing->drawTrack(track.get(), oknoAplikacji);

			oknoAplikacji.display();

			view.setCenter(this->getWorld_ph()->getTheFastestX() * SCALE, 300);
			oknoAplikacji.setView(view);
		}
	}
}

void Simulation::setCars_phFromCars(std::vector<Car> cars)
{
	world->setCars(this->convertCarToCar_ph(cars));
}

std::vector<CarSh> Simulation::convertCarToCar_ph(std::vector<Car> cars)
{
	std::vector<CarSh> cars_ph;
	std::vector<WheelSh> w;
	WheelSh wheel;
	BodyShape_ph shape;
	for (int i = 0; i < cars.size(); ++i) {
		w.clear();
		cars_ph.push_back(CarSh(new Car_ph()));
		cars_ph[i]->setBodyShape(boost::shared_ptr<BodyShape_ph>(new BodyShape_ph()));
		cars_ph[i]->getBodyShape()->setDensity(cars[i].getChromosome().getBodyShape().getDensity());
		cars_ph[i]->getBodyShape()->setVert(cars[i].getChromosome().getBodyShape().getShapePoints());
		for (Wheel wh : cars[i].getChromosome().getWheels()) {
			wheel = WheelSh(new Wheel_ph());
			wheel->setDensity(wh.getDensity());
			wheel->setRadius(wh.getRadius());
			wheel->setJointPoint(wh.getShapePoint());
			w.push_back(wheel);
		}
		cars_ph[i]->setWheels(w);
	}
	return cars_ph;
}




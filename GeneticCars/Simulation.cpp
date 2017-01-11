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

	/*
	boost::shared_ptr<Wheel_ph> wheel_1 (new Wheel_ph());
	wheel_1->createWheel(*world, 3, 1.5, 0.8, 100);
	boost::shared_ptr<Wheel_ph> wheel_2 (new Wheel_ph());
	wheel_2->createWheel(*world, 5, 1.5, 0.8, 100);

	boost::shared_ptr<Wheel_ph> wheel_3(new Wheel_ph());
	wheel_3->createWheel(*world, 3, 1, 0.1, 5);
	boost::shared_ptr<Wheel_ph> wheel_4(new Wheel_ph());
	wheel_4->createWheel(*world, 5, 1, 0.1, 5);

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
	bodyShape->createBodyShape(*world, 4, 0, 0.2);

	boost::shared_ptr<BodyShape_ph> bodyShape_2(new BodyShape_ph());
	bodyShape_2->setVertices(tab);
	bodyShape_2->createBodyShape(*world, 4, 0, 0.7);

	std::shared_ptr<Car_ph> car (new Car_ph());
	car->setParts(wheel_1, wheel_2, bodyShape);
	car->setJointPoints(-1, 1, 1, 1);
	car->createJoints(*world);

	std::shared_ptr<Car_ph> car_2(new Car_ph());
	car_2->setParts(wheel_3, wheel_4, bodyShape_2);
	car_2->setJointPoints(-1, 1, 1, 1);
	car_2->createJoints(*world);

	std::vector<std::shared_ptr<Car_ph>> cars;
	
	cars.push_back(car);
	cars.push_back(car_2);
	world->setCars(cars);
	*/

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
			drawing->drawCars(getWorld_ph()->getCars(), oknoAplikacji);

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

std::vector<std::shared_ptr<Car_ph>> Simulation::convertCarToCar_ph(std::vector<Car> cars)
{
	std::vector<std::shared_ptr<Car_ph>> cars_ph;
	BodyShape_ph shape;
	float a1, a2, b1, b2;
	for (int i = 0; i < cars.size(); ++i) {
		
		cars_ph.push_back(std::shared_ptr<Car_ph>(new Car_ph()));
		cars_ph[i]->setBodyShape(boost::shared_ptr<BodyShape_ph>(new BodyShape_ph()));
		cars_ph[i]->getBodyShape()->setDensity(cars[i].getChromosome().getBodyShape().getDensity());
		cars_ph[i]->getBodyShape()->setVert(cars[i].getChromosome().getBodyShape().getShapePoints());
		cars_ph[i]->setWheel(boost::shared_ptr<Wheel_ph>(new Wheel_ph()), 1);
		cars_ph[i]->getWheel_1()->setDensity(cars[i].getChromosome().getWheels()[0].getDensity());
		cars_ph[i]->getWheel_1()->setRadius(cars[i].getChromosome().getWheels()[0].getRadius());
		cars_ph[i]->setWheel(boost::shared_ptr<Wheel_ph>(new Wheel_ph()), 2);
		cars_ph[i]->getWheel_2()->setDensity(cars[i].getChromosome().getWheels()[1].getDensity());
		cars_ph[i]->getWheel_2()->setRadius(cars[i].getChromosome().getWheels()[1].getRadius());
		a1 = cars[i].getChromosome().getWheels()[0].getShapePoint().getX();
		a2 = cars[i].getChromosome().getWheels()[0].getShapePoint().getX();
		b1 = cars[i].getChromosome().getWheels()[1].getShapePoint().getY();
		b2 = cars[i].getChromosome().getWheels()[1].getShapePoint().getY();
		cars_ph[i]->setJointPoints(a1,a2,b1,b2);
	}
	return cars_ph;
}




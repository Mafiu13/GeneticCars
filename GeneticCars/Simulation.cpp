#include "Simulation.h"


Simulation::Simulation()
{
	b2Vec2 g(0, Gravity);
	world = boost::make_shared<b2World>(g);
	population = boost::make_shared<Population>();
}

Simulation::~Simulation()
{
}

Population * Simulation::getPopulation()
{
	return population.get();
}

b2World * Simulation::getWorld()
{
	return world.get();
}

void Simulation::setPopulation(boost::shared_ptr<Population> p)
{
	population = p;
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
	//-----------------------tworzenie obiektow swiata------------------------------------

	track = boost::make_shared<Track_ph>();
	track->generateTrack(50, 300, 50);
	track->createTrack(*this->world.get());

	drawing = boost::make_shared<Drawing>();
	
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

			population->updateVelocity();
			drawing->drawCars(population->getCars(), oknoAplikacji);
			drawing->drawTrack(track.get(), oknoAplikacji);

			oknoAplikacji.display();

			view.setCenter(population->getTheFastestX() * SCALE, 300);
			oknoAplikacji.setView(view);
		}
	}
}




#include "PhysSimulation.h"
#include "PhysPopulation.h"
#include "PopulationManager.h"
#include "AppWindow.h"
#include <iostream>

int main()
{
	// Krotki opis dzialania - PopulationManager

	const int size = 10; // rozmiar populacji 
	const float rate = 0.0; // wspolczynnik mutacji od 0.0 - 1.0 - im wiekszy tym wieksza sznasa na mutacje, przy 0 nie ma mutacji
	PopulationManager *pm = new PopulationManager(size, rate); // robisz managera do populacji
	std::vector<Car> inPop = pm->generateInitialPopulation(); // generujesz pierwsza populacje ( z randomowymi wartosciami w carach)
	float lel = 1.0;
	for (Car &car : inPop)
	{	
		Chromosome ch = car.getChromosome();
		BodyShape bs = ch.getBodyShape();
		std::cout << "density: " << bs.getDensity() << " ";
		car.setDistance(lel);
		lel += 1.0;
		std::cout << "disatnce: " << car.getDistance() << "\n";
	}
	std::cout << "\n";
	// //Nie uzywaj tego jeszcze, nie dziala dobrze ;/
	pair<float, int> bci = pm->getBestCarInfo(inPop); // zwraca ci najlepszy samocho z wszytskich dotychczasowych populacji wlacznie z ta ktora podajesz/ wazne musisz podac populacje carow z wstawionymi wartosciami distance inaczej wybuchnie
	std::vector<Car> newPop = pm->generateNextPopulation(inPop); // dajesz w parametrze poprzednia populacje z wstawionymi wartosciami distance i dostajesz nowa populacje / dalej uzywasz juz tej metody i tworzysz kolejne populacje
	for (Car &car : newPop)
	{
		Chromosome ch = car.getChromosome();
		BodyShape bs = ch.getBodyShape();
		std::cout << "density: " << bs.getDensity() << " ";
		car.setDistance(lel);
		lel += 1.0;
		std::cout << "disatnce: " << car.getDistance() << "\n";
	}

	for (int i = 0; i < inPop.size(); ++i) {
		for (int j = 0; j < NR_OF_POINTS_IN_BODYSHAPE; ++j) {
			std::cout << '[' << i << ']' << "  " << '[' << j << ']'<< inPop[i].getChromosome().getBodyShape().getShapePoints()[j].getX() << "  " << inPop[i].getChromosome().getBodyShape().getShapePoints()[j].getY() << std::endl;
		}
		std::cout << "Kolo1  " << inPop[i].getChromosome().getWheels()[0].getShapePoint().getX() << "  " << inPop[i].getChromosome().getWheels()[0].getShapePoint().getY() << std::endl;
		std::cout << "Kolo2  " << inPop[i].getChromosome().getWheels()[1].getShapePoint().getX() << "  " << inPop[i].getChromosome().getWheels()[1].getShapePoint().getY() << std::endl;
		std::cout << std::endl;
	}

	for (int i = 0; i < newPop.size(); ++i) {
		//for (int j = 0; j < NR_OF_POINTS_IN_BODYSHAPE; ++j) {
			//std::cout << '[' << i << ']' << "  " << '[' << j << ']' << newPop[i].getChromosome().getBodyShape().getShapePoints()[j].getX() << "  " << newPop[i].getChromosome().getBodyShape().getShapePoints()[j].getY() << std::endl;
		//}
		//std::cout << "Kolo3" << newPop[i].getChromosome().getWheels()[0].getShapePoint().getX() << "  " << newPop[i].getChromosome().getWheels()[0].getShapePoint().getY() << std::endl;
		//std::cout << "Kolo4" << newPop[i].getChromosome().getWheels()[1].getShapePoint().getX() << "  " << newPop[i].getChromosome().getWheels()[1].getShapePoint().getY() << std::endl;
		//std::cout << std::endl;
	}

	boost::shared_ptr<AppWindow> window = boost::make_shared<AppWindow>(800, 600, 32, "Genetic cars");
	boost::shared_ptr<PhysSimulation> simulation = boost::make_shared<PhysSimulation>(1.0,100,8,3);
	
	simulation->createTrack(50, 300, 100);
	simulation->getPopulation()->setCars_phFromCars(inPop);
	simulation->getPopulation()->createCars(*simulation->getWorld());
	simulation->createSimulation();
	
	while (window->getWindow().isOpen()) {
		for (int i = 0; i < simulation->getSimSteps(); ++i) {
			sf::Event zdarzenie;
			while (window->getWindow().pollEvent(zdarzenie))
			{
				if (zdarzenie.type == sf::Event::Closed)
					window->getWindow().close();
				if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
					window->getWindow().close();//obsluga zdarzenia wcisniecia ESC	
			}
			simulation->updateSimulation();
			window->drawAll(simulation->getDrawing());
			window->getWindow().display();
			window->getView().setCenter(sf::Vector2f(simulation->getPopulation()->getTheFastestX() * SCALE, 300));
			window->setViewToWindow();
		}
	}
}
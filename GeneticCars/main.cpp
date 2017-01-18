#include "PhysSimulation.h"
#include "PhysPopulation.h"
#include "PopulationManager.h"
#include "AppWindow.h"
#include "MainController.h"
#include <iostream>

typedef boost::shared_ptr <MainController> PMainController;

int main()
{
	// Krotki opis dzialania - PopulationManager
	const int size = 6; // rozmiar populacji 
	const float rate = 0.0; // wspolczynnik mutacji od 0.0 - 1.0 - im wiekszy tym wieksza sznasa na mutacje, przy 0 nie ma mutacji
	boost::shared_ptr<PopulationManager> pm = boost::make_shared<PopulationManager>(size, rate); // robisz managera do populacji
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
	pair<float, int> bci = pm->getBestCarInfo(inPop); // zwraca ci najlepszy samochod z wszystkich dotychczasowych populacji wlacznie z ta ktora podajesz/ wazne musisz podac populacje carow z wstawionymi wartosciami distance inaczej wybuchnie
	std::vector<Car> newPop;

	boost::shared_ptr<MainController> controller = boost::make_shared<MainController>();
	boost::shared_ptr<AppWindow> window = boost::make_shared<AppWindow>(800, 600, 32, "Genetic cars");
	boost::shared_ptr<PhysSimulation> simulation = boost::make_shared<PhysSimulation>(1.0,100,8,3);
	
	simulation->createTrack(50, 300, 100);
	simulation->createSimulation();

	controller->setSimulation(simulation);
	controller->setPopulationManager(pm);
	controller->setWindow(window);
	controller->getSimualation()->getPopulation()->setCars(controller->convertPhysCarToCar(newPop));
	simulation->getPopulation()->createCars(*simulation->getWorld());

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
			if (controller->finishCheck() == true) {
				for (int i = 0; i < inPop.size(); ++i)
				{
					inPop[i].setDistance(controller->getDistances()[i]);
				}
				newPop.clear();
				newPop = controller->getPopulationManager()->generateNextPopulation(inPop);
				controller->getSimualation()->getPopulation()->setCars(controller->convertPhysCarToCar(newPop));
				simulation->getPopulation()->createCars(*simulation->getWorld());
				inPop = newPop;
			}
			controller->simulatePupulation();
		}
	}
}
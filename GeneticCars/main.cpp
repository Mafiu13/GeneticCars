#include "Simulation.h"
#include "PopulationManager.h"
#include <iostream>

int main()
{
	// Krotki opis dzialania - PopulationManager

	const int size = 2; // rozmiar populacji 
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
	//Car bestCar = pm->getBestCar(inPop); // zwraca ci najlepszy samocho z wszytskich dotychczasowych populacji wlacznie z ta ktora podajesz/ wazne musisz podac populacje carow z wstawionymi wartosciami distance inaczej wybuchnie
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

	boost::shared_ptr<Simulation> simulation(new Simulation());
	simulation->setCars_phFromCars(inPop);
	simulation->getWorld_ph()->createCars();
	simulation->createSimulation();
}
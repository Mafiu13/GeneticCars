#include "Simulation.h"
#include "PopulationManager.h"
#include <iostream>

int main()
{
	//Simulation * s = new Simulation();
	//s->createSimulation();

	// Krotki opis dzialania - PopulationManager

	const int size = 4; // rozmiar populacji 
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
}
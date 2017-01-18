#ifndef MAINCONTROLLER_H 
#define MAINCONTROLLER_H

#include <boost/shared_ptr.hpp>
#include "PhysSimulation.h"
#include "PopulationManager.h"
#include "AppWindow.h"

/**
*\class MainController
* Klasa odpowiadajaca kontrolerowi ³aczacemu model fizyczny i model ewolucyjny, a takze widok
*
*/

class MainController;
typedef boost::shared_ptr <MainController> PMainController;

class MainController
{
	/**
	* Sprytny wskaznik na obiekt symulacji silnika fizycznego
	*/
	PPhysSimulation simulation_;
	/**
	* sprytny wskaznik na menagera populacji
	*/
	PPopulationManager populationManager_;
	/**
	* Sprytny wskaznik na okno aplikacji
	*/
	PAppWindow window_;
	/**
	* Wektor symulowanych pojazdow
	*/
	std::vector<Car> inPop_;
	/**
	* Wektor pojazdow otrzymanych w kolejnej generacji
	*/
	std::vector<Car> nextPop_;
public:
	MainController();
	MainController(int, float);
	~MainController();
	PPhysSimulation getSimualation() const;
	PPopulationManager getPopulationManager() const;
	PAppWindow getWindow() const;
	std::vector<Car> getInPop() const;
	void setSimulation(PPhysSimulation);
	void setPopulationManager(PPopulationManager);
	void setWindow(PAppWindow);
	void setInPop(std::vector<Car>);
	/**
	* Metoda konwertujaca pojazdy modelu ewolucyjnego na pojazdy wykorzystywane w silniku fizycznym
	*/
	std::vector<PPhysCar> convertPhysCarToCar(std::vector<Car>);
	/**
	* Metoda zwracajaca wektor odleglosci pojazdow
	*/
	std::vector<float> getDistancesFromPhysCars();
	/**
	* Metoda uruchamiajaca symulacje populacji
	*/
	void simulatePupulation();
	/**
	* Metoda sprawdzajaca czy symulacja dla danej populacji powinna sie zakonczyc
	*/
	bool finishCheck();
	/**
	* Metoda tworzaca wszystkie obiekty
	*/
	void createAll();
	/**
	* Metoda wpisujaca osiagniete dystanse poszczegolnym pojazdom
	*/
	void setDistancesToCars();
	/**
	* Uruchamiajaca glowna symulacje
	*/
	void runAll();
};

#endif
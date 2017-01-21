#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <boost/shared_ptr.hpp>
#include "PhysSimulation.h"
#include "PopulationManager.h"
#include "AppWindow.h"

typedef boost::shared_ptr <PhysSimulation> PPhysSimulation;
typedef boost::shared_ptr <PopulationManager> PPopulationManager;
typedef boost::shared_ptr <AppWindow> PAppWindow;
/**
*\class MainController
* Klasa odpowiadajaca kontrolerowi ³aczacemu model fizyczny i model ewolucyjny, a takze widok
*
*/
class MainController
{
    /**
    * Sprytny wskaznik na obiekt symulacji silnika fizycznego
    */
    PPhysSimulation simulation_;
    /**
    * sprytny wskaznik na menagera populacji
    */
    PPopulationManager population_manager_;
    /**
    * Sprytny wskaznik na okno aplikacji
    */
    PAppWindow window_;
    /**
    * Liczba symulowanych generacji w populacji
    */
    int max_gen_;
    /**
    * Rozmiar populacji
    */
    int gen_size_;
    /**
    * Wskaznik mutacji
    */
    float rate_;
    /**
    * Numer obecnej generacji
    */
    int current_gen_;
    /**
    * Wektor symulowanych pojazdow
    */
    std::vector<Car> in_pop_;
    /**
    * Wektor pojazdow otrzymanych w kolejnej generacji
    */
    std::vector<Car> next_pop_;
public:
	MainController();
	~MainController();
	PPhysSimulation getSimualation();
	PPopulationManager getPopulationManager();
	PAppWindow getWindow();
	void setSimulation(PPhysSimulation);
	void setPopulationManager(PPopulationManager);
	void setWindow(PAppWindow);
    void setMaxGen(int);
    void setSize(int);
    void setRate(float);
    int getMaxGen();
    int getSize();
    float getRate();
    std::vector<Car> getInPop();
    void setInPop(std::vector<Car>);
    /**
    * Metoda konwertujaca pojazdy modelu ewolucyjnego na pojazdy wykorzystywane w silniku fizycznym
    */
    std::vector<PPhysCar> convertPhysCarToCar(std::vector<Car>);
    /**
    * Metoda zwracajaca wektor odleglosci pojazdow
    */
	std::vector<float> getDistances();
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
	void setDistances();
    /**
    * Uruchamiajaca glowna symulacje
    */
	void runAll();
};

#endif

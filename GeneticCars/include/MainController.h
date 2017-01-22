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
    /**
    * Metoda zwracajaca wskaznik na symulacje
    */
    PPhysSimulation getSimualation();
    /**
    * Metoda zwracajaca wskaznik na menagera populacji
    */
    PPopulationManager getPopulationManager();
    /**
    * Metoda zwracajaca wskaznik na okno aplikacji
    */
    PAppWindow getWindow();
    /**
    * Metoda zwracajaca maksymalna liczbe generowanych populacji
    */
    int getMaxGen() const;
    /**
    * Metoda zwracajaca rozmiar populacji
    */
    int getSize() const;
    /**
    * Metoda zwracajaca wspolczynnik mutacji
    */
    float getRate() const;
    /**
    * Metoda zwracajaca wektor pojazdow z algorytmu ewolucyjnego
    */
    std::vector<Car> getInPop() const;
    /**
    * Metoda ustawiajaca wskaznik symulacji
    */
    void setSimulation(PPhysSimulation simulation);
    /**
    * Metoda ustawiajaca wskaznik menadzera populacji
    */
    void setPopulationManager(PPopulationManager popManager);
    /**
    * Metoda ustawiajaca okno aplikacji
    */
    void setWindow(PAppWindow window);
    /**
    * Metoda ustawiajaca maksymalna liczbe generowania kolejnych populacji
    */
    void setMaxGen(const int& maxGen);
    /**
    * Metoda ustawiajaca rozmiar populacji
    */
    void setSize(const int& size);
    /**
    * Metoda ustawiajaca wspolczynnik mutacji
    */
    void setRate(const float& mut);
    /**
    * Metoda ustawiajacy wektor pojazdow z algorytmu ewolucyjnego
    */
    void setInPop(const std::vector<Car>& cars);
    /**
    * Metoda konwertujaca pojazdy modelu ewolucyjnego na pojazdy wykorzystywane w silniku fizycznym
    */
    std::vector<PPhysCar> convertPhysCarToCar(const std::vector<Car>& cars);
    /**
    * Metoda zwracajaca wektor przejechanych odleglosci
    */
    std::vector<float> getDistances();
    /**
    * Metoda wpisujaca osiagniete dystanse poszczegolnym pojazdom
    */
    void setDistances();
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
    * Uruchamiajaca glowna symulacje
    */
    void runAll();
};

#endif

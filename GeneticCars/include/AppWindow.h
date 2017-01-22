#ifndef APPWINDOW_H
#define APPWINDOW_H
#include <iostream>
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFML/Graphics.hpp>
#include <boost/smart_ptr/weak_ptr.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/lexical_cast/bad_lexical_cast.hpp>
#include "Drawing.h"

/**
*\class AppWindow
* Klasa odpowiadajaca oknu aplikacji
*
*/
class AppWindow;
class MainController;

typedef boost::shared_ptr <AppWindow> PAppWindow;
typedef boost::shared_ptr <MainController> PMainController;

class AppWindow
{
    /**
    * Obiekt okna z biblioteki SFML
    */
    sf::RenderWindow window_;
    /**
    * Obiekt widoku okna w którym będzie renderowana symulacja przejazdu generowancych samochodow
    */
    sf::View sim_view_;
    /**
    * Obiekt widoku okna w którym będzie renderowane GUI
    */
    sf::View default_view_;
    /**
    * Slaby sprytny wskaznik na glowny kontroler
    */
    PMainController controller_;
    /**
    * Obiekt inicjalizujący generowanie GUI
    */
    sfg::SFGUI sfgui_;
    /**
    * Nadrzedny obiekt GUI zawierajacy w sobie wszystkie widzety
    */
    sfg::Desktop desktop_;
    /**
    * Zegar wykorzystywany do aktualizacji GUI
    */
    sf::Clock clock_;
    /**
    * Sprytne wskazniki na widzety wprowadzania tekstu
    */
    sfg::Entry::Ptr size_entry_,rate_entry_,max_gen_entry_,gravity_entry_,steep_entry_,length_entry_;
    /**
    * Sprytny wskaznik na kontener z lista najlepszych osobnikow z kazdej populacji
    */
    sfg::Box::Ptr best_list_box_;
    /**
    * Sprytny wskaznik na widzet wyswietlajacy komunikaty
    */
    sfg::Label::Ptr info_label_;
    /**
    * Flaga do oznaczenia czy jest obecnie renderowana symulacja przejazdu
    */
    bool running_;
    /**
    * Metoda inicjalizujacy wszystkie widzety GUI i ich rozmieszczenie wzgledem siebie w oknie aplikacji
    */
    void setUpGUI();

public:
    /**
    * Konstruktor okna aplikacji
    * @param c - sprytny wskaznik na glowny kontroler
    * @param width - szerokosc widoku
    * @param height - wysokosc okna
    * @param bitsPerPixel - ilosc bitow na pixel, jakosc kolorow
    * @param name - nazwa aplikacji
    */
    AppWindow(PMainController c,const int& width, const int& height, const int& bitsPerPixel, const std::string& name);
    ~AppWindow();
    /**
    * Metoda zwracajaca referencje na okno
    */
    sf::RenderWindow& getWindow();
    /**
    * Metoda zwracajaca referencje na widok
    */
    sf::View& getView();
    /**
    * Metoda rysujaca wszystkie obiekty na widoku
    *@param drawing - rysunek
    */
    void drawAll(PDrawing drawing);
    /**
    * Metoda dodajaca wynik najlepszego osobnika minionej generacji
    *@param gen - numer minionej generacji
    *@param m - wynik osobnika w metrach
    */
    void updateList(const int& gen,const float& m);
    /**
    * Metoda aktualizujaca GUI
    */
    void updateGUI();
    /**
    * Metoda wyswietlajaca informacje na dolnym pasku w oknie aplikacji
    *@param info - tresc informacji
    */
    void updateInfo(const std::string& info);
    /**
    * Metoda wyswietlajaca wynik najlepszego osobnika w generacji
    *@param best - aktualny wynik najlepszego osobnika w generacji
    */
    void updateBest(const float& best);
    /**
    * Metoda uaktualniajaca pozycje widoku
    *@param follow - polozenie sledzonego pojazdu
    */
    void updateFollow(const float& follow);
    /**
    * Metoda GUI obslugujaca zdarzenia (wcisniecie przycisku, zamkniecie okna)
    *@param e - zdarzenie
    */
    void handleEvent(sf::Event e);
    /**
    * Metoda wywolywania po wcisnieciu przycisku rozpoczecia symulacji
    */
    void onRunButtonClick();
    /**
    * Metoda zatrzymujaca symulacje
    */
    void stopSimulation();
    /**
    * Metoda zwracajaca czy jest obecnie renderowana symulacja przejazdu
    */
    bool isRunning();
    /**
    * Metoda czyszczaca liste najlepszych osobnikow
    */
    void clearList();
};

#endif

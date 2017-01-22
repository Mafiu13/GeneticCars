#ifndef APPWINDOW_H 
#define APPWINDOW_H

#include <boost/smart_ptr/weak_ptr.hpp>
#include <SFML/Graphics.hpp>
#include "Drawing.h"

/**
*\class AppWindow
* Klasa odpowiadajaca oknu aplikacji
*
*/
class AppWindow;
class MainController;

typedef boost::weak_ptr <MainController> WPMainController;
typedef boost::shared_ptr <AppWindow> PAppWindow;

class AppWindow
{
	/**
	* Obiekt okna z biblioteki SFML
	*/
	sf::RenderWindow window_;
	/**
	* Obiekt widoku okna
	*/
	sf::View view_;
	/**
	* Slaby sprytny wskaznik na glowny kontroler
	*/
	WPMainController controller_;

public:
	/**
	* Konstruktor okna aplikacji
	* @param c - sprytny wskaznik na glowny kontroler
	* @param width - szerokosc widoku
	* @param height - wysokosc okna
	* @param bitsPerPixel - ilosc bitow na pixel, jakosc kolorow
	* @param name - nazwa aplikacji
	*/
	AppWindow(boost::shared_ptr<MainController> c, float width, float height, int bitsPerPixel, std::string name);
	~AppWindow();
	sf::RenderWindow & getWindow();
	sf::View & getView();
	/**
	* Metoda rysujaca wszystkie obiekty na widoku
	*@param drawing - rysunek
	*/
	void drawAll(boost::shared_ptr<Drawing> drawing);
	/**
	* Uaktualnienie widoku okna
	*/
	void setViewToWindow();
};

#endif
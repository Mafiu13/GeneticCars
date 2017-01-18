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
	AppWindow(boost::shared_ptr<MainController>);
	~AppWindow();
	AppWindow(boost::shared_ptr<MainController>, float, float, int, std::string);
	sf::RenderWindow & getWindow();
	sf::View & getView();
	/**
	* Metoda rysujaca wszystkie obiekty na widoku
	*/
	void drawAll(boost::shared_ptr<Drawing>);
	/**
	* Uaktualnienie widoku okna
	*/
	void setViewToWindow();

};

#endif
#ifndef APPWINDOW_H 
#define APPWINDOW_H

#include <SFML/Graphics.hpp>
#include "Drawing.h"

class MainController;

class AppWindow
{
	sf::RenderWindow window; //definicja okna aplikacji
	sf::View view;
	boost::shared_ptr<MainController> controller;

public:
	AppWindow(boost::shared_ptr<MainController>);
	~AppWindow();
	AppWindow(boost::shared_ptr<MainController>,int,int,int,std::string);
	sf::RenderWindow & getWindow();
	sf::View & getView();
	void drawAll(boost::shared_ptr<Drawing>);
	void setViewToWindow();

};

#endif
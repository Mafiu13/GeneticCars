#ifndef APPWINDOW_H 
#define APPWINDOW_H

#include <SFML/Graphics.hpp>
#include "Drawing.h"

class AppWindow
{
	sf::RenderWindow window; //definicja okna aplikacji
	sf::View view;
public:
	AppWindow();
	~AppWindow();
	AppWindow(int,int,int,std::string);
	sf::RenderWindow & getWindow();
	sf::View & getView();
	void drawAll(boost::shared_ptr<Drawing>);
	void setViewToWindow();
};

#endif
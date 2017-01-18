#include "AppWindow.h"



AppWindow::AppWindow(boost::shared_ptr<MainController> c)
{
	controller = c;
}

AppWindow::~AppWindow()
{
}


AppWindow::AppWindow(boost::shared_ptr<MainController> c, int width, int height, int bitsPerPixel, std::string name)
{
	window.create(sf::VideoMode(width, height, bitsPerPixel), name);
	view.setCenter(sf::Vector2f(width / 2, height / 2));
	view.setSize(sf::Vector2f(width, height));
	window.setView(view);
	controller = c;
}

sf::RenderWindow & AppWindow::getWindow()
{
	return window;
}

sf::View & AppWindow::getView()
{
	return view;
}

void AppWindow::drawAll(boost::shared_ptr<Drawing> drawing)
{
	window.clear(sf::Color::White);
	window.draw(drawing->getLine());
	for (sf::CircleShape circle : drawing->getCircle()) {
		window.draw(circle);
	}
	for (sf::ConvexShape polygon : drawing->getPolygons()) {
		window.draw(polygon);
	}
}

void AppWindow::setViewToWindow()
{
	window.setView(view);
}




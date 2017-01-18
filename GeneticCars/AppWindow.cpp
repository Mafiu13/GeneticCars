#include "AppWindow.h"



AppWindow::AppWindow(boost::shared_ptr<MainController> c)
{
	controller_ = c;
}

AppWindow::~AppWindow()
{
}

AppWindow::AppWindow(boost::shared_ptr<MainController> c, float width, float height, int bitsPerPixel, std::string name)
{
	window_.create(sf::VideoMode(width, height, bitsPerPixel), name);
	view_.setCenter(sf::Vector2f(width / 2, height / 2));
	view_.setSize(sf::Vector2f(width, height));
	window_.setView(view_);
	controller_ = c;
}

sf::RenderWindow & AppWindow::getWindow()
{
	return window_;
}

sf::View & AppWindow::getView()
{
	return view_;
}

void AppWindow::drawAll(boost::shared_ptr<Drawing> drawing)
{
	window_.clear(sf::Color::White);
	window_.draw(drawing->getLine());
	for (sf::CircleShape circle : drawing->getCircle()) {
		window_.draw(circle);
	}
	for (sf::ConvexShape polygon : drawing->getPolygons()) {
		window_.draw(polygon);
	}
}

void AppWindow::setViewToWindow()
{
	window_.setView(view_);
}




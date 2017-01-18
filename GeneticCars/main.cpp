#include "PhysSimulation.h"
#include "PhysPopulation.h"
#include "PopulationManager.h"
#include "AppWindow.h"
#include "MainController.h"
#include <iostream>


int main()
{
	PMainController controller = boost::make_shared<MainController>(6,0);
	boost::shared_ptr<AppWindow> window = boost::make_shared<AppWindow>(controller,800, 600, 32, "Genetic cars");
	controller->setWindow(window);
	controller->getSimualation()->setWorldParams(5.0, 1.0, 100, 8, 3);
	controller->getSimualation()->setTrackParams(100, 400, 50, 50);
	controller->createAll();

	while (controller->getWindow()->getWindow().isOpen()) {
		controller->runAll();
	}
}
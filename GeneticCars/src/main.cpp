#include "PhysSimulation.h"
#include "PhysPopulation.h"
#include "PopulationManager.h"
#include "AppWindow.h"
#include "MainController.h"
#include <iostream>

typedef boost::shared_ptr <MainController> PMainController;

int main()
{
    PMainController controller = boost::make_shared<MainController>();
    boost::shared_ptr<AppWindow> window = boost::make_shared<AppWindow>(controller, 1200, 800, 32, "Genetic cars");
	controller->setWindow(window);

    while (controller->getWindow()->getWindow().isOpen()) {
		controller->runAll();
	}
}

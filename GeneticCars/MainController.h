#ifndef MAINCONTROLLER_H 
#define MAINCONTROLLER_H

#include <boost/shared_ptr.hpp>
#include "PhysSimulation.h"
#include "PopulationManager.h"

class MainController
{
	boost::shared_ptr<PhysSimulation> simulation;
	boost::shared_ptr<PopulationManager> manager;
public:
	MainController();
	~MainController();
	std::vector<CarSh> convertPhysCarToCar(std::vector<Car>);
};

#endif
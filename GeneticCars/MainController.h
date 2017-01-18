#ifndef MAINCONTROLLER_H 
#define MAINCONTROLLER_H

#include <boost/shared_ptr.hpp>
#include "PhysSimulation.h"
#include "PopulationManager.h"
#include "AppWindow.h"

typedef boost::shared_ptr <PhysSimulation> PPhysSimulation;
typedef boost::shared_ptr <PopulationManager> PPopulationManager;
typedef boost::shared_ptr <AppWindow> PAppWindow;
class MainController
{
	PPhysSimulation simulation;
	PPopulationManager populationManager;
	PAppWindow window;
public:
	MainController();
	~MainController();
	PPhysSimulation getSimualation();
	PPopulationManager getPopulationManager();
	PAppWindow getWindow();
	void setSimulation(PPhysSimulation);
	void setPopulationManager(PPopulationManager);
	void setWindow(PAppWindow);
	std::vector<CarSh> convertPhysCarToCar(std::vector<Car>);
	std::vector<float> getDistances();
	void simulatePupulation();
	bool finishCheck();
};

#endif
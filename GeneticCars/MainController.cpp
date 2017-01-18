#include "MainController.h"



MainController::MainController()
{
}

MainController::MainController(int size, float rate)
{
	populationManager = boost::make_shared<PopulationManager>(size, rate);
	simulation = boost::make_shared<PhysSimulation>();
}


MainController::~MainController()
{
}

PPhysSimulation MainController::getSimualation()
{
	return simulation;
}

PPopulationManager MainController::getPopulationManager()
{
	return populationManager;
}

PAppWindow MainController::getWindow()
{
	return window;
}

void MainController::setSimulation(PPhysSimulation s)
{
	simulation = s;
}

void MainController::setPopulationManager(PPopulationManager p)
{
	populationManager = p;
}

void MainController::setWindow(PAppWindow w)
{
	window = w;
}

std::vector<CarSh> MainController::convertPhysCarToCar(std::vector<Car> cars)
{
	std::vector<CarSh> physCars;
	std::vector<WheelSh> w;
	WheelSh wheel;
	PhysBodyShape shape;
	for (int i = 0; i < cars.size(); ++i) {
		w.clear();
		physCars.push_back(boost::make_shared<PhysCar>());
		physCars[i]->setBodyShape(boost::make_shared<PhysBodyShape>());
		physCars[i]->getBodyShape()->setDensity(cars[i].getChromosome().getBodyShape().getDensity());
		physCars[i]->getBodyShape()->setVert(cars[i].getChromosome().getBodyShape().getShapePoints());
		for (Wheel wh : cars[i].getChromosome().getWheels()) {
			wheel = boost::make_shared<PhysWheel>();
			wheel->setDensity(wh.getDensity());
			wheel->setRadius(wh.getRadius());
			wheel->setJointPoint(wh.getShapePoint());
			w.push_back(wheel);
		}
		physCars[i]->setWheels(w);
	}
	return physCars;
}

std::vector<float> MainController::getDistances()
{
	std::vector<float> out;
	for (CarSh car: simulation->getPopulation()->getCars()) {
		out.push_back(car->getBodyShape()->getBody()->GetPosition().x);
	}
	return out;
}

void MainController::simulatePupulation()
{
	simulation->updateSimulation();
	window->drawAll(simulation->getDrawing());
	window->getWindow().display();
	window->getView().setCenter(sf::Vector2f(simulation->getPopulation()->getTheFastestX() * SCALE, 300));
	window->setViewToWindow();
}

bool MainController::finishCheck()
{
	bool finish = false;
	if (simulation->getPopulation()->getTheFastestX() > 0) {
		finish = true;
	}
	for (CarSh car : simulation->getPopulation()->getCars()) {
		if (car->getBodyShape()->getBody()->GetLinearVelocity().x > 0.01 || abs(car->getBodyShape()->getBody()->GetLinearVelocity().y) > 0.01)
			finish = false;
	}
	return finish;
}

void MainController::createAll()
{
	simulation->createSimulation();

	inPop = populationManager->generateInitialPopulation();
	getSimualation()->getPopulation()->setCars(convertPhysCarToCar(inPop));
	simulation->getPopulation()->createCars(*simulation->getWorld());
}

void MainController::setSize(int i)
{
	size = i;
}

void MainController::setRate(float f)
{
	rate = f;
}

int MainController::getSize()
{
	return size;
}

float MainController::getRate()
{
	return rate;
}

std::vector<Car> MainController::getInPop()
{
	return inPop;
}

void MainController::setInPop(std::vector<Car> c)
{
	inPop = c;
}

void MainController::setDistances()
{
	for (int i = 0; i < inPop.size(); ++i)
	{
		inPop[i].setDistance(getDistances()[i]);
	}
}

void MainController::runAll()
{
	for (int i = 0; i < simulation->getSimSteps(); ++i) {
		sf::Event zdarzenie;
		while (window->getWindow().pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
				window->getWindow().close();
			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				window->getWindow().close();//obsluga zdarzenia wcisniecia ESC	
		}
		if (finishCheck() == true) {
			setDistances();
			nextPop.clear();
			nextPop = populationManager->generateNextPopulation(inPop);
			simulation->getPopulation()->setCars(convertPhysCarToCar(nextPop));
			simulation->getPopulation()->createCars(*simulation->getWorld());
			setInPop(nextPop);
		}
		simulatePupulation();
	}
}


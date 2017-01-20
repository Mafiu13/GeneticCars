#include "MainController.h"



MainController::MainController()
{
}

MainController::MainController(int size, float rate)
{
	populationManager_ = boost::make_shared<PopulationManager>(size, rate);
	simulation_ = boost::make_shared<PhysSimulation>();
}


MainController::~MainController()
{
}

PPhysSimulation MainController::getSimualation() const
{
	return simulation_;
}

PPopulationManager MainController::getPopulationManager() const
{
	return populationManager_;
}

PAppWindow MainController::getWindow() const
{
	return window_;
}

void MainController::setSimulation(PPhysSimulation s)
{
	simulation_ = s;
}

void MainController::setPopulationManager(PPopulationManager p)
{
	populationManager_ = p;
}

void MainController::setWindow(PAppWindow w)
{
	window_ = w;
}

std::vector<PPhysCar> MainController::convertPhysCarToCar(std::vector<Car> cars)
{
	std::vector<PPhysCar> physCars;
	std::vector<PPhysWheel> w;
	PPhysWheel wheel;
	PhysBodyShape shape;
	for (int i = 0; i < cars.size(); ++i) 
	{
		w.clear();
		physCars.push_back(boost::make_shared<PhysCar>());
		physCars[i]->setBodyShape(boost::make_shared<PhysBodyShape>());
		physCars[i]->getBodyShape()->setDensity(cars[i].getChromosome().getBodyShape().getDensity());
		physCars[i]->getBodyShape()->setVerticesFromShapePoints(cars[i].getChromosome().getBodyShape().getShapePoints());
		for (Wheel wh : cars[i].getChromosome().getWheels()) 
		{
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

std::vector<float> MainController::getDistancesFromPhysCars()
{
	std::vector<float> out;
	for (PPhysCar car: simulation_->getPopulation()->getCars()) 
	{
		out.push_back(car->getBodyShape()->getBody()->GetPosition().x);
	}
	return out;
}

void MainController::simulatePupulation()
{
	simulation_->updateSimulation();
	window_->drawAll(simulation_->getDrawing());
	window_->getWindow().display();
	window_->getView().setCenter(sf::Vector2f(simulation_->getPopulation()->getFollowX() * SCALE, 300));
	window_->setViewToWindow();
}

bool MainController::finishCheck()
{
	bool finish = false;
	int cnt = 0;

	if (simulation_->getPopulation()->getTheFastestX() > 1)
		finish = true;

	do
	{
		for (PPhysCar car : simulation_->getPopulation()->getCars())
		{
			if (abs(car->getBodyShape()->getBody()->GetLinearVelocity().x) > 0.001 || (abs(car->getBodyShape()->getBody()->GetLinearVelocity().y) > 0.001))
			{
				finish = false;
				if (car->getBodyShape()->getBody()->GetPosition().y > 20)
					finish = true;
			}
		}
		if (finish == true)
			++cnt;
	} while (finish != false && cnt < 3);

	return finish;
}

void MainController::createAll()
{
	simulation_->createSimulation();

	inPop_ = populationManager_->generateInitialPopulation();
	getSimualation()->getPopulation()->setCars(convertPhysCarToCar(inPop_));
	simulation_->getPopulation()->createCars(*simulation_->getWorld());
}


std::vector<Car> MainController::getInPop() const
{
	return inPop_;
}

void MainController::setInPop(std::vector<Car> c)
{
	for (int i = 0; i < inPop_.size(); ++i) {
		inPop_[i] = c[i];
	}
}

void MainController::setDistancesToCars()
{
	std::vector<float> vec = getDistancesFromPhysCars();
	for (int i = 0; i < inPop_.size(); ++i)
	{
		inPop_[i].setDistance(vec[i]);
	}
}

void MainController::runAll()
{
	for (int i = 0; i < simulation_->getSimSteps(); ++i) 
	{
		sf::Event zdarzenie;
		while (window_->getWindow().pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::Closed)
				window_->getWindow().close();
			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
				window_->getWindow().close();//obsluga zdarzenia wcisniecia ESC	
		}
		if (finishCheck() == true) 
		{
			setDistancesToCars();
			nextPop_.clear();
			nextPop_ = populationManager_->generateNextPopulation(inPop_);
			simulation_->getPopulation()->setCars(convertPhysCarToCar(nextPop_));
			simulation_->getPopulation()->createCars(*simulation_->getWorld());
			setInPop(nextPop_);
		}
		simulatePupulation();
	}
}


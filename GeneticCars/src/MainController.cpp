#include "MainController.h"

MainController::MainController()
{
    current_gen_ = 0;
}

MainController::~MainController()
{
}

// ----------metody [get] ---------
PPhysSimulation MainController::getSimualation()
{
    return simulation_;
}

PPopulationManager MainController::getPopulationManager()
{
    return population_manager_;
}

PAppWindow MainController::getWindow()
{
    return window_;
}

int MainController::getMaxGen() const
{
    return max_gen_;
}

int MainController::getSize() const
{
    return gen_size_;
}

float MainController::getRate() const
{
    return rate_;
}

std::vector<Car> MainController::getInPop() const
{
    return in_pop_;
}

//---------metody [set] -----------
void MainController::setSimulation(PPhysSimulation s)
{
    simulation_ = s;
}

void MainController::setPopulationManager(PPopulationManager p)
{
    population_manager_ = p;
}

void MainController::setWindow(PAppWindow w)
{
    window_ = w;
}

void MainController::setMaxGen(const int& i)
{
    max_gen_=i;
}

void MainController::setSize(const int& i)
{
    gen_size_ = i;
}

void MainController::setRate(const float& f)
{
    rate_ = f;
}

void MainController::setInPop(const std::vector<Car>& c)
{
    in_pop_ = c;
}

vector<PPhysCar> MainController::convertPhysCarToCar(const std::vector<Car>& cars)
{
    std::vector<PPhysCar> physCars;
    std::vector<PPhysWheel> w;
    PPhysWheel wheel;
	PhysBodyShape shape;
	for (int i = 0; i < cars.size(); ++i) {
		w.clear();
		physCars.push_back(boost::make_shared<PhysCar>());
		physCars[i]->setBodyShape(boost::make_shared<PhysBodyShape>());
		physCars[i]->getBodyShape()->setDensity(cars[i].getChromosome().getBodyShape().getDensity());
        physCars[i]->getBodyShape()->setVerticesFromShapePoints(cars[i].getChromosome().getBodyShape().getShapePoints());
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
    for (PPhysCar car: simulation_->getPopulation()->getCars()) {
		out.push_back(car->getBodyShape()->getBody()->GetPosition().x);
	}
	return out;
}

void MainController::setDistances()
{
    for (int i = 0; i < in_pop_.size(); ++i)
    {
        in_pop_[i].setDistance(getDistances()[i]);
    }
}

void MainController::simulatePupulation()
{
    if(window_->isRunning())
    {
        simulation_->updateSimulation();
        window_->updateState(simulation_->getPopulation()->getTheFastestX(), simulation_->getPopulation()->getFollowX(),simulation_->getTrack()->getArr()[simulation_->getTrack()->getN()-1].x);
        window_->updateFollow(simulation_->getPopulation()->getFollowX());
        window_->drawAll(simulation_->getDrawing());
    }
}

bool MainController::finishCheck()
{
	bool finish = false;
    if (simulation_->getPopulation()->getTheFastestX() > 0) {
		finish = true;
	}
    for (PPhysCar car : simulation_->getPopulation()->getCars()) {
		if (car->getBodyShape()->getBody()->GetLinearVelocity().x > 0.01 || abs(car->getBodyShape()->getBody()->GetLinearVelocity().y) > 0.01)
			finish = false;
	}
	return finish;
}

void MainController::createAll()
{

    population_manager_ = boost::make_shared<PopulationManager>(gen_size_, rate_);
    simulation_->createSimulation();
    in_pop_ = population_manager_->generateInitialPopulation();
    getSimualation()->getPopulation()->setCars(convertPhysCarToCar(in_pop_));
    simulation_->getPopulation()->createCars(simulation_->getWorld());
}

void MainController::runAll()
{
        sf::Event zdarzenie;
        while (window_->getWindow().pollEvent(zdarzenie))
		{
            window_->handleEvent(zdarzenie);
			if (zdarzenie.type == sf::Event::Closed)
                window_->getWindow().close();
			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
                window_->getWindow().close();//obsluga zdarzenia wcisniecia ESC
		}
        window_->updateGUI();
        if(window_->isRunning() && current_gen_ < max_gen_)
        {
            if (finishCheck() == true) {
                window_->updateList(current_gen_,simulation_->getPopulation()->getTheFastestX());
                setDistances();
                next_pop_.clear();
                next_pop_ = population_manager_->generateNextPopulation(in_pop_);
                simulation_->getPopulation()->setCars(convertPhysCarToCar(next_pop_));
                simulation_->getPopulation()->createCars(simulation_->getWorld());
                setInPop(next_pop_);
                ++current_gen_;
            }
            simulatePupulation();
        }
		if (!window_->isRunning())
			current_gen_ = 0;
        if(current_gen_ == max_gen_)
        {
            window_->stopSimulation();
            current_gen_ = 0;
        }
}

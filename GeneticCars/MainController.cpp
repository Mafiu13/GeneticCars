#include "MainController.h"



MainController::MainController()
{
}


MainController::~MainController()
{
}

std::vector<CarSh> MainController::convertPhysCarToCar(std::vector<Car> cars)
{
	std::vector<CarSh> cars_ph;
	std::vector<WheelSh> w;
	WheelSh wheel;
	PhysBodyShape shape;
	for (int i = 0; i < cars.size(); ++i) {
		w.clear();
		cars_ph.push_back(CarSh(new PhysCar()));
		cars_ph[i]->setBodyShape(boost::shared_ptr<PhysBodyShape>(new PhysBodyShape()));
		cars_ph[i]->getBodyShape()->setDensity(cars[i].getChromosome().getBodyShape().getDensity());
		cars_ph[i]->getBodyShape()->setVert(cars[i].getChromosome().getBodyShape().getShapePoints());
		for (Wheel wh : cars[i].getChromosome().getWheels()) {
			wheel = WheelSh(new PhysWheel());
			wheel->setDensity(wh.getDensity());
			wheel->setRadius(wh.getRadius());
			wheel->setJointPoint(wh.getShapePoint());
			w.push_back(wheel);
		}
		cars_ph[i]->setWheels(w);
	}
	return cars_ph;
}
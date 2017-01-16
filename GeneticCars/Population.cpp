#include "Population.h"

Population::Population()
{
	
}


Population::~Population()
{
}

std::vector<CarSh> Population::getCars()
{
	return cars;
}

void Population::setCars(std::vector<CarSh> c)
{
	cars = c;
}

float Population::getTheFastestX()
{
	float first = 0;
	for (CarSh car : cars) {
		if (car->getBodyShape()->getBody()->GetPosition().x > first && car->getBodyShape()->getBody()->GetPosition().y < 20) {
			first = car->getBodyShape()->getBody()->GetPosition().x;
		}
	}
	return first;
}

void Population::updateVelocity()
{
	for (CarSh car : cars) {
		car->updateVelocity();
	}
}

void Population::createCars(b2World& world)
{
	for (CarSh car : this->cars) {
		car->getBodyShape()->createBodyShape(world);
		for (WheelSh wheel : car->getWheels()) {
			wheel->createWheel(world);
		}
		car->createJoints(world);
	}
}

void Population::setCars_phFromCars(std::vector<Car> cars)
{
	setCars(this->convertCarToCar_ph(cars));
}

std::vector<CarSh> Population::convertCarToCar_ph(std::vector<Car> cars)
{
	std::vector<CarSh> cars_ph;
	std::vector<WheelSh> w;
	WheelSh wheel;
	BodyShape_ph shape;
	for (int i = 0; i < cars.size(); ++i) {
		w.clear();
		cars_ph.push_back(CarSh(new Car_ph()));
		cars_ph[i]->setBodyShape(boost::shared_ptr<BodyShape_ph>(new BodyShape_ph()));
		cars_ph[i]->getBodyShape()->setDensity(cars[i].getChromosome().getBodyShape().getDensity());
		cars_ph[i]->getBodyShape()->setVert(cars[i].getChromosome().getBodyShape().getShapePoints());
		for (Wheel wh : cars[i].getChromosome().getWheels()) {
			wheel = WheelSh(new Wheel_ph());
			wheel->setDensity(wh.getDensity());
			wheel->setRadius(wh.getRadius());
			wheel->setJointPoint(wh.getShapePoint());
			w.push_back(wheel);
		}
		cars_ph[i]->setWheels(w);
	}
	return cars_ph;
}


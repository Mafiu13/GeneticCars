#include "PhysPopulation.h"

PhysPopulation::PhysPopulation()
{	
}


PhysPopulation::~PhysPopulation()
{
}

std::vector<CarSh> PhysPopulation::getCars()
{
	return cars;
}

void PhysPopulation::setCars(std::vector<CarSh> c)
{
	cars = c;
}

float PhysPopulation::getTheFastestX()
{
	float first = 0;
	for (CarSh car : cars) {
		if (car->getBodyShape()->getBody()->GetPosition().x > first && car->getBodyShape()->getBody()->GetPosition().y < 20) {
			first = car->getBodyShape()->getBody()->GetPosition().x;
		}
	}
	return first;
}

void PhysPopulation::updateVelocity()
{
	for (CarSh car : cars) {
		car->updateVelocity();
	}
}

void PhysPopulation::createCars(b2World& world)
{
	for (CarSh car : this->cars) {
		car->getBodyShape()->createBodyShape(world);
		for (WheelSh wheel : car->getWheels()) {
			wheel->createWheel(world);
		}
		car->createJoints(world);
	}
}


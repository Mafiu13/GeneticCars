#include "PhysPopulation.h"

PhysPopulation::PhysPopulation()
{	
}


PhysPopulation::~PhysPopulation()
{
}

std::vector<PPhysCar> PhysPopulation::getCars() const
{
	return cars_;
}

void PhysPopulation::setCars(std::vector<PPhysCar> cars)
{
    //cars_.clear();
	cars_ = cars;
}

float PhysPopulation::getTheFastestX() const
{
	float first = 0;
	for (PPhysCar car : cars_) {
		if (car->getBodyShape()->getBody()->GetPosition().x > first && car->getBodyShape()->getBody()->GetPosition().y < 20)
		{
			first = car->getBodyShape()->getBody()->GetPosition().x;
		}
	}
	return first;
}

float PhysPopulation::getFollowX() const
{
	float first = 0;
	for (PPhysCar car : cars_) {
		if (car->getBodyShape()->getBody()->GetPosition().x > first &&
			car->getBodyShape()->getBody()->GetPosition().y < 20 &&
			car->getBodyShape()->getBody()->GetLinearVelocity().x > 0.1)
		{
			first = car->getBodyShape()->getBody()->GetPosition().x;
		}
	}
	return first;
}

void PhysPopulation::updateVelocity()
{
	for (PPhysCar car : cars_) {
		car->updateVelocity();
	}
}

void PhysPopulation::createCars(b2World& world)
{
	for (PPhysCar car : this->cars_) {
		car->getBodyShape()->createBodyShape(world);
		for (PPhysWheel wheel : car->getWheels()) {
			wheel->createWheel(world);
		}

		car->createJoints(world);
	}
}


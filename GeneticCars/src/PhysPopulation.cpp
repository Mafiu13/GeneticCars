#include "PhysPopulation.h"

PhysPopulation::PhysPopulation()
{	
}


PhysPopulation::~PhysPopulation()
{
}

// ---------------metody [get]----------------------
std::vector<PPhysCar> PhysPopulation::getCars() const
{
	return cars_;
}

// ----------------metody [set]-------------------
void PhysPopulation::setCars(std::vector<PPhysCar> cars)
{
	cars_ = cars;
}

void PhysPopulation::setVelocity(const float& value)
{
    velocity_ = value;
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
            car->getBodyShape()->getBody()->GetLinearVelocity().x > 0.01)
        {
            first = car->getBodyShape()->getBody()->GetPosition().x;
        }
    }
    return first;
}

void PhysPopulation::updateVelocity()
{
	for (PPhysCar car : cars_) {
        car->updateVelocity(velocity_);
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

void PhysPopulation::destroyCars(b2World & world)
{
    for (PPhysCar car : this->cars_) {
        for (b2RevoluteJoint * joint : car->getJoints())
            world.DestroyJoint(joint);
        for (PPhysWheel wheel : car->getWheels())
            world.DestroyBody(wheel->getBody());
        world.DestroyBody(car->getBodyShape()->getBody());
    }
}

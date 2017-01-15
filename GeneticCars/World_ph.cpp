#include "World_ph.h"

World_ph::World_ph()
{
	b2Vec2 g(0, Gravity);
	world = std::make_unique<b2World>(g);

	//for (int i = 0; i < 4; ++i) {
	//	cars.push_back(std::make_shared<Car_ph>());
	//}
	
}


World_ph::~World_ph()
{
}

b2World * World_ph::getWorld()
{
	return world.get();
}

std::vector<CarSh> World_ph::getCars()
{
	return cars;
}

void World_ph::setCars(std::vector<CarSh> c)
{
	cars = c;
}

float World_ph::getTheFastestX()
{
	float first = 0;
	for (CarSh car : cars) {
		if (car->getBodyShape()->getBody()->GetPosition().x > first && car->getBodyShape()->getBody()->GetPosition().y < 20) {
			first = car->getBodyShape()->getBody()->GetPosition().x;
		}
	}
	return first;
}

void World_ph::updateVelocity()
{
	for (CarSh car : cars) {
		car->updateVelocity();
	}
}

void World_ph::createCars()
{
	for (CarSh car : this->cars) {
		car->getBodyShape()->createBodyShape(*getWorld());
		for (WheelSh wheel : car->getWheels()) {
			wheel->createWheel(*getWorld());
		}
		car->createJoints(*getWorld());
	}
}

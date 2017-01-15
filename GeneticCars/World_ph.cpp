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

std::vector<std::shared_ptr<Car_ph>> World_ph::getCars()
{
	return cars;
}

void World_ph::setCars(std::vector<std::shared_ptr<Car_ph>> c)
{
	cars.clear();
	for (int i = 0; i < c.size(); ++i) {
		cars.push_back(c[i]);
	}
}

float World_ph::getTheFastestX()
{
	float first = 0;
	for (int i = 0; i < cars.size(); ++i) {
		if (cars[i].get()->getBodyShape()->getBody()->GetPosition().x > first && cars[i].get()->getBodyShape()->getBody()->GetPosition().y < 20) {
			first = cars[i].get()->getBodyShape()->getBody()->GetPosition().x;
		}
	}
	return first;
}

void World_ph::updateVelocity()
{
	for (int i = 0; i < cars.size(); ++i) {
		cars[i]->updateVelocity();
	}
}

void World_ph::createCars()
{
	float x, y;
	for (int i = 0; i < cars.size(); ++i) {
		cars[i]->getBodyShape()->createBodyShape(*getWorld());
		cars[i]->getWheel_1()->createWheel(*getWorld());
		cars[i]->getWheel_2()->createWheel(*getWorld());
		cars[i]->createJoints(*getWorld());
	}
}

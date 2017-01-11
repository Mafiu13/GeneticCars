#ifndef WORLD_PH_H 
#define WORLD_PH_H

#include<Box2D\Box2D.h>
#include "const.h"
#include "Car_ph.h"
#include "Track_ph.h"
#include <iostream>

class World_ph
{
	std::shared_ptr<b2World> world;
	std::vector<std::shared_ptr<Car_ph>> cars;

public:
	World_ph();
	~World_ph();
	b2World * getWorld();
	std::vector<std::shared_ptr<Car_ph>> getCars();
	void setCars(std::vector<std::shared_ptr<Car_ph>>);
	float getTheFastestX();
	void updateVelocity();
	void createCars();
};

#endif
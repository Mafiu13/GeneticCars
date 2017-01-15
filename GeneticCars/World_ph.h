#ifndef WORLD_PH_H 
#define WORLD_PH_H

#include<Box2D\Box2D.h>
#include "const.h"
#include "Car_ph.h"
#include "Track_ph.h"
#include <iostream>

typedef boost::shared_ptr <Car_ph> CarSh;

class World_ph
{
	std::shared_ptr<b2World> world;
	std::vector<CarSh> cars;

public:
	World_ph();
	~World_ph();
	b2World * getWorld();
	std::vector<CarSh> getCars();
	void setCars(std::vector<CarSh>);
	float getTheFastestX();
	void updateVelocity();
	void createCars();
};

#endif
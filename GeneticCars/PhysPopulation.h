#ifndef PHYSPOPULATION_H 
#define PHYSPOPULATION_H

#include<Box2D\Box2D.h>
#include "const.h"
#include "PhysCar.h"
#include "Car.h"
#include "PhysTrack.h"
#include <iostream>

typedef boost::shared_ptr <PhysCar> CarSh;

class PhysPopulation
{
	std::vector<CarSh> cars;

public:
	PhysPopulation();
	~PhysPopulation();
	std::vector<CarSh> getCars();
	void setCars(std::vector<CarSh>);
	float getTheFastestX();
	void updateVelocity();
	void createCars(b2World&);
	void setCars_phFromCars(std::vector<Car>);
	std::vector<CarSh> convertCarToCar_ph(std::vector<Car>);
};

#endif
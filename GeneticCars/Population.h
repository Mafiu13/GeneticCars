#ifndef POPULATION_H 
#define POPULATION_H

#include<Box2D\Box2D.h>
#include "const.h"
#include "Car_ph.h"
#include "Car.h"
#include "Track_ph.h"
#include <iostream>

typedef boost::shared_ptr <Car_ph> CarSh;

class Population
{
	std::vector<CarSh> cars;

public:
	Population();
	~Population();
	std::vector<CarSh> getCars();
	void setCars(std::vector<CarSh>);
	float getTheFastestX();
	void updateVelocity();
	void createCars(b2World&);
	void setCars_phFromCars(std::vector<Car>);
	std::vector<CarSh> convertCarToCar_ph(std::vector<Car>);
};

#endif
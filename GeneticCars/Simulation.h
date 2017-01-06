#ifndef SIMULATION_H 
#define SIMULATION_H
#include <boost\shared_ptr.hpp>

#include <Box2D\Box2D.h>
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <boost\smart_ptr\make_unique.hpp>
#include "Wheel_ph.h"
#include "Track_ph.h"
#include "BodyShape_ph.h"
#include "ShapePoint.h"
#include "Car_ph.h"
#include "Drawing.h"
#include "const.h"

class Simulation
{
	std::vector<std::shared_ptr<Car_ph>> cars;
public:
	Simulation();
	~Simulation();
	std::vector<std::shared_ptr<Car_ph>> getCars();
	void createSimulation();
	float getTheFastestX();
};

#endif
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
#include "World_ph.h"

class Simulation
{
	
public:
	Simulation();
	~Simulation();
	
	void createSimulation();
	
};

#endif
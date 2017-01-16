#ifndef SIMULATION_H 
#define SIMULATION_H
#include <boost\shared_ptr.hpp>

#include <Box2D\Box2D.h>
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <boost\smart_ptr\make_unique.hpp>
#include <boost\smart_ptr\make_shared.hpp>
#include "Wheel_ph.h"
#include "Track_ph.h"
#include "BodyShape_ph.h"
#include "ShapePoint.h"
#include "Car_ph.h"
#include "Drawing.h"
#include "const.h"
#include "Population.h"
#include "Car.h"

class Simulation
{
	boost::shared_ptr<Population> population;
	boost::shared_ptr<Track_ph> track;
	boost::shared_ptr<b2World> world;
	boost::shared_ptr<Drawing> drawing;
	
public:
	Simulation();
	~Simulation();
	Population* getPopulation();
	b2World* getWorld();
	void setPopulation(boost::shared_ptr<Population>);
	void createSimulation();
	
};

#endif
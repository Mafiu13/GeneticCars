#ifndef PHYSSIMULATION_H 
#define PHYSSIMULATION_H
#include <boost\shared_ptr.hpp>

#include <Box2D\Box2D.h>
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <boost\smart_ptr\make_unique.hpp>
#include <boost\smart_ptr\make_shared.hpp>
#include "PhysWheel.h"
#include "PhysTrack.h"
#include "PhysBodyShape.h"
#include "ShapePoint.h"
#include "PhysCar.h"
#include "Drawing.h"
#include "const.h"
#include "PhysPopulation.h"
#include "Car.h"

class PhysSimulation
{
	boost::shared_ptr<PhysPopulation> population;
	boost::shared_ptr<PhysTrack> track;
	boost::shared_ptr<b2World> world;
	boost::shared_ptr<Drawing> drawing;
	
public:
	PhysSimulation();
	~PhysSimulation();
	PhysPopulation* getPopulation();
	b2World* getWorld();
	void setPopulation(boost::shared_ptr<PhysPopulation>);
	void createSimulation();
	
};

#endif
#ifndef PHYSSIMULATION_H 
#define PHYSSIMULATION_H
#include <boost/shared_ptr.hpp>

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <boost/smart_ptr/make_unique.hpp>
#include <boost/smart_ptr/make_shared.hpp>
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
	//parametry swiata fizycznego
	float simTime;
	int simSteps;
	// te dwie wartosci maja wplyw na dokladnosc symulacji. Im wieksze wartosci, tym fizyka bedzie dokladniejsza, ale wolniejsza
	int velocityIt;
	int positionIt;
	
public:
	PhysSimulation();
	PhysSimulation(float, int, int, int);
	~PhysSimulation();
	PhysPopulation* getPopulation();
	boost::shared_ptr<Drawing> getDrawing();
	b2World* getWorld();
	int getSimSteps();
	void setPopulation(boost::shared_ptr<PhysPopulation>);
	void createTrack(int, int, int);
	void createSimulation();
	void updateSimulation();
};

#endif
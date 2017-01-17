#include "PhysSimulation.h"


PhysSimulation::PhysSimulation()
{
	b2Vec2 g(0, Gravity);
	world = boost::make_shared<b2World>(g);
	world->Step(simTime/simSteps, velocityIt, positionIt);
	population = boost::make_shared<PhysPopulation>();
	drawing = boost::make_shared<Drawing>();
	track = boost::make_shared<PhysTrack>();
}

PhysSimulation::PhysSimulation(float time, int steps, int vel, int pos)
{
	b2Vec2 g(0, Gravity);
	world = boost::make_shared<b2World>(g);
	world->Step(simTime / simSteps, velocityIt, positionIt);
	population = boost::make_shared<PhysPopulation>();
	drawing = boost::make_shared<Drawing>();
	track = boost::make_shared<PhysTrack>();

	simTime = time;
	simSteps = steps;
	velocityIt = vel;
	positionIt = pos;
}

PhysSimulation::~PhysSimulation()
{
	population->~PhysPopulation();
}

PhysPopulation * PhysSimulation::getPopulation()
{
	return population.get();
}

boost::shared_ptr<Drawing> PhysSimulation::getDrawing()
{
	return drawing;
}

b2World * PhysSimulation::getWorld()
{
	return world.get();
}

int PhysSimulation::getSimSteps()
{
	return simSteps;
}

void PhysSimulation::setPopulation(boost::shared_ptr<PhysPopulation> p)
{
	population = p;
}

void PhysSimulation::createTrack(int h1, int h2, int d)
{
	track->generateTrack(h1, h2, d);
	track->createTrack(*this->world.get());
}


//testowa symulacja
void PhysSimulation::createSimulation()
{
	population->updateVelocity();
	drawing->drawCars(population->getCars());
	drawing->drawTrack(track.get());
}

void PhysSimulation::updateSimulation()
{
	world->Step(simTime / simSteps, velocityIt, positionIt);
	population->updateVelocity();
	drawing->drawCars(population->getCars());
}




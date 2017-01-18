#include "PhysSimulation.h"


PhysSimulation::PhysSimulation()
{
	population = boost::make_shared<PhysPopulation>();
	drawing = boost::make_shared<Drawing>();
	track = boost::make_shared<PhysTrack>();
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

void PhysSimulation::createTrack()
{
	track->generateTrack(h1, h2, d);
	track->createTrack(*this->world.get());
}

void PhysSimulation::createSimulation()
{
	b2Vec2 g(0, gravity);
	world = boost::make_shared<b2World>(g);
	world->Step(simTime / simSteps, velocityIt, positionIt);

	createTrack();

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

void PhysSimulation::setWorldParams(float g, float f, int i1, int i2, int i3)
{
	gravity = g;
	simTime = f;
	simSteps = i1;
	velocityIt = i2;
	positionIt = i3;
}

void PhysSimulation::setTrackParams(int i1, int i2, int i3)
{
	h1 = i1;
	h2 = i2;
	d = i3;
}




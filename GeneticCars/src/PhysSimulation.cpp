#include "PhysSimulation.h"


PhysSimulation::PhysSimulation()
{
	population_ = boost::make_shared<PhysPopulation>();
	drawing_ = boost::make_shared<Drawing>();
}

PhysSimulation::~PhysSimulation()
{
    destroyTrack();
    population_->destroyCars(getWorld());
}

// ------------------metody [get]----------------------
PhysPopulation * PhysSimulation::getPopulation()
{
	return population_.get();
}

PDrawing PhysSimulation::getDrawing()
{
	return drawing_;
}

b2World * PhysSimulation::getWorld()
{
	return world_.get();
}

PPhysTrack PhysSimulation::getTrack()
{
	return track_;
}

int PhysSimulation::getSimSteps() const
{
	return simSteps_;
}

//------------------- metody [set]---------------------
void PhysSimulation::setPopulation(PPhysPopulation p)
{
	population_ = p;
}

void PhysSimulation::setWorldParams(float g, float time, int steps, int vel, int pos)
{
    gravity_ = g;
    simTime_ = time;
    simSteps_ = steps;
    velocityIt_ = vel;
    positionIt_ = pos;
}

void PhysSimulation::setTrackParams(int delta_h, int h0, int d, int n)
{
    h1_ = delta_h;
    h2_ = h0;
    d_ = d;
    n_ = n;
}

void PhysSimulation::createTrack()
{
	track_ = boost::make_shared<PhysTrack>(n_);
	track_->generateTrack(h1_, h2_, d_);
	track_->createTrack(world_.get(), n_);
}

void PhysSimulation::createSimulation()
{
	b2Vec2 g(0, gravity_);
	world_ = boost::make_shared<b2World>(g);
	world_->Step(simTime_ / simSteps_, velocityIt_, positionIt_);
	createTrack();
	population_->updateVelocity();
	drawing_->drawCars(population_->getCars());
	drawing_->drawTrack(track_.get());
}

void PhysSimulation::updateSimulation()
{
	world_->Step(simTime_ / simSteps_, velocityIt_, positionIt_);
	population_->updateVelocity();
	drawing_->drawCars(population_->getCars());
}

void PhysSimulation::destroyTrack()
{
    world_.get()->DestroyBody(track_->getBody());
}




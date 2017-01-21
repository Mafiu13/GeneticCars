﻿#include "PhysSimulation.h"


PhysSimulation::PhysSimulation()
{
	population_ = boost::make_shared<PhysPopulation>();
	drawing_ = boost::make_shared<Drawing>();
}

PhysSimulation::~PhysSimulation()
{
	population_->~PhysPopulation();
}

PhysPopulation * PhysSimulation::getPopulation() const
{
	return population_.get();
}

boost::shared_ptr<Drawing> PhysSimulation::getDrawing() const
{
	return drawing_;
}

b2World * PhysSimulation::getWorld() const
{
	return world_.get();
}

int PhysSimulation::getSimSteps() const
{
	return simSteps_;
}

void PhysSimulation::setPopulation(PPhysPopulation p)
{
	population_ = p;
}

void PhysSimulation::createTrack()
{
	track_ = boost::make_shared<PhysTrack>(n_);
	track_->generateTrack(h1_, h2_, d_);
	track_->createTrack(*this->world_.get(), n_);
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





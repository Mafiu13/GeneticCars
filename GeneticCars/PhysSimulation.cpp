#include "PhysSimulation.h"


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

void PhysSimulation::setWorldParams(float g, float f, int i1, int i2, int i3)
{
	gravity_ = g;
	simTime_ = f;
	simSteps_ = i1;
	velocityIt_ = i2;
	positionIt_ = i3;
}

void PhysSimulation::setTrackParams(int i1, int i2, int i3, int i4)
{
	h1_ = i1;
	h2_ = i2;
	d_ = i3;
	n_ = i4;
}





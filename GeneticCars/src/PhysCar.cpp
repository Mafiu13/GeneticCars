#include "PhysCar.h"

PhysCar::PhysCar()
{
}

PhysCar::~PhysCar()
{
}

// --------------metody [get]--------------
std::vector<PPhysWheel> PhysCar::getWheels() const
{
	return wheels_;
}

PhysBodyShape * PhysCar::getBodyShape() const
{
	return bodyShape_.get();
}

std::vector<b2RevoluteJoint*> PhysCar::getJoints()
{
    return joints_;
}

//-------------metody [set]------------------
void PhysCar::setBodyShape(PPhysBodyShape b)
{
	bodyShape_ = b;
}

void PhysCar::setWheels(std::vector<PPhysWheel> v)
{
	wheels_ = v;
}

void PhysCar::createJoint(b2World & World, PPhysWheel wheel)
{
	b2RevoluteJointDef jointdef;

	jointdef.bodyA = bodyShape_->getBody();
	jointdef.bodyB = wheel->getBody();

	jointdef.localAnchorA.Set(wheel->getJointPoint().getX(), wheel->getJointPoint().getY());
	jointdef.localAnchorB.Set(0, 0);  
	jointdef.collideConnected = false;
	jointdef.enableLimit = false; 
	joints_.push_back((b2RevoluteJoint*)World.CreateJoint(&jointdef));
}

void PhysCar::createJoints(b2World& world)
{
	for (PPhysWheel wheel : wheels_) {
		createJoint(world, wheel);
	}
}

void PhysCar::updateVelocity(const float& value)
{
	for (PPhysWheel wheel : wheels_) {
        wheel->updateVelocity(value);
	}
}

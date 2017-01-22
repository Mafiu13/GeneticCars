#include "PhysCar.h"

PhysCar::PhysCar()
{
}

PhysCar::~PhysCar()
{
}


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

void PhysCar::setBodyShape(PPhysBodyShape b)
{
	bodyShape_ = b;
}

void PhysCar::setWheels(std::vector<PPhysWheel> v)
{
	wheels_ = v;
}

void PhysCar::setParts(std::vector<PPhysWheel> v, PPhysBodyShape b)
{
	wheels_ = v;
	bodyShape_ = b;
}

void PhysCar::createJoint(b2World & World, PPhysWheel wheel)
{
	b2RevoluteJointDef jointdef;

	jointdef.bodyA = bodyShape_->getBody();
	jointdef.bodyB = wheel->getBody();

	jointdef.localAnchorA.Set(wheel->getJointPoint().getX(), wheel->getJointPoint().getY()); // ustawiamy punkt zaczepu w pierwszym ciele. Jest on we wspó³rzêdnych LOKALNYCH cia³a
	jointdef.localAnchorB.Set(0, 0);  // i w drugim
	jointdef.collideConnected = false; // cia³a po³¹czone revolute jointem NIE MOG¥ ze sob¹ kolidowaæ
	jointdef.enableLimit = false; // musimy wlaczyc limit
	joints_.push_back((b2RevoluteJoint*)World.CreateJoint(&jointdef));
}

void PhysCar::createJoints(b2World& world)
{
	for (PPhysWheel wheel : wheels_) {
		createJoint(world, wheel);
	}
}

void PhysCar::updateVelocity()
{
	for (PPhysWheel wheel : wheels_) {
		wheel->updateVelocity();
	}
}

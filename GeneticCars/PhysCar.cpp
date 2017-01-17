#include "PhysCar.h"

PhysCar::PhysCar()
{
}

PhysCar::~PhysCar()
{
	b2World * world = bodyShape->getBody()->GetWorld();
	for (b2RevoluteJoint* joint : joints) {
		world->DestroyJoint(joint);
	}
	for (WheelSh wheel : wheels) {
		world->DestroyBody(wheel->getBody());
	}
	world->DestroyBody(bodyShape->getBody());
}


std::vector<WheelSh> PhysCar::getWheels()
{
	return wheels;
}

PhysBodyShape * PhysCar::getBodyShape()
{
	return bodyShape.get();
}

void PhysCar::setBodyShape(BodyShapeSh b)
{
	bodyShape = b;
}

void PhysCar::setWheels(std::vector<WheelSh> v)
{
	wheels = v;
}

void PhysCar::setParts(std::vector<WheelSh> v, BodyShapeSh b)
{
	wheels = v;
	bodyShape = b;
}

void PhysCar::createJoint(b2World & World, WheelSh wheel)
{
	b2RevoluteJointDef jointdef;

	jointdef.bodyA = bodyShape->getBody();
	jointdef.bodyB = wheel->getBody();

	jointdef.localAnchorA.Set(wheel->getJointPoint().getX(), wheel->getJointPoint().getY()); // ustawiamy punkt zaczepu w pierwszym ciele. Jest on we wspó³rzêdnych LOKALNYCH cia³a
	jointdef.localAnchorB.Set(0, 0);  // i w drugim
	jointdef.collideConnected = false; // cia³a po³¹czone revolute jointem NIE MOG¥ ze sob¹ kolidowaæ
	jointdef.enableLimit = false; // musimy wlaczyc limit
	joints.push_back((b2RevoluteJoint*)World.CreateJoint(&jointdef));
}

void PhysCar::createJoints(b2World& world)
{
	for (WheelSh wheel : wheels) {
		createJoint(world, wheel);
	}
}

void PhysCar::updateVelocity()
{
	for (WheelSh wheel : wheels) {
		wheel->updateVelocity();
	}
}

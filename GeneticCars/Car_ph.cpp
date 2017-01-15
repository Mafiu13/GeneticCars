#include "Car_ph.h"

Car_ph::Car_ph()
{
}

Car_ph::~Car_ph()
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


std::vector<WheelSh> Car_ph::getWheels()
{
	return wheels;
}

BodyShape_ph * Car_ph::getBodyShape()
{
	return bodyShape.get();
}

void Car_ph::setBodyShape(BodyShapeSh b)
{
	bodyShape = b;
}

void Car_ph::setWheels(std::vector<WheelSh> v)
{
	wheels = v;
}

void Car_ph::setParts(std::vector<WheelSh> v, BodyShapeSh b)
{
	wheels = v;
	bodyShape = b;
}

void Car_ph::createJoint(b2World & World, WheelSh wheel)
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

void Car_ph::createJoints(b2World& world)
{
	for (WheelSh wheel : wheels) {
		createJoint(world, wheel);
	}
}

void Car_ph::updateVelocity()
{
	for (WheelSh wheel : wheels) {
		wheel->updateVelocity();
	}
}

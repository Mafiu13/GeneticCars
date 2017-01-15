#include "Car_ph.h"

Car_ph::Car_ph()
{
}

Car_ph::~Car_ph()
{
	b2World * world = bodyShape->getBody()->GetWorld();
	world->DestroyJoint(joint1);
	world->DestroyJoint(joint2);
	world->DestroyBody(wheel_1->getBody());
	world->DestroyBody(wheel_2->getBody());
	world->DestroyBody(bodyShape->getBody());
}

Wheel_ph * Car_ph::getWheel_1()
{
	return wheel_1.get();
}

Wheel_ph * Car_ph::getWheel_2()
{
	return wheel_2.get();
}

BodyShape_ph * Car_ph::getBodyShape()
{
	return bodyShape.get();
}

void Car_ph::setBodyShape(boost::shared_ptr<BodyShape_ph> b)
{
	bodyShape = b;
}

void Car_ph::setWheel(boost::shared_ptr<Wheel_ph> wh, int which)
{
	if (which == 1) {
		wheel_1 = wh;
	}
	else if (which == 2) {
		wheel_2 = wh;
	}
}

void Car_ph::setParts(boost::shared_ptr<Wheel_ph> c1, boost::shared_ptr<Wheel_ph> c2, boost::shared_ptr<BodyShape_ph> b)
{
	wheel_1 = c1;
	wheel_2 = c2;
	bodyShape = b;
}

void Car_ph::createJoints(b2World & World)
{
	b2RevoluteJointDef jointdef1;
	b2RevoluteJointDef jointdef2;
	jointdef1.bodyA = bodyShape->getBody();
	jointdef1.bodyB = wheel_1->getBody();

	jointdef1.localAnchorA.Set(wheel_1->getJointPoint().getX(), wheel_1->getJointPoint().getY()); // ustawiamy punkt zaczepu w pierwszym ciele. Jest on we wspó³rzêdnych LOKALNYCH cia³a
	jointdef1.localAnchorB.Set(0, 0);  // i w drugim
	jointdef1.collideConnected = false; // cia³a po³¹czone revolute jointem NIE MOG¥ ze sob¹ kolidowaæ
	jointdef1.enableLimit = false; // musimy wlaczyc limit
	joint1 = (b2RevoluteJoint*)World.CreateJoint(&jointdef1);

	jointdef2.bodyA = bodyShape->getBody();
	jointdef2.bodyB = wheel_2->getBody();
	jointdef2.localAnchorA.Set(wheel_2->getJointPoint().getX(), wheel_2->getJointPoint().getY());
	jointdef2.localAnchorB.Set(0, 0); 
	jointdef2.collideConnected = false;
	jointdef2.enableLimit = false;
	joint2 = (b2RevoluteJoint*)World.CreateJoint(&jointdef2);
}

void Car_ph::updateVelocity()
{
	wheel_1->updateVelocity();
	wheel_2->updateVelocity();
}

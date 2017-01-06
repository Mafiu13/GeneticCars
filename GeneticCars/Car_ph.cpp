#include "Car_ph.h"

Car_ph::Car_ph()
{
	jointPoint_1 = std::make_unique<b2Vec2>();
	jointPoint_2 = std::make_unique<b2Vec2>();
}

Car_ph::~Car_ph()
{
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

void Car_ph::setJointPoints(float x1, float y1, float x2, float y2)
{
	jointPoint_1->x = x1;
	jointPoint_1->y = y1;
	jointPoint_2->x = x2;
	jointPoint_2->y = y2;
}

void Car_ph::setParts(boost::shared_ptr<Wheel_ph> c1, boost::shared_ptr<Wheel_ph> c2, boost::shared_ptr<BodyShape_ph> b)
{
	wheel_1 = c1;
	wheel_2 = c2;
	bodyShape = b;
}

void Car_ph::createJoints(b2World & World)
{
	b2RevoluteJointDef joint;
	joint.bodyA = bodyShape->getBody();
	joint.bodyB = wheel_1->getBody();

	joint.localAnchorA.Set(this->jointPoint_1->x, this->jointPoint_1->y); // ustawiamy punkt zaczepu w pierwszym ciele. Jest on we wspó³rzêdnych LOKALNYCH cia³a
	joint.localAnchorB.Set(0, 0);  // i w drugim
	joint.collideConnected = false; // cia³a po³¹czone revolute jointem NIE MOG¥ ze sob¹ kolidowaæ
	joint.enableLimit = false; // musimy wlaczyc limit
	World.CreateJoint(&joint);

	joint.bodyB = wheel_2->getBody();
	joint.localAnchorA.Set(this->jointPoint_2->x, this->jointPoint_2->y); // ustawiamy punkt zaczepu w pierwszym ciele. Jest on we wspó³rzêdnych LOKALNYCH cia³a
	World.CreateJoint(&joint);
}

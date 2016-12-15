#include "Car_ph.h"

Car_ph::Car_ph(b2Body *wheel1, b2Body *wheel2, b2Body *shapeBody)
{
	bodies[0] = wheel1;
	bodies[1] = wheel2;
	bodies[2] = shapeBody;
}

Car_ph::~Car_ph()
{
}

void Car_ph::createJoint(b2World & World, b2Body * a, b2Body * b, ShapePoint p1, ShapePoint p2)
{
	b2RevoluteJointDef joint;
	joint.bodyA = a;
	joint.bodyB = b;

	joint.localAnchorA.Set(p1.x / SCALE, p1.y / SCALE); // ustawiamy punkt zaczepu w pierwszym ciele. Jest on we wspó³rzêdnych LOKALNYCH cia³a
	joint.localAnchorB.Set(p2.x / SCALE, p2.y / SCALE);  // i w drugim
	joint.collideConnected = false; // cia³a po³¹czone revolute jointem NIE MOG¥ ze sob¹ kolidowaæ
	joint.enableLimit = false; // musimy wlaczyc limit
	World.CreateJoint(&joint);
}
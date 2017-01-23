#define BOOST_TEST_MODULE TestPhysWheel
#include <boost/test/unit_test.hpp>

#include "PhysWheel.h"

BOOST_AUTO_TEST_CASE(TestPhysWheel_Attributes)
{
	PPhysWheel wheel = boost::make_shared<PhysWheel>();
	ShapePoint point(1.0f, 2.0f);
	wheel->setJointPoint(point);
	wheel->setDensity(0.5f);
	wheel->setRadius(0.4f);
	BOOST_CHECK_EQUAL(wheel->getDensity(), 0.5f);
	BOOST_CHECK_EQUAL(wheel->getRadius(), 0.4f);
	BOOST_CHECK_EQUAL(wheel->getJointPoint(), point);
}

BOOST_AUTO_TEST_CASE(TestPhysWheel_CreateInWorld)
{
	b2World world(b2Vec2(0, 5));
	PPhysWheel wheel = boost::make_shared<PhysWheel>();
	ShapePoint point(1.0f, 2.0f);
	wheel->setJointPoint(point);
	wheel->setDensity(0.5f);
	wheel->setRadius(0.4f);
	wheel->createWheel(world);
	BOOST_CHECK(wheel->getBody() != NULL);
	BOOST_CHECK(wheel->getBody()->GetWorld() == &world);
	float velocity = 10.0f;
	wheel->updateVelocity(velocity);
	BOOST_CHECK_EQUAL(wheel->getBody()->GetAngularVelocity(), velocity);
}
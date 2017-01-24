#define BOOST_TEST_MODULE TestPhysTrack
#include <boost/test/unit_test.hpp>

#include "PhysTrack.h"
#include "CarConst.h"

BOOST_AUTO_TEST_CASE(TestPhysTrack_Attributes)
{
	int n = 10;
	PPhysTrack track = boost::make_shared<PhysTrack>(n);

	track->generateTrack(50, 300, 100);
	BOOST_CHECK_EQUAL(track->getN(), n);
	for (int i = 0; i < n; i++) 
	{
		BOOST_CHECK(track->getArr()[i].y < 351 / SCALE && track->getArr()[i].y > 299 / SCALE);
	}
}

BOOST_AUTO_TEST_CASE(TestPhysTrack_CreateInWorld)
{
	int n = 10;
	b2World world(b2Vec2(0, 5));
	PPhysTrack track = boost::make_shared<PhysTrack>(n);
	track->generateTrack(50, 300, 100);

	track->createTrack(&world, n);
	BOOST_CHECK(track->getBody() != NULL);
	BOOST_CHECK_EQUAL(world.GetBodyCount(), 1);
	BOOST_CHECK(track->getBody()->GetWorld() == &world);
}
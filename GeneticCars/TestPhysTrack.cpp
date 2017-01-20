#define BOOST_TEST_MODULE TestPhysTrack
#include <boost/test/unit_test.hpp>

#include "PhysTrack.h"
#include "CarConst.h"

BOOST_AUTO_TEST_CASE(TestPhysTrack_Attributes)
{
	PPhysTrack track = boost::make_shared<PhysTrack>(10);
	
	track->generateTrack(50, 300, 100);
	BOOST_CHECK_EQUAL(track->getN(), 10);
	BOOST_CHECK(track->getArr()[5].y < 351 / SCALE && track->getArr()[5].y > 299 / SCALE);

}

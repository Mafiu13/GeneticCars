#define BOOST_TEST_MODULE TestPhysWheel
#include <boost/test/unit_test.hpp>

#include "PhysWheel.h"

BOOST_AUTO_TEST_CASE(TestPhysWheel_Attributes)
{
	PPhysWheel wheel = boost::make_shared<PhysWheel>();
	wheel->setDensity(0.5);
	wheel->setRadius(0.4);
	BOOST_CHECK_EQUAL(wheel->getDensity(), 0.5);
	BOOST_CHECK_EQUAL(wheel->getRadius(), 0.4);

}

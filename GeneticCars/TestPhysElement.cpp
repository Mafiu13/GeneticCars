#define BOOST_TEST_MODULE TestPhysElement
#include <boost/test/unit_test.hpp>

#include "PhysElement.h"
#include "CarConst.h"

BOOST_AUTO_TEST_CASE(TestPhysElement_Attributes)
{
	PPhysElement elem = boost::make_shared<PhysElement>();
	elem->setDensity(0.4f);

	BOOST_CHECK_EQUAL(elem->getDensity(), 0.4f);

}
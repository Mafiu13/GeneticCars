#define BOOST_TEST_MODULE Test_Wheel
#include <boost/test/unit_test.hpp>
#include <boost/make_shared.hpp>

#include "Wheel.h"

BOOST_AUTO_TEST_CASE(TestWheel_Attributes)
{
	ShapePoint sp = ShapePoint(1.0, 1.0);
	Wheel wheel = Wheel(1.0, 1.0, 1, sp);

	BOOST_CHECK_EQUAL(wheel.getRadius(), 1.0);
	BOOST_CHECK_EQUAL(wheel.getDensity(), 1.0);
	BOOST_CHECK_EQUAL(wheel.getShapePointsIndex(), 1);
	BOOST_CHECK_EQUAL(wheel.getShapePoint().getX(), 1.0);
	BOOST_CHECK_EQUAL(wheel.getShapePoint().getY(), 1.0);
}

#define BOOST_TEST_MODULE TestShapePoint
#include <boost/test/unit_test.hpp>
#include <boost/make_shared.hpp>

#include "ShapePoint.h"

BOOST_AUTO_TEST_CASE(TestShapePoint_Attributes)
{
	ShapePoint shapePoint = ShapePoint(1.0, 1.0);

	BOOST_CHECK_EQUAL(shapePoint.getX(), 1.0);
	BOOST_CHECK_EQUAL(shapePoint.getY(), 1.0);

	shapePoint.setX(2.0);
	shapePoint.setY(2.0);

	BOOST_CHECK_EQUAL(shapePoint.getX(), 2.0);
	BOOST_CHECK_EQUAL(shapePoint.getY(), 2.0);
}
#define BOOST_TEST_MODULE TestBodyShape
#include <boost/test/unit_test.hpp>
#include <boost/make_shared.hpp>

#include "BodyShape.h"
#include "CarConst.h"

BOOST_AUTO_TEST_CASE(TestBodyShape_Attributes)
{
	std::vector<ShapePoint> sps;
	for (int i = 0; i < NR_OF_POINTS_IN_BODYSHAPE; ++i)
	{
		ShapePoint sp = ShapePoint(1.0, 1.0);
		sps.push_back(sp);
	}
	BodyShape bs = BodyShape(sps, 1.0);

	BOOST_CHECK_EQUAL(bs.getDensity(), 1.0);
	BOOST_CHECK_EQUAL(bs.getShapePoints().size, NR_OF_POINTS_IN_BODYSHAPE);
}
#define BOOST_TEST_MODULE Test_Chromosome
#include <boost/test/unit_test.hpp>
#include <boost/make_shared.hpp>

#include "Chromosome.h"
#include "CarConst.h"

BOOST_AUTO_TEST_CASE(TestChromosome_Attributes)
{
	std::vector<ShapePoint> sps;
	for (int i = 0; i < NR_OF_POINTS_IN_BODYSHAPE; ++i)
	{
		ShapePoint sp = ShapePoint(1.0, 1.0);
		sps.push_back(sp);
	}
	BodyShape bs = BodyShape(sps, 1.0);

	std::vector<Wheel> whs;
	for (int i = 0; i < NR_OF_WHEELS; ++i)
	{
		ShapePoint sp = ShapePoint(1.0, 1.0);
		Wheel wheel = Wheel(1.0, 1.0, 1, sp);
		whs.push_back(wheel);
	}

	Chromosome ch = Chromosome(bs, whs);

    BOOST_CHECK_EQUAL(ch.getBodyShape().getShapePoints().size(), NR_OF_POINTS_IN_BODYSHAPE);
    BOOST_CHECK_EQUAL(ch.getWheels().size(), NR_OF_WHEELS);
}

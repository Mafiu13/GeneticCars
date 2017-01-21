#define BOOST_TEST_MODULE Test_PhysSimulation
#include <boost/test/unit_test.hpp>

#include "PhysSimulation.h"
#include "CarConst.h"

BOOST_AUTO_TEST_CASE(TestPhysSimulation_Attributes)
{
	PPhysSimulation sim = boost::make_shared<PhysSimulation>();
	BOOST_CHECK(sim->getPopulation() != NULL);
	BOOST_CHECK(sim->getDrawing() != NULL);
}

#define BOOST_TEST_MODULE TestPhysPopulation
#include <boost/test/unit_test.hpp>

#include "PhysPopulation.h"
#include "CarConst.h"

BOOST_AUTO_TEST_CASE(TestPhysPopulation_Attributes)
{
	PPhysPopulation pop = boost::make_shared<PhysPopulation>();
	std::vector<PPhysCar> cars;
	cars.push_back(boost::make_shared<PhysCar>());
	cars.push_back(boost::make_shared<PhysCar>());
	pop->setCars(cars);

	BOOST_CHECK_EQUAL(pop->getCars().size(), 2);

}
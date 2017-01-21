#define BOOST_TEST_MODULE Test_PhysCar
#include <boost/test/unit_test.hpp>

#include "PhysCar.h"
#include "CarConst.h"

BOOST_AUTO_TEST_CASE(TestPhysCar_Attributes)
{
	PPhysCar car = boost::make_shared<PhysCar>();
	std::vector<PPhysWheel> wheels;
	PPhysWheel wheel = boost::make_shared<PhysWheel>();
	wheels.push_back(wheel);
	car->setWheels(wheels);
	BOOST_CHECK(car->getWheels()[0] == wheel);

	wheels.push_back(boost::make_shared<PhysWheel>());
	BOOST_CHECK_EQUAL(car->getWheels().size(), 2);

	PPhysBodyShape body = boost::make_shared<PhysBodyShape>();
	car->setBodyShape(body);
	BOOST_CHECK(car->getBodyShape() == body.get());
}

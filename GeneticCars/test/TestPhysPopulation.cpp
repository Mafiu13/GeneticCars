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

	float vel = 20.f;
	pop->setVelocity(vel);

}

BOOST_AUTO_TEST_CASE(TestPhysPopulation_CreateInWorld)
{
	b2World world(b2Vec2(0, 5));

	PPhysCar car(boost::make_shared<PhysCar>());
	std::vector<PPhysWheel> wheels;
	PPhysWheel wheel1(boost::make_shared<PhysWheel>());
	wheel1->setDensity(1.0f);
	wheel1->setRadius(0.5f);
	wheel1->setJointPoint(ShapePoint(1.0f, 1.0f));
	wheel1->createWheel(&world);
	wheels.push_back(wheel1);

	PPhysWheel wheel2(boost::make_shared<PhysWheel>());
	wheel2->setDensity(1.0f);
	wheel2->setRadius(0.5f);
	wheel2->setJointPoint(ShapePoint(0.0f, 0.0f));
	wheel2->createWheel(&world);
	wheels.push_back(wheel2);
	car->setWheels(wheels);

	PPhysBodyShape bodyShape(boost::make_shared<PhysBodyShape>());
	bodyShape->setDensity(0.5f);
	std::vector<ShapePoint> vec;
	vec.push_back(ShapePoint(0, 0));
	vec.push_back(ShapePoint(1, 1));
	vec.push_back(ShapePoint(2, 1));
	vec.push_back(ShapePoint(4, -1));
	vec.push_back(ShapePoint(0, -2));
	vec.push_back(ShapePoint(-1, -1));
	vec.push_back(ShapePoint(-2, 0));
	vec.push_back(ShapePoint(-1, 1));
	bodyShape->setVerticesFromShapePoints(vec);
	bodyShape->createBodyShape(&world);
	car->setBodyShape(bodyShape);
	car->createJoints(&world);

	PPhysPopulation pop = boost::make_shared<PhysPopulation>();
	std::vector<PPhysCar> cars;
	cars.push_back(car);
	pop->setCars(cars);
	BOOST_CHECK_EQUAL(pop->getCars().size(), 1);
	BOOST_CHECK(pop->getCars().front() == car);

	float vel = 20.f;
	pop->setVelocity(vel);

	BOOST_CHECK_EQUAL(pop->getFollowX(), pop->getTheFastestX());

	BOOST_CHECK_EQUAL(world.GetBodyCount(), 3);
	pop->destroyCars(&world);
	BOOST_CHECK_EQUAL(world.GetBodyCount(), 0);

}

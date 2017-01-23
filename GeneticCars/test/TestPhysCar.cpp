#define BOOST_TEST_MODULE TestPhysCar
#include <boost/test/unit_test.hpp>

#include "PhysCar.h"
#include "CarConst.h"

BOOST_AUTO_TEST_CASE(TestPhysCar_Attributes)
{
	PPhysCar car(boost::make_shared<PhysCar>());
	std::vector<PPhysWheel> wheels;
	PPhysWheel wheel(boost::make_shared<PhysWheel>());
	wheels.push_back(wheel);
	wheels.push_back(boost::make_shared<PhysWheel>());
	car->setWheels(wheels);

	BOOST_CHECK(car->getWheels()[0] == wheel);
	BOOST_CHECK_EQUAL(car->getWheels().size(), 2);

	PPhysBodyShape body = boost::make_shared<PhysBodyShape>();
	car->setBodyShape(body);
	BOOST_CHECK(car->getBodyShape() == body.get());

}

BOOST_AUTO_TEST_CASE(TestPhysCar_CreateInWorld)
{
	b2World world(b2Vec2(0, 5));

	PPhysCar car(boost::make_shared<PhysCar>());
	std::vector<PPhysWheel> wheels;
	PPhysWheel wheel1(boost::make_shared<PhysWheel>());
	wheel1->setDensity(1.0f);
	wheel1->setRadius(0.5f);
	wheel1->setJointPoint(ShapePoint(1.0f, 1.0f));
	wheel1->createWheel(world);
	wheels.push_back(wheel1);

	PPhysWheel wheel2(boost::make_shared<PhysWheel>());
	wheel2->setDensity(1.0f);
	wheel2->setRadius(0.5f);
	wheel2->setJointPoint(ShapePoint(0.0f, 0.0f));
	wheel2->createWheel(world);
	wheels.push_back(wheel2);
	car->setWheels(wheels);

	PPhysBodyShape bodyShape(boost::make_shared<PhysBodyShape>());
	bodyShape->setDensity(0.5f);
	std::vector<ShapePoint> vec;
	vec.push_back(ShapePoint(0.0f, 0.0f));
	vec.push_back(ShapePoint(1.0f, 1.0f));
	vec.push_back(ShapePoint(-1.0f, 1.0f));
	bodyShape->setVerticesFromShapePoints(vec);
	bodyShape->createBodyShape(world);
	car->setBodyShape(bodyShape);
	car->createJoints(world);
	
	BOOST_CHECK_EQUAL(car->getJoints().size(), 2);
	BOOST_CHECK_EQUAL(car->getJoints().front->GetBodyA, bodyShape->getBody());

	float vel = 20.0f;
	car->updateVelocity(vel);
}
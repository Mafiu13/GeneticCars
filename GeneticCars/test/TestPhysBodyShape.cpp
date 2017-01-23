#define BOOST_TEST_MODULE TestPhysBodyShape
#include <boost/test/unit_test.hpp>
#include <boost/make_shared.hpp>

#include "PhysBodyShape.h"
#include "CarConst.h"

BOOST_AUTO_TEST_CASE(TestPhysWheel_Attributes)
{
	PPhysBodyShape bodyShape = boost::make_shared<PhysBodyShape>();
	bodyShape->setDensity(0.5);
	BOOST_CHECK_EQUAL(bodyShape->getDensity(), 0.5);
	std::vector<ShapePoint> vec;
	vec.push_back(ShapePoint(0, 0));
	vec.push_back(ShapePoint(1, 1));
	vec.push_back(ShapePoint(-1, 1));
	bodyShape->setVerticesFromShapePoints(vec);

	BOOST_CHECK_EQUAL(bodyShape->getVertices()[0].x, 0);
	BOOST_CHECK_EQUAL(bodyShape->getVertices()[0].y, 0);
	BOOST_CHECK_EQUAL(bodyShape->getVertices()[1].x, 1);
	BOOST_CHECK_EQUAL(bodyShape->getVertices()[1].y, 1);
	BOOST_CHECK_EQUAL(bodyShape->getVertices()[2].x, -1);
	BOOST_CHECK_EQUAL(bodyShape->getVertices()[2].y, 1);
}

BOOST_AUTO_TEST_CASE(TestPhysBodyShape_CreateInWorld)
{
	PPhysBodyShape bodyShape = boost::make_shared<PhysBodyShape>();
	bodyShape->setDensity(0.5);

	std::vector<ShapePoint> vec;
	vec.push_back(ShapePoint(0, 0));
	vec.push_back(ShapePoint(1, 1));
	vec.push_back(ShapePoint(-1, 1));
	bodyShape->setVerticesFromShapePoints(vec);

	b2World world(b2Vec2(0, 5));
	bodyShape->createBodyShape(world);
	BOOST_CHECK(bodyShape->getBody() != NULL);
	BOOST_CHECK(bodyShape->getBody()->GetWorld() == &world);
}
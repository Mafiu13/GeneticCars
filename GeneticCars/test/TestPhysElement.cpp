#define BOOST_TEST_MODULE TestPhysElement
#include <boost/test/unit_test.hpp>

#include "PhysElement.h"
#include "CarConst.h"

BOOST_AUTO_TEST_CASE(TestPhysElement_Attributes)
{
	PPhysElement elem = boost::make_shared<PhysElement>();
	elem->setDensity(0.4f);
	BOOST_CHECK_EQUAL(elem->getDensity(), 0.4f);

	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.position.Set(0, 0);

	b2World world(b2Vec2(0, 5));
	b2Body* body = world.CreateBody(&def);
	elem->setBody(body);
	BOOST_CHECK(elem->getBody() == body);
	BOOST_CHECK(elem->getBody()->GetWorld() == &world);
	BOOST_CHECK_EQUAL(world.GetBodyCount(), 1);
}
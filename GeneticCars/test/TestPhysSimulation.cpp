#define BOOST_TEST_MODULE TestPhysSimulation
#include <boost/test/unit_test.hpp>

#include "PhysSimulation.h"
#include "CarConst.h"

BOOST_AUTO_TEST_CASE(TestPhysSimulation_Creating)
{
	PPhysSimulation sim(boost::make_shared<PhysSimulation>());
	BOOST_CHECK(sim->getPopulation() != NULL);
	BOOST_CHECK(sim->getDrawing() != NULL);

	PPhysPopulation pop(boost::make_shared<PhysPopulation>());

	BOOST_CHECK(sim->getPopulation(), pop);

	sim->setWorldParams(10.0f, 1.0f, 100, 4, 5);

	BOOST_CHECK_EQUAL(sim->getSimSteps(), 100);

	sim->setTrackParams(50, 300, 100, 20);

	sim->createSimulation();
	BOOST_CHECK(sim->getWorld() != NULL);
	BOOST_CHECK(sim->getTrack() != NULL);
	BOOST_CHECK_EQUAL(sim->getTrack()->getN(), 20);
	BOOST_CHECK(sim->getTrack()->getBody() != NULL);

	b2World* w = sim->getWorld();
	BOOST_CHECK_EQUAL(w->GetGravity().y, 10.0f);
	BOOST_CHECK_EQUAL(w->GetBodyCount(), 1);

	sim->destroyTrack();
	BOOST_CHECK_EQUAL(w->GetBodyCount(), 0);
}


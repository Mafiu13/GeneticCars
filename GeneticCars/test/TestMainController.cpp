#define BOOST_TEST_MODULE TestMainController
#include <boost/test/unit_test.hpp>
#include <boost/make_shared.hpp>

#include "MainController.h"

BOOST_AUTO_TEST_CASE(TestMainControllerAttributes)
{
	PMainController controller(boost::make_shared<MainController>());

	PPopulationManager pm(boost::make_shared<PopulationManager>(10, 0.1f));
	controller->setPopulationManager(pm);
	BOOST_CHECK(controller->getPopulationManager() == pm);
	controller->setSize(20);
	BOOST_CHECK_EQUAL(controller->getSize(), 20);
	controller->setRate(0.1f);
	BOOST_CHECK_EQUAL(controller->getRate(), 0.1f);
	controller->setMaxGen(30);
	BOOST_CHECK_EQUAL(controller->getMaxGen(), 30);
	controller->setSize(20);
	BOOST_CHECK_EQUAL(controller->getSize(), 20);
	controller->setRate(0.5f);
	BOOST_CHECK_EQUAL(controller->getRate(), 0.5f);
	controller.reset();
}

#define BOOST_TEST_MODULE TestMainController
#include <boost/test/unit_test.hpp>
#include <boost/make_shared.hpp>

#include "MainController.h"

BOOST_AUTO_TEST_CASE(TestPhysWheel_Attributes)
{
	PMainController controller(boost::make_shared<MainController>());

	PPhysSimulation sim(boost::make_shared<PhysSimulation>());
	controller->setSimulation(sim);
	BOOST_CHECK(controller->getSimualation(), sim);

	PPopulationManager pm(boost::make_shared<PopulationManager>());
	controller->setPopulationManager(pm);
	BOOST_CHECK(controller->getPopulationManager(), pm);

	PAppWindow window(boost::make_shared<AppWindow>(controller, 300, 600, 32, "test"));
	controller->setWindow(window);
	BOOST_CHECK(controller->getWindow(), window);

	controller->setMaxGen(30);
	BOOST_CHECK_EQUAL(controller->getMaxGen(), 30);
	controller->setSize(20);
	BOOST_CHECK_EQUAL(controller->getSize(), 20);
	controller->setRate(0.5f);
	BOOST_CHECK_EQUAL(controller->getRate(), 0.5f);
	
}

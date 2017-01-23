#define BOOST_TEST_MODULE TestAppWindow
#include <boost/test/unit_test.hpp>

#include "AppWindow.h"

BOOST_AUTO_TEST_CASE(TestAppWindow_Attributes)
{
	PMainController controller(boost::make_shared<MainController>());

	PAppWindow window(boost::make_shared<AppWindow>(controller, 300, 600, 32, "test"));

	BOOST_CHECK_EQUAL(window->getWindow().getSize().x, 300);
	BOOST_CHECK_EQUAL(window->getWindow().getSize().y, 600);
}
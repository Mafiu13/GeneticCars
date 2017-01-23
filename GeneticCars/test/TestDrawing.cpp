#define BOOST_TEST_MODULE TestDrawing
#include <boost/test/unit_test.hpp>

#include "Drawing.h"

BOOST_AUTO_TEST_CASE(TestDrawing_Attributes)
{
	PDrawing drawing(boost::make_shared<Drawing>());

	PPhysCar car(boost::make_shared<PhysCar>());
	std::vector<PPhysWheel> wheels;
	PPhysWheel wheel(boost::make_shared<PhysWheel>());
	wheel->setDensity(1.0f);
	wheel->setRadius(0.5f);
	wheel->setJointPoint(ShapePoint(1.0f, 1.0f));
	wheels.push_back(wheel);

	PPhysWheel wheel2(boost::make_shared<PhysWheel>());
	wheel2->setDensity(1.0f);
	wheel2->setRadius(0.5f);
	wheel2->setJointPoint(ShapePoint(0.0f, 0.0f));
	wheels.push_back(wheel2);
	car->setWheels(wheels);

	PPhysBodyShape bodyShape(boost::make_shared<PhysBodyShape>());
	bodyShape->setDensity(0.5f);
	std::vector<ShapePoint> vec;
	vec.push_back(ShapePoint(0.0f, 0.0f));
	vec.push_back(ShapePoint(1.0f, 1.0f));
	vec.push_back(ShapePoint(-1.0f, 1.0f));
	bodyShape->setVerticesFromShapePoints(vec);
	car->setBodyShape(bodyShape);

	std::vector<PPhysCar> cars;
	cars.push_back(car);

	drawing->drawCars(cars);
	
	BOOST_CHECK(drawing->getCircle().front != NULL);
	BOOST_CHECK(drawing->getPolygons().front != NULL);

	int n = 10;
	PPhysTrack track = boost::make_shared<PhysTrack>(n);
	track->generateTrack(50, 300, 100);

	drawing->drawTrack(track.get());
	BOOST_CHECK_EQUAL(drawing->getLine().getVertexCount(), 2*n);


}

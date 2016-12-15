#pragma once
#include <Box2D\Box2D.h>
#include <SFML/Graphics.hpp>
#include "Wheel_ph.h"
#include "Track_ph.h"
#include "BodyShape_ph.h"
#include "ShapePoint.h"
#include "Car_ph.h"
#include "Drawing.h"


class Simulation
{
public:
	Simulation();
	~Simulation();
	void createSimulation();
};


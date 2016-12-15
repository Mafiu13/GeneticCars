#pragma once
#include <Box2D\Box2D.h>
#include <ctime>
#include <random>
#include "const.h"

class Track_ph
{
	b2Body * body;
	b2Vec2 v[N];

public:
	Track_ph();
	~Track_ph();
	b2Body * getBody();
	b2Vec2 * getTab();
	void createTrack(b2World &world);
	void generateTrack(int h1, int h2, int d);
};

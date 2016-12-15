#include "Track_ph.h"
#include "const.h"

Track_ph::Track_ph()
{
}


Track_ph::~Track_ph()
{
}

b2Body * Track_ph::getBody()
{
	return body;
}

b2Vec2 * Track_ph::getTab()
{
	return v;
}

void Track_ph::createTrack(b2World & world)
{
	b2BodyDef chainDefinition;
	chainDefinition.type = b2_staticBody;
	b2Body* chain = world.CreateBody(&chainDefinition);
	b2ChainShape chainShape; // stanowi krawedz, lancuch odcinkow, nie ma grubosci ani masy

	chainShape.CreateChain(this->v, N);

	b2FixtureDef chainFixture;
	chainFixture.shape = &chainShape;
	chain->CreateFixture(&chainFixture);

	this->body = chain;
}

void Track_ph::generateTrack(int h1, int h2, int d)
{
	int b1 = 0;
	int b2 = d;
	int l1 = 0;
	int l2 = 0;
	int temp = 0;

	srand(time(NULL));
	for (int i = 0; i < N; ++i) {
		l1 = (std::rand() % h1) + h2;
		do
		{
			l2 = (std::rand() % b2) + b1;
		} while (l2 <= temp);

		temp = l2;
		b1 += d;
		b2 += d;
		this->v[i].y = l1 / SCALE;
		this->v[i].x = l2 / SCALE;
	}
}

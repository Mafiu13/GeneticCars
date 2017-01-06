#include "Track_ph.h"
#include "const.h"


Track_ph::Track_ph()
{
	arr = std::make_unique<b2Vec2[]>(N);
}


Track_ph::~Track_ph()
{
}

b2Vec2 * Track_ph::getArr()
{
	return arr.get();
}



void Track_ph::createTrack(b2World & world)
{
	b2BodyDef chainDefinition;
	chainDefinition.type = b2_staticBody;
	b2Body * chain = (world.CreateBody(&chainDefinition));
	b2ChainShape chainShape; // stanowi krawedz, lancuch odcinkow, nie ma grubosci ani masy
	
	chainShape.CreateChain(arr.get(), N);

	b2FixtureDef chainFixture;
	chainFixture.shape = &chainShape;
	chainFixture.filter.categoryBits = 0x0001;
	chainFixture.filter.maskBits = 0x0002;

	chain->CreateFixture(&chainFixture);

	this->setBody(chain);
}

//h1 - przedzial wysokosci, h0 - wysokosc poczatkowa, d - dlugosc odcinka
void Track_ph::generateTrack(int delta_h, int h0, int d)
{
	int b1 = 0; //losowanie wspolrzednej x, wartosc poczatkowa
	int b2 = d; //losowanie wspolrzednej x, wartosc koncowa
	int l1 = 0; //kolejna wspolrzedna x
	int l2 = 0; //kolejna wspolrzedna y
	int temp = 0;

	srand(time(NULL));
	for (int i = 0; i < N; ++i) {
		l1 = (std::rand() % delta_h) + h0;
		do
		{
			l2 = (std::rand() % b2) + b1;
		} while (l2 <= temp);

		temp = l2;
		b1 += d;
		b2 += d;
		arr[i] = b2Vec2(l2 / SCALE, l1 / SCALE);
	}
}

#include "PhysTrack.h"
#include "const.h"


PhysTrack::PhysTrack(int n)
{
	arr_ = std::make_unique<b2Vec2[]>(n);
	n_ = n;
}


PhysTrack::~PhysTrack()
{
}

b2Vec2 * PhysTrack::getArr() const
{
	return arr_.get();
}

int PhysTrack::getN() const
{
	return n_;
}

void PhysTrack::createTrack(b2World & world, int n)
{
	b2BodyDef chainDefinition;
	chainDefinition.type = b2_staticBody;
	b2Body * chain = (world.CreateBody(&chainDefinition));
	b2ChainShape chainShape; // stanowi krawedz, lancuch odcinkow, nie ma grubosci ani masy
	
	chainShape.CreateChain(arr_.get(), n);

	b2FixtureDef chainFixture;
	chainFixture.shape = &chainShape;
	chainFixture.filter.categoryBits = 0x0001;
	chainFixture.filter.maskBits = 0x0002;

	chain->CreateFixture(&chainFixture);

	this->setBody(chain);
}

//h1 - przedzial wysokosci, h0 - wysokosc poczatkowa, d - dlugosc odcinka
void PhysTrack::generateTrack(int delta_h, int h0, int d)
{
	int b1 = 0; //losowanie wspolrzednej x, wartosc poczatkowa
	int b2 = d; //losowanie wspolrzednej x, wartosc koncowa
	int l1 = 0; //kolejna wspolrzedna x
	int l2 = 0; //kolejna wspolrzedna y
	int temp = 0;

	srand(time(NULL));
	for (int i = 0; i < n_; ++i) 
	{
		l1 = (std::rand() % delta_h) + h0;
		do
		{
			l2 = (std::rand() % b2) + b1;
		} while (l2 <= temp);

		temp = l2;
		b1 += d;
		b2 += d;
		arr_[i] = b2Vec2(l2 / SCALE, l1 / SCALE);
	}
	for (int i = 0; i < n_ * 0.1; ++i) {
		arr_[i].y = h0 / SCALE;
	}
	arr_[0].x = -5 * d / SCALE;
}

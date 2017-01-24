#include "PhysTrack.h"


PhysTrack::PhysTrack(const int& n)
{
	arr_ = std::make_unique<b2Vec2[]>(n);
	n_ = n;
}

PhysTrack::~PhysTrack()
{
}

// ------------------metody [get]---------------
b2Vec2 * PhysTrack::getArr() const
{
    return arr_.get();
}

int PhysTrack::getN() const
{
	return n_;
}

void PhysTrack::createTrack(b2World* world, int n)
{
	b2BodyDef chainDefinition;
	chainDefinition.type = b2_staticBody;
	b2Body* chain = world->CreateBody(&chainDefinition);
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
	float b1 = 0; //losowanie wspolrzednej x, wartosc poczatkowa
	int b2 = d; //losowanie wspolrzednej x, wartosc koncowa
	float l1 = 0; //kolejna wspolrzedna x
	float l2 = 0; //kolejna wspolrzedna y
	float temp = 0;
	float dh = (float)delta_h;

	srand(time(NULL));
	for (int i = 0; i < n_; ++i)
	{
		// losowanie wspolrzednej y wierzcholka
		l1 = (float)(std::rand() % delta_h) + h0;
		do
		{
			//losowanie wspolrzednej x wierzcholka
			l2 = (float)(std::rand() % b2) + b1;
		} while (l2 <= temp + 0.2 * d);

		temp = l2;
		b1 += d;
		b2 += d;
		arr_[i] = b2Vec2(l2 / SCALE, l1 / SCALE);
		
		// zwiekszanie stromosci wrac z uplywem trasy
		if (i > n_ * 0.9f) {
			delta_h = (int)(dh * 1.9f);
		} else if (i > n_ * 0.8f && i < n_ * 0.9f) {
			delta_h = (int)(dh * 1.8f);
		} else if (i > n_ * 0.7 && i < n_ * 0.8f){
			delta_h = (int)(dh * 1.7f);
		} else if (i > n_ * 0.6 && i < n_ * 0.7f){
			delta_h = (int)(dh * 1.6f);
		} else if (i > n_ * 0.5 && i < n_ * 0.6f){
			delta_h = (int)(dh * 1.5f);
		} else if (i > n_ * 0.4 && i < n_ * 0.5f){
			delta_h = (int)(dh * 1.4f);
		} else if (i > n_ * 0.3 && i < n_ * 0.4f){
			delta_h = (int)(dh * 1.3f);
		} else if (i > n_ * 0.2 && i < n_ * 0.3f){
			delta_h = (int)(dh * 1.2f);
		} else if (i > n_ * 0.1 && i < n_ * 0.2f){
			delta_h = (int)(dh * 1.1f);
		} else {
			delta_h = (int)dh;
		}
	}
    for (int i = 0; i < 10; ++i) {
		arr_[i].y = h0 / SCALE;
	}
	arr_[0].x = -5 * d / SCALE;
}

#include "RandomService.h"



RandomService::RandomService()
	:randomEngine(randomDevice())
{
}


RandomService::~RandomService()
{
}

int RandomService::getRandomInt(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	double randomInt = dist(randomEngine);
	return randomInt;
}

double RandomService::getRandomDouble(double min, double max)
{
	uniform_real_distribution<float> dist(min, max);
	double randomDouble = dist(randomEngine);
	return randomDouble;
}

float RandomService::getRandomFloat(float min, float max)
{
	uniform_real_distribution<float> dist(min, max);
	float randomFloat = dist(randomEngine);
	return randomFloat;
}
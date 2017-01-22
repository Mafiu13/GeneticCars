#include "RandomService.h"



RandomService::RandomService()
	:randomEngine_(randomDevice_())
{
}


RandomService::~RandomService()
{
}

int RandomService::getRandomInt(const int& min, const int& max)
{
	uniform_int_distribution<int> dist(min, max);
	int randomInt = dist(randomEngine_);
	return randomInt;
}

double RandomService::getRandomDouble(const double& min, const double& max)
{
	uniform_real_distribution<double> dist(min, max);
	double randomDouble = dist(randomEngine_);
	return randomDouble;
}

float RandomService::getRandomFloat(const float& min, const float& max)
{
	uniform_real_distribution<float> dist(min, max);
	float randomFloat = dist(randomEngine_);
	return randomFloat;
}
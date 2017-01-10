#pragma once
#include <random>

using namespace std;

class RandomService
{
public:
	RandomService();
	~RandomService();

	int getRandomInt(int min, int max);
	double getRandomDouble(double min, double max);
	float getRandomFloat(float min, float max);

private:
	random_device randomDevice;
	mt19937 randomEngine;
};
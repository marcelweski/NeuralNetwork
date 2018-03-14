#include "Tools.hpp"

static bool init_rand = true;
double random(double min, double max)
{
	if (init_rand)
	{
		srand((unsigned int)time(NULL));
		init_rand = false;
	}

	return min + ((max - min) * ((double)rand() / RAND_MAX));
}
double random(double max)
{
	return random(0, max);
}

double map(double x, double in_min, double in_max, double out_min, double out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

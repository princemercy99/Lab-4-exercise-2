#include "Sinusoid.h"
#include <cmath>

float Sinusoid::evaluate(float x) const
{
	return amplitude_*sin(frequency_ * x + phase_);
}
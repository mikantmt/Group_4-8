#include <stdlib.h>
#include "Random.h"

float Random::ScopingRand(float min, float max) {
	float rand;

	rand = GetRand(max);

	if (rand <= min) {
		return ScopingRand(min, max);
	}
	else
		return rand;
}

float Random::OutRand(float min, float max, float out_min, float out_max) {
	float rand;

	rand = ScopingRand(min, max);

	if (rand > out_min && rand < out_max) {
		return OutRand(min, max, out_min, out_max);
	}
	else
		return rand;

}
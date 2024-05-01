#ifndef  NOISE_H
#define NOISE_H

#include <iostream>
#include "../Math.h"
#include "random"

namespace Noise {

	std::vector<std::vector<float>> generateNoise();		

	int getSeed();

}


#endif // ! NOISE_H

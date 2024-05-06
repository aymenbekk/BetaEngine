#include "Noise.h"
#include "../../third_party/fastNoise/FastNoiseLite.h"


std::vector<std::vector<float>> Noise::generateNoise() {

	FastNoiseLite noise;
	noise.SetFractalOctaves(5);
	noise.SetFractalLacunarity(1.75);
	noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
	noise.SetFractalType(FastNoiseLite::FractalType_FBm);
	noise.SetSeed(Noise::getSeed());

	std::vector<std::vector<float>> noiseData;
	std::vector<float> row;
	for (int y = 0; y < 16; y++) {

		for (int x = 0; x < 16; x++) {

			
			row.push_back(noise.GetNoise((float)x, (float)y));
			//noiseData[x][y] = noise.GetNoise((float)x, (float)y);

		}
		noiseData.push_back(row);
		row.clear();
	}

	return noiseData;
}


int Noise::getSeed() {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, 10000);

	return distr(gen);
}


//Random.cpp
#include "common/Random.h"

Random::Random() {}
Random::~Random() {}


void Random::StartUp(){
	std::srand(std::time(nullptr));

	boolDistribution.resize(10);
	intDistribution.resize(10);
	floatDistribution.resize(10);

	for(size_t i = 0, iLen = 10; i < iLen; i++){
		boolDistribution[i] = false;
		intDistribution[i] = 0;
		floatDistribution[i] = 0.0f;
	}
}

void Random::ShutDown(){}

B8 Random::GetBool(){
	return std::rand() % 2;
}

I32 Random::GetInt(I32 start, I32 end){
	ASSERT(start < end);
	I32 range = end - start;
	I32 randomVar = std::rand() / ((RAND_MAX + 1u) / range);
	return randomVar + start;
}

F32 Random::GetFloat(F32 start, F32 end){
	ASSERT(start < end);
	I32 range = end - start;
	F32 randomVar = (std::rand() / (float)RAND_MAX) * range;
	return randomVar + start;
}


I32 Random::GetIntNormalDistributed(I32 start, I32 end){
	ASSERT(start < end);
	I32 range = end - start;
	I32 randomVar = 0;

	for(size_t i = 0, iLen = 20; i < iLen; i++){
		randomVar = std::rand() / ((RAND_MAX + 1u) / range) + start;
		
		// Compare number to rules
		// 1. not the same number as n_0
		if(randomVar = intDistribution[0]) continue;

		// 2. not the same number as n_1
		if(randomVar = intDistribution[1]) continue;
		
		// 3. inc/dec sequences of 4 numbers
		if(randomVar > intDistribution[0]){
			if(intDistribution[0] > intDistribution[1]){
				if(intDistribution[1] > intDistribution[2]){
					if(intDistribution[2] > intDistribution[3]){
						continue;
					}
				}
			}
		} else if(randomVar < intDistribution[0]){
			if(intDistribution[0] < intDistribution[1]){
				if(intDistribution[1] < intDistribution[2]){
					if(intDistribution[2] < intDistribution[3]){
						continue;
					}
				}
			}
		}

		// 4. n numbers above/beneath average/median
		I32 median = start + range / 2;
		const size_t medianCheck = 4;
		for(size_t i = 0, iLen = medianCheck - 1; i < iLen; i++){
				
		}

		// 5. repeating pairs of numbers
		// 6. max of n same numbers in the last 10 numbers
		
		break;
	}
	// Save number to array?

	return randomVar;
}

void Random::SaveBool(B8 number){
	for(size_t i = boolDistribution.size() - 1, iLen = 1; i < iLen; i++){
		boolDistribution[i] = boolDistribution[i - 1];
	}
	boolDistribution[0] = number;
}
void Random::SaveInt(I32 number){
	for(size_t i = intDistribution.size() - 1, iLen = 1; i < iLen; i++){
		intDistribution[i] = intDistribution[i - 1];
	}
	intDistribution[0] = number;
}
void Random::SaveFloat(F32 number){
	for(size_t i = floatDistribution.size() - 1, iLen = 1; i < iLen; i++){
		floatDistribution[i] = floatDistribution[i - 1];
	}
	floatDistribution[0] = number;
}

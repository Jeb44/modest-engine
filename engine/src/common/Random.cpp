//Random.cpp
#include "common/Random.h"

Random::Random() {}
Random::~Random() {}

void Random::StartUp(){
	std::srand(std::time(nullptr));
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
	I32 randomVar = std::rand() / ((RAND_MAX + 1u) / range);
	
	// Compare number to rules
	// 1. not the same number as n_0
	// 2. not the same number as n_1
	// 3. inc/dec sequences of 4 numbers
	// 4. n numbers above/beneath average/median
	// 5. repeating pairs of numbers
	// 6. max of n same numbers in the last 10 numbers

	// Save number to array?

	return randomVar + start;
}
// Random.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#include <cstdlib>
#include <ctime>
#include <vector>

class Random {
public:
	explicit Random();
	virtual ~Random();

	void StartUp();
	void ShutDown();
	
	B8 GetBool();
	I32 GetInt(I32 start = 0, I32 end = RAND_MAX);
	F32 GetFloat(F32 start = 0.0f, F32 end = 1.0f);

	I32 GetIntNormalDistributed(I32 start = 0, I32 end = RAND_MAX);
	
private:
	void SaveBool(B8 number);
	void SaveInt(I32 number);
	void SaveFloat(F32 number);

	std::vector<B8> boolDistribution;
	std::vector<I32> intDistribution;
	std::vector<F32> floatDistribution;
};
// Random.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#include <cstdlib>
#include <ctime>

class Random {
public:
	explicit Random();
	virtual ~Random();

	static void StartUp();
	static void ShutDown();
	
	static B8 GetBool();
	static I32 GetInt(I32 start = 0, I32 end = RAND_MAX);
	static F32 GetFloat(F32 start = 0.0f, F32 end = 1.0f);

	static I32 GetIntNormalDistributed(I32 start = 0, I32 end = RAND_MAX);
	
};
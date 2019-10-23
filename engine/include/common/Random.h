// Random.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"
#include "common/Locator.h"

#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath> // Todo: replace with own implementation

#define INT_ITERATIONS_MAX 20
#define INT_SEQ_TOTAL_CHECKS 3
#define INT_SEQ_MAX_INC_DEC 3
#define INT_MEDIAN_TOTAL_CHECKS 8
#define INT_MEDIAN_MAX_DEVIATIONS 5
#define INT_PAIR_TOTAL_CHECKS 9
#define INT_SAME_NUMBERS_TOTAL_CHECKS 10
#define INT_MAX_SAME_NUMBERS 4

#define FLT_ITERATIONS_MAX 20
#define FLT_PAIR_MIN_DIFFERENCE 0.02f
#define FLT_TRIO_MIN_DIFFERENCE 0.1f
#define FLT_SEQ_TOTAL_CHECKS 4
#define FLT_SEQ_MAX_INC_DEC 4
#define FLT_MEDIAN_TOTAL_CHECKS 8
#define FLT_MEDIAN_MAX_DEVIATIONS 5



class Random {
public:
	explicit Random();
	virtual ~Random();

	void StartUp();
	void ShutDown();
	
	B8 GetBool();
	I32 GetInt(I32 start = 0, I32 end = RAND_MAX);
	F32 GetFloat(F32 start = 0.0f, F32 end = 1.0f);

	
	B8 GetEqualBool();
	I32 GetEqualInt(I32 start = 0, I32 end = RAND_MAX);
	F32 GetEqualFloat(F32 start = 0.0f, F32 end = 1.0f);
	
private:
	void SaveBool(B8 number);
	void SaveInt(I32 number);
	void SaveFloat(F32 number);

	std::vector<B8> boolDistribution;
	std::vector<I32> intDistribution;
	std::vector<F32> floatDistribution;
};
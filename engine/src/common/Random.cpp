//Random.cpp
#include "common/Random.h"

Random::Random() {}
Random::~Random() {}


void Random::StartUp(){
	std::srand(std::time(nullptr));

	ResizeBool(10);
	ResizeInt(0, 10, 10);
	ResizeFloat(0.0f, 1.0f, 10);
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

B8 Random::GetEqualBool(){
	B8 newEntry = GetBool();

	// Compare numbers to rules
	// 1. if at least same 4 numbers in sequence: negate the rolled number with 75% chance
	if(boolDistribution[2] ==  boolDistribution[1]){
		if(boolDistribution[2] == boolDistribution[0]){
			if(boolDistribution[2] == newEntry){
				newEntry = (GetFloat() <= 0.75? -newEntry : newEntry);
			}
		}
	}

	// 2. when entry 3 - 6 are the same as new - 2 then negate newest entry
	if(boolDistribution[2] == boolDistribution[6]){
		if(boolDistribution[1] == boolDistribution[5]){
			if(boolDistribution[0] == boolDistribution[4]){
				if(newEntry 		== boolDistribution[3]){
					newEntry = -newEntry;
				}
			}
		}
	}

	// 3. negate newest entry when entries new - 4 are 111000 or 000111
	if(boolDistribution[4] 					== true){
		if(boolDistribution[3] 				== true){
			if(boolDistribution[2] 			== true){
				if(boolDistribution[1] 		== false){
					if(boolDistribution[0] 	== false){
						if(newEntry			== false){
							newEntry = -newEntry;
						}
					}
				}
			}
		}
	}
	else {								//	== false
		if(boolDistribution[3] 				== false){
			if(boolDistribution[2] 			== false){
				if(boolDistribution[1] 		== true){
					if(boolDistribution[0] 	== true){
						if(newEntry 		== true){
							newEntry = -newEntry;
						}
					}
				}
			}
		}
	}
	
	SaveBool(newEntry);

	return newEntry;
}

I32 Random::GetEqualInt(I32 start, I32 end){
	ASSERT(start < end);
	I32 range = end - start;
	I32 newestEntry = 0;

	for(size_t i = 0, iLen = INT_ITERATIONS_MAX; i < iLen; i++){
		
		newestEntry = GetInt(start, end);
		std::cout << newestEntry << std::endl;
		
		// Compare number to rules
		// 1. not the same number as n_0
		if(newestEntry = intDistribution[0]) continue;

		// 2. not the same number as n_1
		if(newestEntry = intDistribution[1]) continue;
		
		#pragma region | Inc / Dec sequences of 4 numbers
		I32 checksCorrect = 0;
		ASSERT(INT_SEQ_TOTAL_CHECKS >= INT_SEQ_MAX_INC_DEC);
		for(size_t i = 0, iLen = INT_SEQ_TOTAL_CHECKS; i < iLen; i++){
			if(intDistribution[i] < intDistribution[i+1]){
				checksCorrect++;
				continue;
			}
			break;
		}
		if(checksCorrect >= FLT_SEQ_MAX_INC_DEC){
			continue;
		}
		checksCorrect = 0;
		for(size_t i = 0, iLen = INT_SEQ_TOTAL_CHECKS; i < iLen; i++){
			if(intDistribution[i] > intDistribution[i+1]){
				checksCorrect++;
				continue;
			}
			break;
		}
		if(checksCorrect >= INT_SEQ_MAX_INC_DEC){
			continue;
		}
		#pragma endregion

		#pragma region | N numbers above/beneath average/median
		I32 median = start + range / 2;
		I32 medianCount = 0;

		ASSERT(INT_MEDIAN_TOTAL_CHECKS <= intDistribution.size());
		ASSERT(INT_MEDIAN_TOTAL_CHECKS > INT_MEDIAN_MAX_DEVIATIONS);
		for(size_t i = 0, iLen = INT_MEDIAN_TOTAL_CHECKS; i < iLen; i++){
			intDistribution[i] > median? medianCount++ : medianCount--;
		}
		newestEntry > median? medianCount++ : medianCount--;
		if(std::abs(medianCount) > INT_MEDIAN_MAX_DEVIATIONS){
			continue;
		}
		#pragma endregion

		#pragma region | repeating pairs of numbers
		I32 pairPartner = intDistribution[0];
		B8 doContinue = false;
		ASSERT(INT_PAIR_TOTAL_CHECKS <= intDistribution.size());
		for(size_t i = 0, iLen = INT_PAIR_TOTAL_CHECKS; i < iLen; i++){
			if(newestEntry == intDistribution[i] &&
				pairPartner == intDistribution[i+1]){
					doContinue = true;
					break;
			}
		}
		if(doContinue) continue;
		#pragma endregion

		#pragma region | max of n same numbers in the last 10 numbers
		I32 sameNumbersCount = 0;
		for(size_t i = 0, iLen = INT_SAME_NUMBERS_TOTAL_CHECKS; i < iLen; i++){
			if(intDistribution[i] == newestEntry){
				sameNumbersCount++;
			}
		}
		if(sameNumbersCount >= INT_MAX_SAME_NUMBERS){
			continue;
		}
		#pragma endregion

		break;
	}
	// Save number to array?
	SaveInt(newestEntry);

	return newestEntry;
}

F32 Random::GetEqualFloat(F32 start, F32 end){
	ASSERT(start < end);
	F32 range = end - start;
	F32 newestEntry = 0;

	for(size_t i = 0, iLen = FLT_ITERATIONS_MAX; i < iLen; i++){
		newestEntry = GetFloat(start, end);
		
		// Compare numbers to rules
		// 1. Difference between to the first pair of numbers is > 0.02
		F32 diff1 = std::abs(newestEntry - floatDistribution[0]);
		if(diff1 < FLT_PAIR_MIN_DIFFERENCE){
			continue;
		}

		// 2. Difference between the first trio of numbers is > 0.1
		F32 diff2 = std::abs(newestEntry - floatDistribution[1]);
		F32 diff3 = std::abs(floatDistribution[0] - floatDistribution[1]);
		if(diff1 > diff2 && diff1 > diff3){
			if(diff1 < FLT_TRIO_MIN_DIFFERENCE){
				continue;
			}
		}
		else if(diff2 > diff1 && diff2 > diff3){
			if(diff2 < FLT_TRIO_MIN_DIFFERENCE){
				continue;
			}
		}
		else if(diff3 > diff1 && diff3 > diff2){
			if(diff3 < FLT_TRIO_MIN_DIFFERENCE){
				continue;
			}
		}

		// 3. max inc/dec sequences of 5 numbers
		I32 checksCorrect = 0;
		ASSERT(FLT_SEQ_TOTAL_CHECKS >= FLT_SEQ_MAX_INC_DEC);
		for(size_t i = 0, iLen = FLT_SEQ_TOTAL_CHECKS; i < iLen; i++){
			if(floatDistribution[i] < floatDistribution[i+1]){
				checksCorrect++;
				continue;
			}
			break;
		}
		if(checksCorrect >= FLT_SEQ_MAX_INC_DEC){
			continue;
		}

		checksCorrect = 0;
		for(size_t i = 0, iLen = FLT_SEQ_TOTAL_CHECKS; i < iLen; i++){
			if(floatDistribution[i] > floatDistribution[i+1]){
				checksCorrect++;
				continue;
			}
			break;
		}
		if(checksCorrect >= FLT_SEQ_MAX_INC_DEC){
			continue;
		}

		// 4. n numbers above/beneath average/median
		F32 median = start + range / 2;
		I32 medianCount = 0;
		ASSERT(FLT_MEDIAN_TOTAL_CHECKS <= floatDistribution.size());
		ASSERT(FLT_MEDIAN_TOTAL_CHECKS > FLT_MEDIAN_MAX_DEVIATIONS);
		for(size_t i = 0, iLen = FLT_MEDIAN_TOTAL_CHECKS; i < iLen; i++){
			floatDistribution[i] > median? medianCount++ : medianCount--;
		}
		newestEntry > median? medianCount++ : medianCount--;
		if(std::abs(medianCount) > FLT_MEDIAN_MAX_DEVIATIONS){
			continue;
		}

		break;
	}
	SaveFloat(newestEntry);

	return newestEntry;
}


void Random::ResizeBool(I32 size){
	ASSERT(size >= 6);
	boolDistribution.resize(size);
	
	for(size_t i = 0, iLen = size; i < iLen; i++){
		boolDistribution[i] = GetBool();
	}
	
	for(size_t i = 0, iLen = size; i < iLen; i++){
		GetEqualBool();
	}
}

void Random::ResizeInt(I32 start, I32 end, I32 size){
	ASSERT(size >= 10);
	intDistribution.resize(size);
	intCurrentMin = start;
	intCurrentMax = end;

	for(size_t i = 0, iLen = size; i < iLen; i++){
		intDistribution[i] = GetInt(start, end);
	}
	for(size_t i = 0, iLen = size; i < iLen; i++){
		GetEqualInt(start, end);
	}
}

void Random::ResizeFloat(F32 start, F32 end, I32 size){
	ASSERT(size >= 10);
	floatDistribution.resize(size);
	floatCurrentMin = start;
	floatCurrentMax = end;

	for(size_t i = 0, iLen = size; i < iLen; i++){
		floatDistribution[i] = GetFloat(start, end);
	}
	for(size_t i = 0, iLen = size; i < iLen; i++){
		GetEqualFloat(start, end);
	}
}

void Random::SaveBool(B8 number){
	for(size_t i = boolDistribution.size() - 1, iLen = 1; i > iLen; i--){
		boolDistribution[i] = boolDistribution[i - 1];
	}
	boolDistribution[0] = number;
}
void Random::SaveInt(I32 number){
	for(size_t i = intDistribution.size() - 1, iLen = 1; i > iLen; i--){
		intDistribution[i] = intDistribution[i - 1];
	}
	intDistribution[0] = number;
}
void Random::SaveFloat(F32 number){
	for(size_t i = floatDistribution.size() - 1, iLen = 1; i > iLen; i--){
		floatDistribution[i] = floatDistribution[i - 1];
	}
	floatDistribution[0] = number;
}

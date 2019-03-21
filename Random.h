#pragma once
#include <ctime>
#include <cstdlib>

class Random
{
private:
	int ivalue;
	float fvalue;

public:
	Random() = default;
	~Random() = default;

	static int iRand();
	static int RdPs();
	static bool iLeftRight();
	// static float fRandY();
	// static float fRandX();
};


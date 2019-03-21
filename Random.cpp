#include "Random.h"

int Random::iRand()
{
	return rand() % 4 + 0;
}

bool Random::iLeftRight()
{
	int a = rand() % 1000 + 1;
	
	if (a%2==0)
	{
		return false;
	}
	return true;
}

int Random::RdPs()
{
	int p = Random::iRand();
	switch (p)
	{
	case 0:
		return 150;
		break;
	case 1:
		return 200;
		break;
	case 2:
		return 500;
		break;
	case 3:
		return 700;
		break;
	case 4:
		return 500;
		break;

	default:
		return 400;
		break;
	}
}
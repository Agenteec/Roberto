#include "FeatureTester.h"

bool FeatureTester::MF()
{
	return false;
}

bool FeatureTester::TestSelector()
{
	switch (testNumber)
	{
	case 0:
		return false;
	case 1:
		return GF();
	case 2:
		return MF();
	default:
		return false;
	}
	
}

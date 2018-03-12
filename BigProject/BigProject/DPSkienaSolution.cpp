#include "DPSkienaSolution.h"



DPSkienaSolution::DPSkienaSolution()
{
}


DPSkienaSolution::~DPSkienaSolution()
{
}

bool DPSkienaSolution::isJumble(char * one, char * two, char * three)
{
	if (!*one && !*two && !*three)		// all strings empty, reached end of strings
	{
		return true;
	}
	if (*one != *three && *two != *three)	// neither element matches, not a jumble
	{
		return false;
	}
	if (*one == *two)						// both elements match 
	{
		bool try1 = isJumble(one + 1, two, three + 1);		// check if first element match makes next case true
		bool try2 = isJumble(one, two + 1, three + 1);		// if not, check for second element

		if (try1 == true)
		{
			return try1;
		}
		else if (try2 == true)
		{
			return try2;
		}
		else					// if neither future cases true, not a jumble
		{
			return false;
		}
	}
	else if (*one == *three)	// element in string one matches, advance string one to next element
	{
		return isJumble(one + 1, two, three + 1);
	}
	else if (*two == *three)	// element in string two matches, advance string two to next element
	{
		return isJumble(one, two + 1, three + 1);
	}
}

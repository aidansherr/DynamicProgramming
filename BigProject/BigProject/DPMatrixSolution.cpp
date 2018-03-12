#include "DPMatrixSolution.h"

DPMatrixSolution::DPMatrixSolution(char * one, char * two, char * three, int sz1, int sz2, int sz3)
{
	// create 2D array
	map = new bool *[sz1 + 1];
	for (int i = 0; i <= sz1; i++)
	{
		map[i] = new bool[sz2 + 1];
	}

	// init array to all false values
	for (int i = 0; i <= sz1; i++)
	{
		for (int j = 0; j <= sz2; j++)
		{
			map[i][j] = false;
		}
	}

	// init top row and first column to true
	for (int j = 0; j <= sz2; j++)
	{
		map[0][j] = true;
	}
	for (int i = 0; i <= sz1; i++)
	{
		map[i][0] = true;
	}

	// store all strings and sizes
	strg1 = one;
	strg2 = two;
	strg3 = three;
	size1 = sz1;
	size2 = sz2;
	size3 = sz3;
}


DPMatrixSolution::~DPMatrixSolution()
{
	// delete array 
	for (int i = 0; i < size2; i++)
	{
		delete[] map[i];
	}

	delete[] map;
}

bool DPMatrixSolution::isJumble()
{
	if (allStringsEmpty())
	{
		return true;
	}
	if (jumbleTooSmall())
	{
		return false;
	}

	for (int i = 1; i <= size1; i++)
	{
		for (int j = 1; j <= size2; j++)
		{			
			// strg1 length 0 and char in strg1 and strg3 match
			if ((size1 == 0) && (strg2[j - 1] == strg3[j - 1]))
			{
				map[i][j] = map[i][j - 1];
			}
			// strg2 length 0 and char in strg2 and strg3 match
			else if ((size2 == 0) && (strg1[i - 1] == strg3[i - 1]))
			{
				map[i][j] = map[i - 1][j];
			}
			// Char in strg3 matches char in strg1 but not in strg2
			else if ((strg1[i - 1] == strg3[i + j - 1]) && (strg2[j - 1] != strg3[i + j - 1]))
			{
				map[i][j] = map[i - 1][j];
			}
			// Char in strg3 matches char in strg2 but not in strg1
			else if ((strg2[j - 1] == strg3[i + j - 1]) && (strg1[i - 1] != strg3[i + j - 1]))
			{
				map[i][j] = map[i][j - 1];
			}
			// Char in strg3 matches both char in strg1 and strg2
			else if ((strg1[i - 1] == strg3[i + j - 1]) && (strg2[j - 1] == strg3[i + j - 1]))
			{
				if (map[i - 1][j] || map[i][j - 1])
				{
					map[i][j] = true;
				}
				else
				{
					map[i][j] = false;
				}
			}
		}
	}

	return map[size1][size2];
}

bool DPMatrixSolution::allStringsEmpty()
{
	if (size1 == 0 && size2 == 0 && size3 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool DPMatrixSolution::jumbleTooSmall()
{
	if (size3 != (size1 + size2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
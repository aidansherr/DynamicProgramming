#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include "DPMatrixSolution.h"
#include "DPSkienaSolution.h"

using namespace std;

int main()
{
	clock_t startTime;
	double timePassed;
	string string1;
	string string2;
	string lgString;

	cout << "Enter the jumbled string: ";
	getline(cin, lgString);
	cout << "Enter the first string you would like to search for in the jumble: ";
	getline(cin, string1);
	cout << "Enter the second string you would like to search for in the jumble: ";
	getline(cin, string2);

	transform(string1.begin(), string1.end(), string1.begin(), tolower);
	transform(string2.begin(), string2.end(), string2.begin(), tolower);
	transform(lgString.begin(), lgString.end(), lgString.begin(), tolower);

	char * stringOne = &string1[0];
	char * stringTwo = &string2[0];
	char * jumbledString = &lgString[0];

	int size1 = string1.size();
	int size2 = string2.size();
	int lgSize = lgString.size();

	bool check = false;

	// Matrix
	cout << "Matrix Solution: " << endl;
	startTime = clock();
	for (volatile int i = 0; i < 100000; i++)
	{
		DPMatrixSolution matrix(stringOne, stringTwo, jumbledString, size1, size2, lgSize);
		check = matrix.isJumble();
	}
	timePassed = (clock() - startTime) / (CLOCKS_PER_SEC/1000);
	
	if (check)
	{
		cout << "The first string " << string1 << " and the second string " << string2
			<< " are a jumble of the larger string " << lgString << endl;
	}
	else
	{
		cout << "No jumble found for the first string " << string1 << " and the second string " 
			<< string2 << " in the larger string " << lgString  << endl;
	}
	cout << "Time elapsed: " << timePassed << " milliseconds" << endl << endl;

	// Skiena
	cout << "Skiena's Solution: " << endl;
	startTime = clock();
	for (volatile int i = 0; i < 100000; i++)
	{
		DPSkienaSolution skiena;
		check = skiena.isJumble(stringOne, stringTwo, jumbledString);
	}
	//this_thread::sleep_for(chrono::seconds(5));
	timePassed = (clock() - startTime) / (CLOCKS_PER_SEC/1000);

	if (check)
	{
		cout << "The first string " << string1 << " and the second string " << string2 
			<< " are a jumble of the larger string " << lgString << endl;
	}
	else
	{
		cout << "No jumble found for the first string " << string1 << " and the second string "
			<< string2 << " in the larger string " << lgString << endl;
	}
	cout << "Time elapsed: " << timePassed << " milliseconds" << endl << endl;

	cin.get();

	return 0; 
}
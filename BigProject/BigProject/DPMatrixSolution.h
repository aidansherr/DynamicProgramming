#pragma once
class DPMatrixSolution
{
public:
	DPMatrixSolution(char * one, char * two, char * three, int sz1, int sz2, int sz3);
	~DPMatrixSolution();

	bool isJumble();

private:
	char * strg1;
	char * strg2;
	char * strg3;
	int size1;
	int size2; 
	int size3;
	bool ** map;
	
	bool allStringsEmpty();
	bool jumbleTooSmall();
};


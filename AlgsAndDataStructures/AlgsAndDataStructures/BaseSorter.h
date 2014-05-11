#pragma once
#include <vector>
#include <array>
#include <ctime>
using namespace std;

class BaseSorter
{
public:
	BaseSorter(void);
	~BaseSorter(void);

	virtual double sort(vector<int>, vector<int> &) = 0;

private:
	int arraySize;
	
};


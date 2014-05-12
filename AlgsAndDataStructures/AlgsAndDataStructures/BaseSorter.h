#pragma once
#include <vector>
#include <array>
#include <ctime>
using namespace std;

#define INSERTION_SORT 1
#define MERGE_SORT 2

class BaseSorter
{
public:
	BaseSorter(void);
	~BaseSorter(void);

	virtual double sort(vector<int>, vector<int> &) = 0;
	

private:
	int arraySize;

protected:
	void printResults(int, vector<int>);
	
};


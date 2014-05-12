#pragma once
#include "basesorter.h"

class MergeSorter :
	public BaseSorter
{
public:
	MergeSorter(void);
	~MergeSorter(void);

	double sort(vector<int>, vector<int> &);

private:
	vector<int> merge(vector<int>, vector<int>);
	vector<int> mergeSort(vector<int>);
};


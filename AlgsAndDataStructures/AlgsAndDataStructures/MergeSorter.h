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
	void merge(vector<int>, int, int, int, vector<int> &);
	void mergeSort(vector<int>, int, int, vector<int> &);
};


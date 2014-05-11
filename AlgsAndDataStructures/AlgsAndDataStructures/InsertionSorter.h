#pragma once
#include "basesorter.h"

class InsertionSorter :
	public BaseSorter
{
public:
	InsertionSorter(void);
	~InsertionSorter(void);

	double sort(vector<int>, vector<int> &);
};


#include "StdAfx.h"
#include "InsertionSorter.h"

InsertionSorter::InsertionSorter(void)
{
}

InsertionSorter::~InsertionSorter(void)
{
}

double InsertionSorter::sort(vector<int> vectorToSort, vector<int> &sortedVector)
{
	clock_t startTime;
	clock_t endTime;

	startTime = clock();

	int key = 0;
	int insertionIndex = 0;
	for(int keyIndex = 1; keyIndex < vectorToSort.size(); keyIndex++)
	{
		key = vectorToSort[keyIndex];
		insertionIndex = keyIndex - 1;
		while( insertionIndex >= 0 && vectorToSort[insertionIndex] > key)
		{
			vectorToSort[insertionIndex + 1] = vectorToSort[insertionIndex];
			insertionIndex -= 1;
		}
		vectorToSort[insertionIndex + 1] = key;
	}

	endTime = clock();

	sortedVector = vectorToSort;

	return difftime(endTime, startTime) / (double) CLOCKS_PER_SEC;
}
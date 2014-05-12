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

	//printf("un"); printResults(vectorToSort);

	int key = 0;
	int insertionIndex = 0;
	for (int keyIndex = 1; keyIndex < vectorToSort.size(); keyIndex++)
	{
		// Store key value
		key = vectorToSort[keyIndex];

		// Set initial insertion index
		insertionIndex = keyIndex - 1;

		// Shift all preceeding values greater than the key to the right by one to make room for insertion 
		while (insertionIndex > -1 && vectorToSort[insertionIndex] > key)
		{
			vectorToSort[insertionIndex + 1] = vectorToSort[insertionIndex];
			insertionIndex--;
		}

		// Insert key value
		vectorToSort[insertionIndex + 1] = key;
	}

	sortedVector = vectorToSort;

	endTime = clock();

	printResults(INSERTION_SORT, sortedVector);

	return difftime(endTime, startTime) / (double) CLOCKS_PER_SEC;
}
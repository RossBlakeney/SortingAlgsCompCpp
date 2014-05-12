#include "StdAfx.h"
#include "MergeSorter.h"


MergeSorter::MergeSorter(void)
{
}


MergeSorter::~MergeSorter(void)
{
}

double MergeSorter::sort(vector<int> vectorToSort, vector<int> &sortedVector)
{
	clock_t startTime;
	clock_t endTime;

	startTime = clock();

	sortedVector = mergeSort(vectorToSort);

	endTime = clock();

	printResults(MERGE_SORT, sortedVector);

	return difftime(endTime, startTime) / (double)CLOCKS_PER_SEC;
}

vector<int> MergeSorter::merge(vector<int> leftSubVector, vector<int> rightSubVector)
{
	vector<int> resultVector;

	vector<int>::iterator leftIt = leftSubVector.begin();
	vector<int>::iterator rightIt = rightSubVector.begin();

	// Sort the two vectors until one of the vectors run out of data to sort
	while (leftIt != leftSubVector.end() && rightIt != rightSubVector.end())
	{
		if (*leftIt < *rightIt)
		{
			resultVector.push_back(*leftIt);
			leftIt++;
		}
		else
		{
			resultVector.push_back(*rightIt);
			rightIt++;
		}
	}

	// Toss any leftovers into the resultant (nothing to compare to)
	while (leftIt != leftSubVector.end())
	{
		resultVector.push_back(*leftIt);
		leftIt++;
	}
	while (rightIt != rightSubVector.end())
	{
		resultVector.push_back(*rightIt);
		rightIt++;
	}

	return resultVector;
}

vector<int> MergeSorter::mergeSort(vector<int> vectorToSort)
{
	// Trivial case
	if (vectorToSort.size() <= 1)
	{
		return vectorToSort;
	}

	// Determine middle position of the data set
	vector<int>::iterator middleIt = vectorToSort.begin() + (vectorToSort.size() / 2);

	// Split data into two vectors
	vector<int> leftSubVector(vectorToSort.begin(), middleIt);
	vector<int> rightSubVector(middleIt, vectorToSort.end());

	// Recursive merge sort of the two vectors
	leftSubVector = mergeSort(leftSubVector);
	rightSubVector = mergeSort(rightSubVector);

	// Merge sorted reults
	return merge(leftSubVector, rightSubVector);
}


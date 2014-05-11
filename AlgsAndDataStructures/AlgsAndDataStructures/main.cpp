// AlgsAndDataStructures.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <ctime>

#include "stdafx.h"
#include "definitions.h"
#include "InsertionSorter.h"
#include "MergeSorter.h"

using namespace std;

void printVector(int, vector<int>);
void populateRandomVector(vector<int> &, int);

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> randomVector;
	vector<int> sortedVector;
	InsertionSorter insertionSorter = InsertionSorter();
	MergeSorter mergeSorter = MergeSorter();
	double cummulativeInsertionSortDuration = 0;
	double cummulativeMergeSortDuration = 0;
	double averageInsertionSortDuration = 0;
	double averageMergeSortDuration = 0;

	// Set random seed based on system time
	srand(time(NULL));

	int timesToRun = 1;			//<<<<<<<<<<<<<
	int datasetLength = 4;		//<<<<<<<<<<<<<
	int runCount = 0;
	while(runCount < timesToRun)
	{
		populateRandomVector(randomVector, datasetLength);
		//printVector(RANDOM_VECTOR, randomVector);

		// Insertion Sort - n^2
		cummulativeInsertionSortDuration += insertionSorter.sort(randomVector, sortedVector);

		// Merge Sort - n lg n
		printVector(RANDOM_VECTOR, randomVector);
		sortedVector.clear();
		mergeSorter.sort(randomVector, sortedVector);
		printVector(SORTED_VECTOR, sortedVector);


		// Heap Sort - n lg n
		//heapSort(randomArray, sortedArray);
		// Quick Sort - n lg n
		// Counting Sort - k + n
		// Radix Sort - d(n + k)
		// Bucket Sort - n

		runCount++;
	}
	
	averageInsertionSortDuration = cummulativeInsertionSortDuration / (double)timesToRun;

	printf("Insertion Sort Duration: %f\n", averageInsertionSortDuration);

	return 0;
}

void populateRandomVector(vector<int> &vectorToFill, int vectorSize)
{
	vectorToFill.clear();
	for(int i = 0; i < vectorSize; i++)
	{
		vectorToFill.push_back(rand() % 100 + 1);
	}
}

void printVector(int vectorType, vector<int> vectorToPrint)
{
	if(vectorType == RANDOM_VECTOR)
	{
		printf("randomArray : ");
	}
	else if(vectorType == SORTED_VECTOR)
	{
		printf("sortedArray : ");
	}

	printf("[ ");
	for(vector<int>::iterator it = vectorToPrint.begin(); it != vectorToPrint.end(); ++it)
	{
		printf("%i", *it);
		if(it < vectorToPrint.end() - 1)
		{
			printf(", ");
		}
	}
	printf(" ]\n");
}
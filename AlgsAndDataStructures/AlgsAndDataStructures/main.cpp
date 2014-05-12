// AlgsAndDataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "definitions.h"
#include "InsertionSorter.h"
#include "MergeSorter.h"

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <iostream>

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
	double cummulativeHeapSortDuration = 0;
	double cummulativeQuickSortDuration = 0;
	double averageInsertionSortDuration = 0;
	double averageMergeSortDuration = 0;
	double averageHeapSortDuration = 0;
	double averageQuickSortDuration = 0;

	// Set random seed based on system time
	srand(time(NULL));

	int timesToRun = 0;
	int datasetLength = 0;
	
	// These input statements will need to be guarded !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	printf("Enter the number of times to run the test.\n> ");
	cin >> timesToRun;
	printf("Enter the size of the data set to use.\n> ");
	cin >> datasetLength;
	
	int runCount = 0;
	while(runCount < timesToRun)
	{
		populateRandomVector(randomVector, datasetLength);

		// Insertion Sort - n^2
		sortedVector.clear();
		cummulativeInsertionSortDuration += insertionSorter.sort(randomVector, sortedVector);

		// Merge Sort - n lg n
		sortedVector.clear();
		cummulativeMergeSortDuration += mergeSorter.sort(randomVector, sortedVector);
		
		// Heap Sort - n lg n
		//printVector(RANDOM_VECTOR, randomVector);
		//cummulativeHeapSortDuration += heapSort(randomArray, sortedArray);
		//printVector(SORTED_VECTOR, sortedVector);
		// Quick Sort - n lg n
		// Counting Sort - k + n
		// Radix Sort - d(n + k)
		// Bucket Sort - n

		runCount++;
	}
	
	averageInsertionSortDuration = cummulativeInsertionSortDuration / (double)timesToRun;
	averageMergeSortDuration = cummulativeMergeSortDuration / (double)timesToRun;
	averageHeapSortDuration = cummulativeHeapSortDuration / (double)timesToRun;

	printf("Insertion Sort Duration: %f\n", averageInsertionSortDuration);
	printf("Merge Sort Duration: %f\n", averageMergeSortDuration);
	printf("Heap Sort Duration: %f\n", averageHeapSortDuration);

	return 0;
}

void populateRandomVector(vector<int> &vectorToFill, int vectorSize)
{
	vectorToFill.clear();
	for(int i = 0; i < vectorSize; i++)
	{
		vectorToFill.push_back(rand() % 10000 + 1);
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
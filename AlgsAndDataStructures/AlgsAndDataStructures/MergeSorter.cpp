#include "StdAfx.h"
#include "MergeSorter.h"

#define MAX_INT 99999

MergeSorter::MergeSorter(void)
{
}


MergeSorter::~MergeSorter(void)
{
}

double MergeSorter::sort(vector<int> vectorToSort, vector<int> &sortedVector)
{
	mergeSort(vectorToSort, 0, vectorToSort.size(), sortedVector);

	return 0;
}

void MergeSorter::merge(vector<int> vectorToSort, int leftIndex, int centerIndex, int rightIndex, vector<int> &sortedVector)
{
	if(leftIndex < 0)
	{
		printf("[ERR] leftIndex < 0");
		return;
	}
	else if(leftIndex > vectorToSort.size())
	{
		printf("[ERR] leftIndex > vectorToSort.size()");
		return;
	}
	else if(centerIndex > vectorToSort.size())
	{
		printf("[ERR] centerIndex > vectorToSort.size()");
		return;
	}
	else if(centerIndex < 0)
	{
		printf("[ERR] centerIndex < 0");
		return;
	}
	else if(rightIndex > vectorToSort.size())
	{
		printf("[ERR] rightIndex > vectorToSort.size()");
		return;
	}
	else if(rightIndex < 0)
	{
		printf("[ERR] rightIndex < 0");
		return;
	}
	else if(vectorToSort.size() < 1)
	{
		printf("[ERR] vectorToSort.size() < 1");
		return;
	}


	int lengthOfLeftSubArray = centerIndex - leftIndex + 1;
	int lengthOfRightSubArray = rightIndex - centerIndex;

	printf("leftIndex: %i\n", leftIndex);
	printf("centerIndex: %i\n", centerIndex);
	printf("rightIndex: %i\n", rightIndex);
	printf("lengthOfLeftSubArray: %i\n", lengthOfLeftSubArray);
	printf("lengthOfRightSubArray: %i\n", lengthOfRightSubArray);

	vector<int> leftSubVector;
	vector<int> rightSubVector;
	
	// Populate the left and right vectors
	for(int i = 0; i < lengthOfLeftSubArray; i++)
	{
		leftSubVector.push_back(vectorToSort[leftIndex + i]);
	}
	for(int i = 0; i < lengthOfRightSubArray; i++)
	{
		rightSubVector.push_back(vectorToSort[centerIndex + 1 + i]);
	}

	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////
	
	printf("vectorToSort: ");
	for(int i = 0; i < vectorToSort.size(); i++)
	{
		printf("%i ", vectorToSort[i]);
	}
	printf("\n");
	printf("leftSubVector: ");
	for(int i = 0; i < leftSubVector.size(); i++)
	{
		printf("%i ", leftSubVector[i]);
	}
	printf("\n");
	printf("rightubVector: ");
	for(int i = 0; i < rightSubVector.size(); i++)
	{
		printf("%i ", rightSubVector[i]);
	}
	printf("\n");
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////
	leftSubVector.push_back(MAX_INT);
	rightSubVector.push_back(MAX_INT);

	int currentLeftSubVectorIndex = 0;
	int currentRightSubVectorIndex = 0;
	for(int currentPrimaryVectorIndex = leftIndex; currentPrimaryVectorIndex < rightIndex; currentPrimaryVectorIndex++)
	{
		if(leftSubVector[currentLeftSubVectorIndex] <= rightSubVector[currentRightSubVectorIndex])
		{
			vectorToSort[currentPrimaryVectorIndex] = leftSubVector[currentLeftSubVectorIndex];
			currentLeftSubVectorIndex++;
		}
		else
		{
			vectorToSort[currentPrimaryVectorIndex] = rightSubVector[currentRightSubVectorIndex];
			currentRightSubVectorIndex++;
		}
	}

	sortedVector = vectorToSort;
	for(int i = 0; i < sortedVector.size(); i++)
	{
		printf("%i ", sortedVector[i]);
	}
	printf("\n\n");
}

void MergeSorter::mergeSort(vector<int> vectorToSort, int leftIndex, int rightIndex, vector<int> &sortedVector)
{
	if(leftIndex < rightIndex)
	{
		int centerIndex = (leftIndex + rightIndex) / 2;
		printf("centerIndex: %i\n", centerIndex);
		mergeSort(vectorToSort, leftIndex, centerIndex, sortedVector);
		mergeSort(vectorToSort, centerIndex + 1, rightIndex, sortedVector);
		merge(vectorToSort, leftIndex, centerIndex, rightIndex, sortedVector);
	}
}
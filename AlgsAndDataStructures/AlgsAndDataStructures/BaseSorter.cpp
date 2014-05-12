#include "StdAfx.h"
#include "BaseSorter.h"



BaseSorter::BaseSorter(void)
{
}


BaseSorter::~BaseSorter(void)
{
}

void BaseSorter::printResults(int methodTag, vector<int> vectorToPrint)
{
	switch (methodTag)
	{
		case INSERTION_SORT:
			printf("Insertion sort results:\n");
			break;
		case MERGE_SORT:
			printf("Merge sort results:\n");
			break;
		default:
			break;
	}

	if (vectorToPrint.size() > 15)
	{
		printf("  [ %i %i %i %i %i ... %i %i %i %i %i ... %i %i %i %i %i ]\n",
			vectorToPrint[0],
			vectorToPrint[1],
			vectorToPrint[2],
			vectorToPrint[3],
			vectorToPrint[4],
			vectorToPrint[vectorToPrint.size() / 2 - 2],
			vectorToPrint[vectorToPrint.size() / 2 - 1],
			vectorToPrint[vectorToPrint.size() / 2],
			vectorToPrint[vectorToPrint.size() / 2 + 1],
			vectorToPrint[vectorToPrint.size() / 2 + 2],
			vectorToPrint[vectorToPrint.size() - 5],
			vectorToPrint[vectorToPrint.size() - 4],
			vectorToPrint[vectorToPrint.size() - 3],
			vectorToPrint[vectorToPrint.size() - 2],
			vectorToPrint[vectorToPrint.size() - 1]
			);
	}
	else
	{
		printf("  [ ");
		for (vector<int>::iterator it = vectorToPrint.begin(); it != vectorToPrint.end(); ++it)
		{
			printf("%i", *it);
			if (it < vectorToPrint.end() - 1)
			{
				printf(", ");
			}
		}
		printf(" ]\n");
	}
}
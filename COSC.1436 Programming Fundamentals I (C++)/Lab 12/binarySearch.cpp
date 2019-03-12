#include <string.h>

#include "BinarySearch.h"

int binarySearch(const char A[], char B)
{
	int		First;
	int		Middle;
	int		Last;

	First = 0;
	Last = strlen(A) - 1;
	while (First <= Last)
	{
		Middle = (First + Last) / 2;
		if (B == A[Middle])
			return Middle;
		else
			if (B < A[Middle])
				Last = Middle - 1;
			else
				First = Middle + 1;
	}
	return -1;
}

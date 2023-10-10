#include "search_algos.h"

/**
  * binary_search - one of the searching algorithms
  * @array: A pinter of the elements
  * @size: size of the elements
  * @value: the number serarched
  * Return: the index when success
  */
int binary_search(int *array, size_t size, int value)
{
	size_t j, l, r;

	if (array == NULL)
		return (-1);

	for (l = 0, r = size - 1; r >= l;)
	{
		printf("Searching in array: ");
		for (j = l; j < r; j++)
			printf("%d, ", array[j]);
		printf("%d\n", array[j]);

		j = l + (r - l) / 2;
		if (array[j] == value)
			return (j);
		if (array[j] > value)
			r = j - 1;
		else
			l = j + 1;
	}

	return (-1);
}

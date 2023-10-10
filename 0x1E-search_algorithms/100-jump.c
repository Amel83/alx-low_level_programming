#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value
 * @array:  array
 * @size: size of array
 * @value: value to be searched
 * Return: index
 */
int jump_search(int *array, size_t size, int value)
{
	int i, mm, kk, pr;

	if (array == NULL || size == 0)
		return (-1);

	mm = (int)sqrt((double)size);
	kk = 0;
	pr = i = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", i, array[i]);

		if (array[i] == value)
			return (i);
		kk++;
		pr = i;
		i = kk * mm;
	} while (i < (int)size && array[i] < value);

	printf("Value found between indexes [%d] and [%d]\n", pr, i);

	for (; pr <= i && pr < (int)size; pr++)
	{
		printf("Value checked array[%d] = [%d]\n", pr, array[pr]);
		if (array[pr] == value)
			return (pr);
	}

	return (-1);
}

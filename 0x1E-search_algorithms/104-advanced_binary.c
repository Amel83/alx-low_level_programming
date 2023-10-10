#include "search_algos.h"

/**
 * rec_search - searches for index
 * @array: input array
 * @size: size of array
 * @value: value to be searched
 * Return: index of search
 */
int rec_search(int *array, size_t size, int value)
{
	size_t h = size / 2;
	size_t j;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (j = 0; j < size; j++)
		printf("%s %d", (j == 0) ? ":" : ",", array[j]);

	printf("\n");

	if (h && size % 2 == 0)
		h--;

	if (value == array[h])
	{
		if (h > 0)
			return (rec_search(array, h + 1, value));
		return ((int)h);
	}

	if (value < array[h])
		return (rec_search(array, h + 1, value));

	h++;
	return (rec_search(array + h, size - h, value) + h);
}

/**
 * advanced_binary - calls to it 
 * @array: points to array
 * @size: size of array
 * @value: value to be searched
 * Return: index of number
 */
int advanced_binary(int *array, size_t size, int value)
{
	int i;

	i = rec_search(array, size, value);

	if (i >= 0 && array[i] != value)
		return (-1);
	return (i);
}

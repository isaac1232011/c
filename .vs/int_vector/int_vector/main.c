#include <stdio.h>
#include <stdlib.h>
#include "int_vector.h"

void bubble_sort(MY_VECTOR hVector);

void my_swap(int* a, int* b);

int main(int argc, char* argv[])
{
	MY_VECTOR hVector = NULL;
	int i;

	hVector = int_vector_init_default(); //First book-end
	if (hVector == NULL)
	{
		printf("Failed to allocate int_vector object.\n");
		exit(1);
	}

	//happy fun time (do stuff)

	for (i = 0; i < 100; i++)
	{
		if (int_vector_push_back(hVector, rand()) == FAILURE)
		{
			printf("Failed to add item\n");
			exit(1);
		}
		printf("%d/%d\n", int_vector_get_size(hVector), int_vector_get_capacity(hVector));
	}

	for (i = 0; i < int_vector_get_size(hVector); i++)
	{
		printf("%d is the element at the index %d\n", *int_vector_at(hVector, i), i);
	}

	printf("******\n");

	bubble_sort(hVector);

	for (i = 0; i < int_vector_get_size(hVector); i++)
	{
		printf("%d is the element at the index %d\n", *int_vector_at(hVector, i), i);
	}


	int_vector_destroy(&hVector); //Last book-end
	if (hVector == NULL)
	{
		printf("VICTORY!\n");
	}

	return 0;
}

void bubble_sort(MY_VECTOR hVector)
{
	int i;
	int j;

	for (i = 0; i < int_vector_get_size(hVector) - 1; i++)
	{
		for (j = 0; j < int_vector_get_size(hVector) - 1; j++)
		{
			if (*int_vector_at(hVector, j) > *int_vector_at(hVector, j + 1))
			{
				my_swap(int_vector_at(hVector, j), int_vector_at(hVector, j + 1));
			}
		}
	}
}

void my_swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
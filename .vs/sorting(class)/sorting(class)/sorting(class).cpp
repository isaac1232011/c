#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
void vanilla_bubble_sort(int numbers[], int size);
void my_swap(int* a, int* b);

void selection_sort(int numbers[], int size);
int find_index_of_min(int numbers[], int size, int index_of_start);

void vanilla_insertion_sort(int numbers[], int size);
void vanilla_insertion_sort_with_shifting(int numbers[], int size);
void vanilla_insertion_sort_with_shifting_and_sentinel(int numbers[], int size);
void fix_up(int heap[], int index);

void fix_down(int heap[], int index, int size);

void heapify(int numbers[], int size);
int main(int argc, char *argv[])
{
	int numbers[SIZE];
	int i;
	for (i = 0; i < SIZE; i++) {
		numbers[i] = rand();
		//printf("%d\n", numbers[i]);
	}

	//vanilla_bubble_sort(numbers,SIZE);
	//selection_sort(numbers, SIZE);
	vanilla_insertion_sort(numbers, SIZE);
	//vanilla_insertion_sort_with_shifting(numbers, SIZE);
	//vanilla_insertion_sort_with_shifting_and_sentinel(numbers, SIZE);
	/*for (i = 1; i < SIZE; i++)
	{
	fix_up(numbers, i);
	}*/
	printf("-------------------\n");
	for (i = 0; i < SIZE; i++) {
		printf("%d\n", numbers[i]);
	}
	printf("-------------------\n");

	heapify(numbers, SIZE);
	for (i = 0; i < SIZE; i++) {
		printf("%d\n", numbers[i]);
	}
	printf("-------------------\n");


	printf("DONE!\n");

	return 0;
}
void vanilla_insertion_sort_with_shifting_and_sentinel(int numbers[], int size) {
	int i;
	int j;
	int temp;
	my_swap(&numbers[0], &numbers[find_index_of_min(numbers, size, 0)]);
	//smallest into the position
	for (i = 1; i < size; i++) 
	{
		j = 0;
		temp = numbers[i];
		while (temp < numbers[i - j - 1]) //1-0-1=0
		{
			numbers[i - j] = numbers[i - j - 1];
			j++;
		}
		numbers[i - j] = temp;
	}
}

void vanilla_insertion_sort_with_shifting(int numbers[], int size) {
	int i;
	int j;
	int temp;
	for (i = 1; i < size; i++) {
		j = 0;
		temp = numbers[i];
		while (i - 1 - j >= 0 && temp < numbers[i - j - 1])
		{
			numbers[i - j] = numbers[i - j - 1];
			j++;
		}
		numbers[i - j] = temp;
	}
}

void vanilla_insertion_sort(int numbers[], int size) {
	int i;
	int j;
	for (i = 1; i < size; i++) {
		j = 0;
		while (i - 1 - j > 0 && numbers[i - j] < numbers[i - j - 1])
		{
			my_swap(&numbers[i - j], &numbers[i - j - 1]);
			j++;
		}
	}
}

void selection_sort(int numbers[], int size) {
	int i;
	for (i = 0; i < size - 1; i++) {
		my_swap(&numbers[i], &numbers[find_index_of_min(numbers, size, i)]);
	}
}

int find_index_of_min(int numbers[], int size, int index_of_start) {
	int i;
	int index_of_min = index_of_start;
	for (i = index_of_start + 1; i < size; i++) {
		if (numbers[i] < numbers[index_of_min]) {
			index_of_min = i;
		}
	}
	return index_of_min;
}

void vanilla_bubble_sort(int numbers[], int size) {
	int i = 0, j = 0;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) { // ignore the part we have already sorted
			if (numbers[j] > numbers[j + 1]) {
				my_swap(&numbers[j], &numbers[j + 1]);
			}
		}
	}
}

void my_swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void fix_up(int heap[], int index)
{
	int index_of_parent;
	index_of_parent = (index - 1) / 2;
	int temp;

	if (index >= 1 && heap[index] > heap[index_of_parent])
	{
		temp = heap[index];
		heap[index] = heap[index_of_parent];
		heap[index_of_parent] = temp;
		fix_up(heap, index_of_parent);
	}
}

void fix_down(int heap[], int index, int size)
{
	int index_of_left_child;
	int index_of_right_child;
	int index_of_larger_child = size;
	int temp;

	index_of_left_child = index * 2 + 1;
	index_of_right_child = index * 2 + 2;

	if (index_of_right_child < size)  //we have two children
	{
		if (heap[index_of_left_child] > heap[index_of_right_child])
		{
			index_of_larger_child = index_of_left_child;
		}
		else
		{
			index_of_larger_child = index_of_right_child;
		}
	}
	else if (index_of_left_child < size) //we have only one child
	{
		index_of_larger_child = index_of_left_child;
	}

	if (index_of_larger_child < size && heap[index_of_larger_child] > heap[index])
	{
		temp = heap[index];
		heap[index] = heap[index_of_larger_child];
		heap[index_of_larger_child] = temp;
		fix_down(heap, index_of_larger_child, size);
	}

}

void heapify(int numbers[], int size)
{
	int i;
	for (i = (size - 2) / 2; i >= 0; i--)
	{
		fix_down(numbers, i, size);
	}
}

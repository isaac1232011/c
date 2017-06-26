#include <stdlib.h>
#include "int_queue.h"
#include "status.h"
#include <string.h>
struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

//THE KNOWN TYPE
struct queue
{
	Node* head;
};
typedef struct queue Queue;

QUEUE queue_init_default(void)
{
	Queue* pQueue = (Queue*)malloc(sizeof(Queue));
	if (pQueue != NULL)
	{
		pQueue->head = NULL;

	}
	return pQueue;
}
Status queue_enqueue(QUEUE hQueue, int item)
{
	Queue* pQueue = (Queue*)hQueue;
	Node* temp;

	if (pQueue->head == NULL)
	{
		pQueue->head = (Node*)malloc(sizeof(Node));
		pQueue->head->data = item;
		pQueue->head->next = NULL;
	}
	else
	{
		temp = pQueue->head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = (Node*)malloc(sizeof(Node));
		if (temp->next == NULL)
		{
			exit(1);
		}
		temp->next->data = item;
		temp->next->next = NULL;
	}
}

Status queue_service(QUEUE hQueue)
{
	Queue* pQueue = (Queue*)hQueue;
	Node* temp;

	if (pQueue->head == NULL)
	{
		return FAILURE;
	}
	else
	{
		temp = pQueue->head;
		pQueue->head = pQueue->head->next;
		free(temp);
	}
	return SUCCESS;
}
Boolean queue_empty(QUEUE hQueue)
{
	Queue* pQueue = (Queue*)hQueue;
	return (Boolean)(pQueue->head == NULL);
}

int queue_front(QUEUE hQueue, Status* pStatus)
{
	Queue* pQueue = (Queue*)hQueue;

	//if pStatus is NULL then ignore the status.
	if (queue_empty(hQueue))
	{
		if (pStatus != NULL)
		{
			*pStatus = FAILURE;
		}
		return -8887888;
	}

	if (pStatus != NULL)
	{
		*pStatus = SUCCESS;
	}

	return pQueue->head->data;
}

void clear_buffer(void)
{
	char ch;
	scanf("%c", &ch);
	while (ch != '\n')
	{
		scanf("%c", &ch);
	}
}

//Queue* pLeft = (Queue*)hLeft;
//Queue* pRight = (Queue*)hRight;
void queue_destroy(QUEUE* phQueue)
{
	Queue* pQueue = (Queue*)*phQueue;
	Node* temp;
	if (pQueue != NULL)
	{
		while (pQueue->head != NULL)
		{
			temp = pQueue->head;
			pQueue->head = pQueue->head->next;
			free(temp);
		}
		free(pQueue);
		*phQueue = NULL;
	}
}
int main(QUEUE hLeft, QUEUE hRight)
{

	int i = 0, boat_len = 0, boat_lenOG = 0, numofcars = 0, car_len = 0, space = 0, counter = 0;
	char side = ' ';
	scanf("%d %d", &boat_lenOG, &numofcars);
	clear_buffer();
	for (i = 0; i < numofcars; i++)
	{
		scanf("%d %c", &car_len, &side);
		clear_buffer();
		if (side == 'l')
		{
			queue_enqueue(hLeft, car_len);
		}
		else
		{
			queue_enqueue(hRight, car_len);
		}
		
	}
	boat_len = boat_lenOG;
	boat_len *= 100;

	while (queue_empty(hLeft) != TRUE || queue_empty(hRight) != TRUE)
	{
		boat_len -= (queue_front(hLeft, NULL));
		while (boat_len >= 0 && !queue_empty(hLeft))
		{
			queue_service(hLeft);
			boat_len -= (queue_front(hLeft, NULL));
		}
		counter++;
		boat_len = boat_lenOG * 100;
		if (queue_empty(hLeft) == TRUE && queue_empty(hRight) == TRUE)
		{
			break;
		}
		boat_len -= (queue_front(hRight, NULL));
		while (boat_len >= 0 && !queue_empty(hRight))
		{
			queue_service(hRight);
			boat_len -= (queue_front(hRight, NULL));
		}
		counter++;
		boat_len = boat_lenOG * 100;
	}

	return counter;
}


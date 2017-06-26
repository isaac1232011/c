#ifndef QUEUE_H
#define QUEUE_H
#include "status.h"

typedef void* QUEUE;

QUEUE queue_init_default(void);

//push_back
Status queue_enqueue(QUEUE hQueue, int item);

//Accessor functions
Status queue_service(QUEUE hQueue);
Boolean queue_empty(QUEUE hQueue);

//clear
//set size to zero so that the vector appears to be empty

//
int queue_front(QUEUE hQueue, Status* pStatus);

//remove
void clear_buffer(void);
void queue_destroy(QUEUE* phQueue);

#endif
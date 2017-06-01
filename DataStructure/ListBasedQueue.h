#ifndef __LISTBASED_QUEUE_H__
#define __LiSTBASED_QUEUE_H__

typedef int lbQData;

typedef struct _lbQNode {
	struct _lbQNode * next;
	lbQData data;
}LBQNode;

typedef struct _lbQueue {
	LBQNode * front;
	LBQNode * rear;
} ListBasedQueue;

void InitListBasedQueue(ListBasedQueue * lbQ);
bool IsListBasedQueueEmpty(ListBasedQueue * lbQ);

void EnListBasedQueue(ListBasedQueue * lbQ, lbQData data);
void DeListBasedQueue(ListBasedQueue * lbQ);
lbQData PeekListBasedQueue(ListBasedQueue * lbQ);
#endif
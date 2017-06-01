#include <iostream>
#include "ListBasedQueue.h"

using namespace std;

void InitListBasedQueue(ListBasedQueue * lbQ) {
	lbQ->front = lbQ->rear = NULL;
}
bool IsListBasedQueueEmpty(ListBasedQueue * lbQ) {
	if (lbQ->front == NULL && lbQ->rear == NULL) return true;
	else return false;
}

void EnListBasedQueue(ListBasedQueue * lbQ, lbQData data) {
	LBQNode * newNode = (LBQNode *)malloc(sizeof(LBQNode));
	newNode->data = data;
	newNode->next = NULL;

	if (IsListBasedQueueEmpty(lbQ))
		lbQ->front = newNode;
	else
		lbQ->rear->next = newNode;

	lbQ->rear = newNode;
}
void DeListBasedQueue(ListBasedQueue * lbQ) {
	if (IsListBasedQueueEmpty(lbQ)) {
		cout << "Memory Empty Err!" << endl;
		exit(-1);
	}

	LBQNode * delNode = lbQ->front;
	lbQ->front = delNode->next;
	free(delNode);

	if (lbQ->front == NULL)
		lbQ->rear = NULL;
}
lbQData PeekListBasedQueue(ListBasedQueue * lbQ) {
	if (IsListBasedQueueEmpty(lbQ)) {
		cout << "Memory Empty Err!" << endl;
		exit(-1);
	}

	return lbQ->front->data;
}
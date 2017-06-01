#include <iostream>
#include "Dequeue.h"

using namespace std;

void InitDQueue(DQueue * dQ) {
	dQ->head = dQ->tail = NULL;
}
bool IsDQueueEmpty(DQueue * dQ) {
	if (dQ->head == NULL && dQ->tail == NULL)
		return true;
	else
		return false;
}

// 순서 무조건 암기!!
void AddDQueueFisrt(DQueue * dQ, DeqData data) {
	DeqNode * newNode = (DeqNode *)malloc(sizeof(DeqNode));
	newNode->data = data;

	newNode->next = dQ->head;

	if (IsDQueueEmpty(dQ))
		dQ->tail = newNode;
	else
		dQ->head->prev = newNode;
	newNode->prev = NULL;
	dQ->head = newNode;
}

void AddDQueueLast(DQueue * dQ, DeqData data) {
	DeqNode * newNode = (DeqNode *)malloc(sizeof(DeqNode));
	newNode->data = data;

	newNode->prev = dQ->tail;

	if (IsDQueueEmpty(dQ))
		dQ->head = newNode;
	else
		dQ->tail->next = newNode;

	newNode->next = NULL;
	dQ->tail = newNode;
}

DeqData RemoveDQueueFirst(DQueue * dQ) {
	if (IsDQueueEmpty(dQ)) {
		cout << "Memory Empty Err!" << endl;
		exit(-1);
	}

	DeqNode * delNode = dQ->head;
	DeqData delData = delNode->data;

	dQ->head = delNode->next;
	free(delNode);

	if (dQ->head == NULL)
		dQ->tail = NULL;
	else
		dQ->head->prev = NULL;

	return delData;
}
DeqData RemoveDQueueLast(DQueue * dQ) {
	if (IsDQueueEmpty(dQ)) {
		cout << "Memory Empty Err!" << endl;
		exit(-1);
	}

	DeqNode * delNode = dQ->tail;
	DeqData delData = delNode->data;

	dQ->tail = delNode->prev;
	free(delNode);

	if (dQ->tail == NULL)
		dQ->head = NULL;
	else
		dQ->tail->next = NULL;

	return delData;
}

DeqData GetDQueueFirst(DQueue * dQ) {
	if (IsDQueueEmpty(dQ)) {
		cout << "Memory Empty Err!" << endl;
		exit(-1);
	}

	return dQ->head->data;
}
DeqData GetDQueueLast(DQueue * dQ) {
	if (IsDQueueEmpty(dQ)) {
		cout << "Memory Empty Err!" << endl;
		exit(-1);
	}

	return dQ->tail->data;
}
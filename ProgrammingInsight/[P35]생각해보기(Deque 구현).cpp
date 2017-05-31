/**
p.35 생각해보기
Dequeue(Double Ended Queue) 구현
+ k번째 위치에 삽입[ * 맨 끝에 삽입하는 것 고쳐야 함 * ]
*/
#if 0
#include <iostream>
using namespace std;

typedef int Data;
typedef struct _dNode {
	Data data;
	struct _dNode * prev;
	struct _dNode * next;
} Node;

typedef struct _dQueue {
	Node * head;
	Node * tail;
} DQueue;

void InitDQueue(DQueue * dQueue) {
	dQueue->head = dQueue->tail = NULL;
}

bool IsDQueueEmpty(DQueue * dQueue) {
	if (dQueue->head == NULL && dQueue->tail == NULL) return true;
	else return false;
}

void DQAddFirst(DQueue * dQueue, Data data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->data = data;

	newNode->next = dQueue->head;
	dQueue->head = newNode;

	if (dQueue->tail == NULL) dQueue->tail = newNode;
	else newNode->next->prev = newNode;
}

void DQAddLast(DQueue * dQueue, Data data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	newNode->prev = dQueue->tail;
	dQueue->tail = newNode;

	if (dQueue->head == NULL) dQueue->head = newNode;
	else newNode->prev->next = newNode;
}

void DQRemoveFirst(DQueue * dQueue) {
	if (IsDQueueEmpty(dQueue)) {
		cout << "Queue is empty!! " << endl;
		exit(-1);
	}

	Node * rNode = dQueue->head;
	dQueue->head = rNode->next;
	dQueue->head->prev = NULL;

	free(rNode);
}

void DQRemoveLast(DQueue * dQueue) {
	if (IsDQueueEmpty(dQueue)) {
		cout << "Queue is empty!! " << endl;
		exit(-1);
	}


	Node * rNode = dQueue->tail;
	dQueue->tail = rNode->prev;
	dQueue->tail->next = NULL;

	free(rNode);
}

Data DQGetFirst(DQueue * dQueue) {
	return dQueue->head->data;
}

Data DQGetLast(DQueue * dQueue) {
	return dQueue->tail->data;
}

void PrintDQueue(DQueue * dQueue) {
	Node * cur;
	cur = dQueue->head;
	while (cur != NULL) {
		cout << cur->data << " ";
		cur = cur->next;
	}
}

void InsertKthLocation(DQueue * dQueue, Data data, int k) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	Node * cur = dQueue->head;

	newNode->data = data;
	newNode->next = newNode->prev = NULL;

	for (int i = 1; i <= k; i++) cur = cur->next;
	newNode->prev = cur->prev;
	newNode->next = cur;

	if (newNode->prev != NULL)
		newNode->prev->next = newNode;
	if (newNode->next != NULL)
		newNode->next->prev = newNode;

	if (cur == dQueue->head) dQueue->head = newNode;
	if (cur == dQueue->tail) dQueue->tail = newNode;

}

int main(void) {

	DQueue dQueue;
	InitDQueue(&dQueue);

	DQAddFirst(&dQueue, 11); DQAddFirst(&dQueue, 12);
	DQAddFirst(&dQueue, 13); DQAddFirst(&dQueue, 14);

	DQAddLast(&dQueue, 12); DQAddLast(&dQueue, 13);
	DQAddLast(&dQueue, 14);

	PrintDQueue(&dQueue);
	cout << endl;

	InsertKthLocation(&dQueue, 11, 6);
	PrintDQueue(&dQueue);
	cout << endl;

	DQRemoveFirst(&dQueue); DQRemoveLast(&dQueue);

	PrintDQueue(&dQueue);
	cout << endl;

	cout << DQGetFirst(&dQueue) << " " << DQGetLast(&dQueue) << endl;
}
#endif
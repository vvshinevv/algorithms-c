/**
p.29 Queue (리스트 기반)
*/
#if 0
#include <iostream>
using namespace std;
typedef int Data;

typedef struct _node {
	Data data;
	struct _node * next;
} Node;

typedef struct _queue {
	Node * head;
	Node * tail;
	int queue_size;
} Queue;

void InitQueue(Queue * queue) {
	queue->queue_size = 0;
	queue->head = queue->tail = NULL;
}

bool IsQueueEmpty(Queue * queue) {
	if (queue->queue_size == 0)
		return true;
	else
		return false;
}

void Enqueue(Queue * queue, Data data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (IsQueueEmpty(queue)) {
		queue->head = newNode;
		queue->tail = newNode;
	}
	else {
		queue->tail->next = newNode;
		queue->tail = newNode;
	}

	queue->queue_size++;
}

Data Dequeue(Queue * queue) {
	if (IsQueueEmpty(queue)) {
		cout << "Queue Is Empty!!" << endl;
		return -1;
	}

	Node * rNode = queue->head;
	Data rData = queue->head->data;
	queue->head = queue->head->next;

	if (queue->head == NULL)
		queue->tail = NULL;
	free(rNode);
	queue->queue_size--;
	return rData;
}

int main(void) {
	Queue queue;
	InitQueue(&queue);

	int inputNum;

	do {
		cout << "Input Number: ";
		cin >> inputNum;

		if (inputNum == 0) {
			cout << Dequeue(&queue) << endl;
		}
		else {
			Enqueue(&queue, inputNum);
		}
	} while (inputNum >= 0);

	return 0;
}

#endif

/**
p.29 원형 큐 (배열 기반)
*/
#if 0
#include <iostream>

#define QUE_LEN	8 

using namespace std;
typedef int Data;

typedef struct _cQueue {
	int front;
	int rear;
	Data queArr[QUE_LEN];
} Queue;

void QueueInit(Queue * queue) {
	queue->front = 0;
	queue->rear = 0;
}

bool QIsEmpty(Queue * queue) {
	if (queue->front == queue->rear)
		return true;
	else
		return false;
}

int NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue * queue, Data data) {
	if (NextPosIdx(queue->rear) == queue->front) {
		cout << "Queue Is Full!!" << endl;
		return;
	}
	queue->rear = NextPosIdx(queue->rear);
	queue->queArr[queue->rear] = data;
}

Data Dequeue(Queue * queue) {
	if (QIsEmpty(queue)) {
		cout << "Queue Is Empty!!" << endl;
		return -1;
	}
	queue->front = NextPosIdx(queue->front);
	return queue->queArr[queue->front];
}

Data QPeek(Queue * queue) {
	if (QIsEmpty(queue)) {
		cout << "Queue Is Empty!!" << endl;
		return -1;
	}
	return queue->queArr[NextPosIdx(queue->front)];
}

int main(void) {
	Queue queue;
	QueueInit(&queue);
	Data inputNum;

	do {
		cout << "Input Num: ";
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
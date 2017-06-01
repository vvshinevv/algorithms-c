#if 0
#include <iostream>
#include "CircularQueue.h"

using namespace std;

void InitQueue(Queue * que) {
	que->front = que->rear = 0;
}

int NextPosIdx(int pos) {
	if (pos == LEN_QUE - 1) return 0;
	else return pos + 1;
}

void EnQueue(Queue * que, Data data) {
	if (NextPosIdx(que->rear) == que->front) {
		cout << "Memory Full Error" << endl;
		exit(-1);
	}
	
	que->rear = NextPosIdx(que->rear);
	que->queArr[que->rear] = data;
}

Data DeQueue(Queue * que) {
	if (que->front == que->rear) {
		cout << "Memory Empty Error" << endl;
		exit(-1);
	}

	que->front = NextPosIdx(que->front);
	return que->queArr[que->front];
}

Data PeekQueue(Queue * que) {
	if (que->front == que->rear) {
		cout << "Memory Empty Error" << endl;
		exit(-1);
	}
	return que->queArr[NextPosIdx(que->front)];
}
#endif
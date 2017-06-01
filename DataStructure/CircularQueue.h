#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define LEN_QUE 5
typedef int Data;

typedef struct _cQueue {
	Data queArr[LEN_QUE];
	int front, rear;
} CQueue;

typedef CQueue Queue;

void InitQueue(Queue * que);
void EnQueue(Queue * que, Data data);
Data DeQueue(Queue * que);
Data PeekQueue(Queue * que);

#endif
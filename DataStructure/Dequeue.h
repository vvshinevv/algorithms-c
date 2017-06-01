#ifndef __DE_QUEUE_H__
#define __DE_QUEUE_H__

typedef int DeqData;

typedef struct _deqNode {
	struct _deqNode * prev;
	struct _deqNode * next;
	DeqData data;
} DeqNode;

typedef struct _dQueue {
	DeqNode * head;
	DeqNode * tail;
} DQueue;

void InitDQueue(DQueue * dQ);
bool IsDQueueEmpty(DQueue * dQ);

void AddDQueueFisrt(DQueue * dQ, DeqData data);
void AddDQueueLast(DQueue * dQ, DeqData data);

DeqData RemoveDQueueFirst(DQueue * dQ);
DeqData RemoveDQueueLast(DQueue * dQ);

DeqData GetDQueueFirst(DQueue * dQ);
DeqData GetDQueueLast(DQueue * dQ);

#endif
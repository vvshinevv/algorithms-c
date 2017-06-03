#ifndef __HEAP_H__
#define __HEAP_H__

#define HEAP_LEN 100
typedef char HData;

typedef int PriorityComp(HData d1, HData d2);

typedef struct _hEap {
	PriorityComp * comp;
	int hCnt;
	HData data[HEAP_LEN];
} Heap;

void InitHeap(Heap * h, PriorityComp * comp);
bool IsHeapEmpty(Heap * h);

void InsertHeap(Heap * h, HData data);
HData DeleteHeap(Heap * h);
#endif
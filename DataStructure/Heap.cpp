#include <iostream>
#include "Heap.h"

int GetParentIdx(int idx) {
	return idx / 2;
}

int GetLeftChildIdx(int idx) {
	return idx * 2;
}

int GetRightChildIdx(int idx) {
	return idx * 2 + 1;
}

void InitHeap(Heap * h, PriorityComp * comp) {
	h->hCnt = 0;
	h->comp = comp;
}
bool IsHeapEmpty(Heap * h) {
	if (h->hCnt == 0)
		return true;
	else
		return false;
}

int GetHighPriorityChildIdx(Heap * h, int parentIdx) {
	if (GetLeftChildIdx(parentIdx) > h->hCnt)
		return 0;
	else if (GetLeftChildIdx(parentIdx) == h->hCnt)
		return GetLeftChildIdx(parentIdx);
	else {
		if (h->comp(h->data[GetLeftChildIdx(parentIdx)],
			h->data[GetRightChildIdx(parentIdx)]) > 0)
			return GetLeftChildIdx(parentIdx);
		else
			return GetRightChildIdx(parentIdx);
	}
}

void InsertHeap(Heap * h, HData data) {
	int idx = h->hCnt + 1;

	while (idx != 1) {
		if (h->comp(data, h->data[GetParentIdx(idx)]) > 0) {
			h->data[idx] = h->data[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		} else {
			break;
		}
	}
	h->data[idx] = data;
	h->hCnt++;
}

HData DeleteHeap(Heap * h) {
	HData rData = h->data[1];
	HData tData = h->data[h->hCnt];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHighPriorityChildIdx(h, parentIdx)) {
		if (h->comp(tData, h->data[childIdx]) > 0)
			break;

		h->data[parentIdx] = h->data[childIdx];
		parentIdx = childIdx;
	}

	h->data[parentIdx] = tData;
	h->hCnt--;
	return rData;
}
#if 0
#include <iostream>
#include "Heap.h"
using namespace std;
int Priority(HData d1, HData d2) {
	return d2 - d1;
	// 0���� �۴� : d2�� �켱������ ����.
	// 0���� ũ�� : d1�� �켱������ ����.
}
int main(void) {
	Heap heap;
	InitHeap(&heap, Priority);

	InsertHeap(&heap, 'A');
	InsertHeap(&heap, 'B');
	InsertHeap(&heap, 'C');
	
	cout << DeleteHeap(&heap);

	InsertHeap(&heap, 'A');
	InsertHeap(&heap, 'B');
	InsertHeap(&heap, 'C');

	cout << DeleteHeap(&heap);

	while (!IsHeapEmpty(&heap))
		cout << DeleteHeap(&heap);

	return 0;
}
#endif
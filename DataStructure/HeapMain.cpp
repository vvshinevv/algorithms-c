#if 0
#include <iostream>
#include "Heap.h"
using namespace std;
int Priority(HData d1, HData d2) {
	return d2 - d1;
	// 0보다 작다 : d2의 우선순위가 높다.
	// 0보다 크다 : d1의 우선순위가 높다.
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
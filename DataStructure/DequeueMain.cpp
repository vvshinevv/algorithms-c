#if 0
#include <iostream>
#include "Dequeue.h"
using namespace std;

int main(void) {
	DQueue dQ;
	InitDQueue(&dQ);

	AddDQueueFisrt(&dQ, 1); AddDQueueFisrt(&dQ, 2);
	AddDQueueFisrt(&dQ, 3); AddDQueueFisrt(&dQ, 4);

	AddDQueueLast(&dQ, 1); AddDQueueLast(&dQ, 2);
	AddDQueueLast(&dQ, 3); AddDQueueLast(&dQ, 4);

	cout << GetDQueueFirst(&dQ) << endl;
	cout << GetDQueueLast(&dQ) << endl;

	cout << RemoveDQueueFirst(&dQ) << endl;
	cout << RemoveDQueueLast(&dQ) << endl;

	for (int i = 0; i < 6; i++)
		cout << RemoveDQueueLast(&dQ) << " ";
	cout << endl;

	cout << RemoveDQueueLast(&dQ) << " ";
	return 0;
}

#endif
#if 0
#include <iostream>
#include "ListBasedQueue.h"
using namespace std;
int main(void) {
	ListBasedQueue lbQ;
	InitListBasedQueue(&lbQ);

	EnListBasedQueue(&lbQ, 1); EnListBasedQueue(&lbQ, 2);
	EnListBasedQueue(&lbQ, 3); EnListBasedQueue(&lbQ, 4);

	for (int i = 0; i < 4; i++) {
		cout << PeekListBasedQueue(&lbQ) << " ";
		DeListBasedQueue(&lbQ);
	}
	cout << endl;

	return 0;
}

#endif
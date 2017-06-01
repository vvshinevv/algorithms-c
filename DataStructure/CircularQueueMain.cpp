#if 0
#include <iostream>
#include "CircularQueue.h"

using namespace std;

int main(void) {
	Queue que;
	InitQueue(&que);

	EnQueue(&que, 1); EnQueue(&que, 2);
	EnQueue(&que, 3); EnQueue(&que, 4);

	while (que.front != que.rear)
		cout << DeQueue(&que) << " ";

	cout << endl;

	return 0;
}
#endif

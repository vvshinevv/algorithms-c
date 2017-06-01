#if 0
#include <iostream>
#include "ListBasedStack.h"

using namespace std;

int main(void) {
	ListBasedStack lbS;

	InitListBasedStack(&lbS);

	PushListBasedStack(&lbS, 1); PushListBasedStack(&lbS, 2);
	PushListBasedStack(&lbS, 3); PushListBasedStack(&lbS, 4);

	while (!IsListBasedStackEmpty(&lbS)) {
		cout << PeekListBasedStack(&lbS) << " ";
		PopListBasedStack(&lbS);
	}

	return 0;
}

#endif
#if 0
#include <iostream>
#include "ArrayBasedStack.h"
using namespace std;
int main(void) {
	ArrayBasedStack abS;

	InitArrayBasedStack(&abS);

	PushArrayBasedStack(&abS, 1); PushArrayBasedStack(&abS, 2);
	PushArrayBasedStack(&abS, 3); PushArrayBasedStack(&abS, 4);
	
	
	
	while (!IsEmptyArrayBasedStack(&abS)) {
		cout << PeekArrayBasedStack(&abS) << " ";
		PopArrayBasedStack(&abS);
	}

	cout << endl;

	return 0;
}

#endif
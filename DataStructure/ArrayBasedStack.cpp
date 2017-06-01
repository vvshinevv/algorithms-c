#include <iostream>
#include "ArrayBasedStack.h"

using namespace std;

void InitArrayBasedStack(ArrayBasedStack * abS) {
	abS->top = -1;
}

bool IsEmptyArrayBasedStack(ArrayBasedStack * abS) {
	if (abS->top == -1) 
		return true;
	else 
		return false;
}

void PushArrayBasedStack(ArrayBasedStack * abS, abSData data) {
	if (abS->top == STACK_LEN) {
		cout << "Memory Full Err!" << endl;
		exit(-1);
	}
	abS->data[++(abS->top)] = data;
}

void PopArrayBasedStack(ArrayBasedStack * abS) {
	if (IsEmptyArrayBasedStack(abS)) {
		cout << "Memory Empty Err!" << endl;
		exit(-1);
	}
	(abS->top)--;
}

abSData PeekArrayBasedStack(ArrayBasedStack * abS) {
	return abS->data[abS->top];
}
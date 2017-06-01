#include <iostream>
#include "ListBasedStack.h"
using namespace std;
void InitListBasedStack(ListBasedStack * lbS) {
	lbS->top = NULL;
}
bool IsListBasedStackEmpty(ListBasedStack * lbS) {
	if (lbS->top == NULL) return true;
	else return false;
}

void PushListBasedStack(ListBasedStack * lbS, lbSData data) {
	ListBasedStackNode * newNode = (ListBasedStackNode *)malloc(sizeof(ListBasedStackNode));
	newNode->data = data;

	newNode->next = lbS->top;
	lbS->top = newNode;
}

void PopListBasedStack(ListBasedStack * lbS) {
	if (IsListBasedStackEmpty(lbS)) {
		cout << "Memory Empty Err!" << endl;
		exit(-1);
	}

	ListBasedStackNode * delNode = lbS->top;
	lbS->top = delNode->next;

	free(delNode);
}

lbSData PeekListBasedStack(ListBasedStack * lbS) {
	if (IsListBasedStackEmpty(lbS)) {
		cout << "Memory Empty Err!" << endl;
		exit(-1);
	}

	return lbS->top->data;
}
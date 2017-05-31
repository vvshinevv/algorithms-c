/**
p.36 0.d
연결 리스트를 이용하여 스택 자료구조 구현
*/
#if 0
#include <iostream>
using namespace std;
typedef int Data;
typedef struct _sNode {
	Data  data;
	struct _sNode * next;
} Node;

typedef struct _linkedListStack {
	Node * top;
	int stackCnt;
} Stack;

void InitStack(Stack * stack) {
	stack->top = NULL;
	stack->stackCnt = 0;
}

void PushToStack(Stack * stack, Data data) {
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = stack->top;
	stack->top = newNode;
	stack->stackCnt++;
}

void PopFromStack(Stack * stack) {
	if (stack->top == NULL) {
		cout << "Stack is empty!" << endl;
		exit(-1);
	}

	Node * rNode = stack->top;
	stack->top = rNode->next;

	free(rNode);
	stack->stackCnt--;
}

Data PeekFromStack(Stack * stack) {
	if (stack->top == NULL) {
		cout << "Stack is empty!" << endl;
		exit(-1);
	}

	return stack->top->data;
}

bool IsEmptyStack(Stack * stack) {
	if (stack->top == NULL) return true;
	else return false;
}

int main(void) {
	Stack stack;
	InitStack(&stack);

	PushToStack(&stack, 1); PushToStack(&stack, 2);
	PushToStack(&stack, 3); PushToStack(&stack, 4);
	PushToStack(&stack, 5);

	while (!IsEmptyStack(&stack)) {
		cout << PeekFromStack(&stack) << " ";
		PopFromStack(&stack);
	}

	return 0;
}
#endif
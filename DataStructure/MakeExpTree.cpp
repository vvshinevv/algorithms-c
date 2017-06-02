#include <iostream>
#include <string>
#include <stack>
#include "MakeExpTree.h"

using namespace std;

BTreeNode * MakeExpTree(char exp[]) {
	stack<BTreeNode *> stack;
	int expLen = strlen(exp);
	BTreeNode * pNode;
	for (int i = 0; i < expLen; i++) {
		pNode = MakeBTreeNode();
		if (isdigit(exp[i])) {
			SetData(pNode, exp[i] - '0');
		} else {
			MakeRightSubTree(pNode, stack.top()); stack.pop();
			MakeLeftSubTree(pNode, stack.top()); stack.pop();
			SetData(pNode, exp[i]);
		}
		stack.push(pNode);
	}
	return stack.top();
}

void PrintData(BTData data) {
	if (data >= 0 && data <= 9)
		printf("%d", data);
	else
		printf("%c", data);
}

void ShowPrefixTypeExp(BTreeNode * bt) {
	PreOrderTraverse(bt, PrintData);
}

void ShowPostifxTypeExp(BTreeNode * bt) {
	PostOrderTravese(bt, PrintData);
}

void ShowInfixTypeExp(BTreeNode * bt) {
	InOrderTraverse(bt, PrintData);
}

int EvaluateExpTree(BTreeNode * bt) {
	
	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);

	int op1 = EvaluateExpTree(GetLeftSubTree(bt));
	int op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt)) {
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}
	return 0;
}

#include <iostream>
#include <string>
#include <stack>
#include "InfixToPostfix.h"
using namespace std;

int GetOpPrec(char op) {
	switch(op) {
	case '*': case '/':
		return 5;
	case '+': case '-':
		return 3;
	case '(':
		return 1;
	}
	return -1;
}

int WhoIsPrec(char op1, char op2) {
	if (op1 > op2)
		return 1;
	else if (op1 < op2)
		return -1;
	else
		return 0;
}

void InfixToPostfix(char exp[]) {
	stack<char> stack;
	int expLen = strlen(exp) + 1;
	char * convExp = (char *)malloc(sizeof(char) * expLen);
	memset(convExp, 0, expLen);
	int idx = 0;
	char tok;
	for (int i = 0; i < expLen; i++) {
		tok = exp[i];
		if (isdigit(tok)) {
			convExp[idx++] = tok;
		} else {
			switch (tok) {
			case '(':
				stack.push(tok);
				break;
			case ')':
				while (1) {
					if (stack.top() == '(') {
						stack.pop();
						break;
					}
					convExp[idx++] = stack.top();
					stack.pop();
				}
				break;
			case '*': case '/':
			case '+': case '-':
				while (!stack.empty() && WhoIsPrec(stack.top(), tok) >= 0) {
					convExp[idx++] = stack.top();
					stack.pop();
				}
				stack.push(tok);
				break;
			}
		}
	}
	while (!stack.empty()) {
		convExp[idx++] = stack.top();
		stack.pop();
	}
	strcpy_s(exp, expLen, convExp);
	free(convExp);
}
#include <iostream>
#include <string>
#include <stack>
#include "PostCalculator.h"

using namespace std;

double PostCalculator(char exp[]) {
	stack<double> stack;
	int expLen = strlen(exp);
	char tok;
	for (int i = 0; i < expLen; i++) {
		tok = exp[i];
		if (isdigit(tok)) {
			stack.push((double)(tok - '0'));
		} else {
			double op2 = stack.top(); stack.pop();
			double op1 = stack.top(); stack.pop();

			switch (tok) {
			case '+':
				stack.push(op1 + op2);
				break;
			case '-':
				stack.push(op1 - op2);
				break;
			case '*':
				stack.push(op1 * op2);
				break;
			case '/':
				stack.push(op1 / op2);
				break;
			}
		}	
	}
	return stack.top();
}

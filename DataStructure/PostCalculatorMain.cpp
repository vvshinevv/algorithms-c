#if 0
#include <iostream>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

using namespace std; 
int main(void) {
	char exp[] = "((1-2)+3)/(5-2)";
	InfixToPostfix(exp);
	cout << PostCalculator(exp) << endl;;

	return 0;
}
#endif
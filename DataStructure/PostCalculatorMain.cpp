#if 0
#include <iostream>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

using namespace std; 
int main(void) {
	char exp[] = "((11-2)+3)";
	InfixToPostfix(exp);
	cout << PostCalculator(exp) << endl;;

	return 0;
}
#endif
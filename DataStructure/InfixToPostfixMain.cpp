#if 0
#include <iostream>
#include "InfixToPostfix.h"
using namespace std;
int main(void) {
	char exp[] = "((11-2)+3)*(5-2)";
	InfixToPostfix(exp); // 12-3+52-*
	cout << exp << endl;
	return 0;
}
#endif
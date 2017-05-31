/**
tmp ¾øÀÌ swap
*/
#if 0
#include <iostream>
using namespace std;

int main(void) {
	int x = 10, y = 13;

	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
	cout << x << " " << y;

	return 0;
}

#endif

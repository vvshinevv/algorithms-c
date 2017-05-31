/**
p.43 n! 계산하기(for 문, 재귀)
*/
#if 0
#include <iostream>
using namespace std;

int Factorial1(int n) {
	int mul = 1;
	for (int i = 2; i <= n; i++)
		mul *= i;

	return mul;
}

int Factorial2(int n) {
	if (n == 1) return 1;
	else return n * Factorial2(n - 1);
}

int main(void) {
	int a = 100000;

	//cout << "Factorial1: " << Factorial1(a) << endl;
	cout << "Factorial2: " << Factorial2(a) << endl;
	return 0;
}
#endif
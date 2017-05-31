/**
* [2xn ≈∏¿œ∏µ]https://www.acmicpc.net/problem/11726
*/
#if 0
#include <iostream>

using namespace std;

int main(void) {

	int result[1001] = { 0, };
	int num;

	cin >> num;
	result[1] = 1;
	result[2] = 2;

	for (int i = 3; i <= num; i++) {
		result[i] = (result[i - 1] + result[i - 2]) % 10007;
	}
	cout << result[num];
	return 0;
}

#endif
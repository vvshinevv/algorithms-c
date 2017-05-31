/**
* [2xn ≈∏¿œ∏µ2]https://www.acmicpc.net/problem/11727
*/
#if 0
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num;
	vector<long long> numArr(1001, 0);
	cin >> num;

	numArr[1] = 1;
	numArr[2] = 3;

	for (int i = 3; i <= num; i++)
		numArr[i] = (2 * numArr[i - 2] + numArr[i - 1]);

	cout << numArr[num];

	return 0;
}
#endif
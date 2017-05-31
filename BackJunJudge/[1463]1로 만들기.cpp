/**
* [1로 만들기]https://www.acmicpc.net/problem/1463
*/
#if 0
#include <iostream>

using namespace std;

int main(void) {
	int num;
	cin >> num;
	int * numArr = new int[num + 1];

	for (int i = 0; i <= num; i++)
		numArr[i] = 0;

	for (int i = 2; i <= num; i++) {
		if ((i % 2 == 0) && (i % 3 == 0)) {
			numArr[i] = numArr[i / 2] > numArr[i / 3] ? (numArr[i / 3] > numArr[i - 1] ? numArr[i - 1] : numArr[i / 3]) : (numArr[i / 2] > numArr[i - 1] ? numArr[i - 1] : numArr[i / 2]);
			numArr[i] += 1;
		}
		else if (i % 2 == 0) {
			numArr[i] = numArr[i / 2] > numArr[i - 1] ? numArr[i - 1] : numArr[i / 2];
			numArr[i] += 1;
		}
		else if (i % 3 == 0) {
			numArr[i] = numArr[i / 3] > numArr[i - 1] ? numArr[i - 1] : numArr[i / 3];
			numArr[i] += 1;
		}
		else {
			numArr[i] = numArr[i - 1] + 1;
		}
	}
	cout << numArr[num] << endl;
	return 0;
}
#endif

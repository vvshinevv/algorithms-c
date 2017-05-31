/**
* [Èü Á¤·Ä]https://www.acmicpc.net/problem/2220
*/
#if 0
#include <iostream>
#include <vector>

using namespace std;

void SwapArr(vector<int>& vecArr, int n1, int n2) {
	int tmp = vecArr[n1];
	vecArr[n1] = vecArr[n2];
	vecArr[n2] = tmp;
}

int main(void) {
	int num;
	cin >> num;

	vector<int> vecArr(num + 1, 0);
	vecArr[1] = 1;

	for (int i = 2; i <= num; i++) {
		vecArr[i] = i; int j = i - 1;
		SwapArr(vecArr, i, i - 1);
		while (j != 1) {
			SwapArr(vecArr, j, j / 2);
			j = j / 2;
		}
	}

	for (int i = 1; i <= num; i++)
		cout << vecArr[i] << " ";

	return 0;
}

#endif
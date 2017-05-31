/**
* [쉬운 계단 수] https://www.acmicpc.net/problem/10844
*/
#if 0
#include <iostream>
#define val 1000000000
using namespace std;
int tab[101][10];

void InitOneJari() {
	for (int i = 1; i < 10; i++)
		tab[1][i] = 1;
}

int CalculateResult(int jarisu) {
	int result = 0;
	for (int i = 0; i < 10; i++) {
		result = (result + tab[jarisu][i]) % val;
	}
	return result;
}

void Processing(int jarisu) {
	for (int i = 2; i <= jarisu; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				tab[i][j] = (tab[i][j] + tab[i - 1][1]) % val;
			}
			else if (j == 9) {
				tab[i][j] = (tab[i][j] + tab[i - 1][8]) % val;
			}
			else {
				tab[i][j] = (tab[i - 1][j - 1] + tab[i - 1][j + 1]) % val;
			}
		}
	}
}

int main(void) {
	int jarisu;
	cin >> jarisu;
	InitOneJari();
	Processing(jarisu);
	cout << CalculateResult(jarisu);
	return 0;
}

#endif
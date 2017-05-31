/**
* [ºØ¾î»§ ÆÇ¸ÅÇÏ±â]https://www.acmicpc.net/problem/11052
*/
#if 0
#include <iostream>

using namespace std;

int pi[1001];
int pn[1001];

int main(void) {
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> pn[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i <= j) {
				if (pi[j] > (pi[j - i] + pn[i])) {
					pi[j] = pi[j];
				}
				else {
					pi[j] = pi[j - i] + pn[i];
				}
			}
		}
	}
	cout << pi[N];
	return 0;
}
#endif
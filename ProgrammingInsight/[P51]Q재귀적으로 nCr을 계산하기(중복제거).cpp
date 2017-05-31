/**
p.51 재귀적 이항계수 계산하기
중복 없애기!!
*/
#if 0
#include <iostream>
#define MAX 200
using namespace std;
int cnt1, cnt2;

long long BinomialCoefficient2(long long n, long long r) {
	cnt2++;
	static long long memo[MAX][MAX];
	if (memo[n][r] > 0) return memo[n][r];
	if (r == 0 || r == n) return memo[n][r] = 1;
	return memo[n][r] = BinomialCoefficient2(n - 1, r - 1) + BinomialCoefficient2(n - 1, r);
}
int main(void) {
	long long n, r;

	do {
		cout << "input n, r: ";
		cin >> n >> r;
		BinomialCoefficient1(n, r); BinomialCoefficient2(n, r);
		cout << "cnt1: " << cnt1 << endl;
		cout << "cnt2: " << cnt2 << endl;
	} while (n < r);

	return 0;
}
#endif
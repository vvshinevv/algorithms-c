/**
p.49 재귀적으로 이항계수 계산하기
nCr = n-1Cr-1 + n-1Cr;
*/
#if 0
#include <iostream>
#define MAX 200
using namespace std;
int cnt1, cnt2;

long long BinomialCoefficient1(long long n, long long r) {
	cnt1++;
	if (r == 0 || r == n) return 1;
	return BinomialCoefficient1(n - 1, r - 1) + BinomialCoefficient1(n - 1, r);
}
int main(void) {
	long long n, r;

	do {
		cout << "input n, r: ";
		cin >> n >> r;
		BinomialCoefficient1(n, r); BinomialCoefficient1(n, r);
		cout << "cnt1: " << cnt1 << endl;
		cout << "cnt2: " << cnt2 << endl;
	} while (n < r);

	return 0;
}
#endif
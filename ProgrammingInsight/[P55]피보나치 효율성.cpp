#if 0
#include <iostream>
#define MAX 100
using namespace std;

long long memo[MAX];

// 변수 2개 이용
long long Fibo1(int n) {
	long long update, save;
	
	if (n == 1 || n == 2) return 1;
	save = update = 1;
	for (int i = 3; i <= n; i++) {
		update += save;
		save = update - save;
	}
	return update;
}

// 배열 이용
long long Fibo2(int n) {
	
	if (n == 1 || n == 2) return 1;
	
	memo[1] = memo[2] = 1;
	for (int i = 3; i <= n; i++) 
		memo[i] = memo[i - 1] + memo[i - 2];
	
	return memo[n];
}

// 가장 비효율적
long long Fibo3(int n) {
	if (n == 1 || n==2) return 1;
	else return Fibo3(n - 1) + Fibo3(n - 2);
}

// 재귀 함수 개선
long long Fibo4(int n) {
	if (memo[n] > 0) return memo[n];
	if (n == 1 || n == 2) return memo[n] = 1;
	else return memo[n] = Fibo4(n - 1) + Fibo4(n - 2);
}

int main(void) {
	cout << Fibo1(5);
	return 0;
}
#endif
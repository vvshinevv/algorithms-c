/**
p.53 풀이가 있는 생각해보기
0과 1로 이루어진 문자열이 있다. 이 문자열에는 1이 연속하여 나올 수는 있지만
0이 연속해서 나올 수는 없다.
길이가 n인 올바른 문자열은 몇 개일까?
풀이 방법 : 재귀 & memozation & 동적
*/
#if 0
#include <iostream>
#define MAX 100
using namespace std;
static int memo1[MAX][2];
static int memo2[MAX];
int Solution1(int n) {
	if (n == 0) return 0;
	memo1[1][0] = memo1[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		memo1[i][0] = memo1[i - 1][1];
		memo1[i][1] = memo1[i - 1][0] + memo1[i - 1][1];
	}

	return memo1[n][0] + memo1[n][1];
}

int Solution2(int n) {
	if (memo2[n] > 0) return memo2[n];

	if (n == 0) return memo2[0] = 0;
	if (n == 1) return memo2[1] = 2;
	if (n == 2) return memo2[2] = 3;

	return memo2[n] = Solution2(n - 1) + Solution2(n - 2);
}

int Solution3(int n) {
	if (n == 0) return 0;
	if (n == 1) return 2;
	if (n == 2) return 3;

	return Solution2(n - 1) + Solution2(n - 2);
}

int main(void) {
	cout << Solution2(38);
	return 0;
}
#endif
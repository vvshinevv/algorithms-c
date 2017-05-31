/**
p.36 0.c
10진수를 2진수로 변환
*/
#if 0
#include <iostream>

using namespace std;

int ReturnOneCnt(int n) {
	int cnt = 0;

	while (n > 0) {
		if (n % 2 == 1) cnt++;
		n /= 2;
	}
	return cnt;
}

int main(void) {
	cout << ReturnOneCnt(1000) << endl;
	return 0;
}

#endif
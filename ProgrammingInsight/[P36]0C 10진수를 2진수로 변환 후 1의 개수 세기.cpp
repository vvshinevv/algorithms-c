/**
p.36 0.c
10������ 2������ ��ȯ
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
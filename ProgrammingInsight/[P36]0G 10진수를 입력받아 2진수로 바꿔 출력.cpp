/**
p.36 0.g
10���� ������ �Է¹޾Ƽ� �������� �ٲپ� ���
*/
#if 0
#include <iostream>
#define MAX 10
using namespace std;
int cnt;
int arr[MAX];
void decimalToBinary(int n) {
	for (cnt = 0; n > 0; n /= 2, cnt++) {
		arr[cnt] = n % 2;
	}
}

int main(void) {
	decimalToBinary(1000);
	for (int i = cnt - 1; i >= 0; i--)
		cout << arr[i];
	return 0;
}
#endif
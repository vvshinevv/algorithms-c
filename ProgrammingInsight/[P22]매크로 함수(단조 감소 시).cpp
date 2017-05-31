/**
단조감소 & 매크로 함수 max구할 때 시간이 오래걸림
(2^n) - 1개 만큼 함수가 재귀됨...
*/
#if 0
#include <iostream>
#define max(x, y) ((x > y) ? x : y)

using namespace std;

int max_arr2(int arr[], int arr_len) {
	cout << arr_len << endl;

	if (arr_len == 1)
		return arr[0];
	else
		return max(arr[arr_len - 1], max_arr2(arr, arr_len - 1));
}

int main(void) {

	int a[4];
	for (int i = 0; i < 4; i++)
		a[i] = 4 - i;

	cout << max_arr2(a, 4);


	return 0;
}
#endif

/**
�������� & ��ũ�� �Լ� max���� �� �ð��� �����ɸ�
(2^n) - 1�� ��ŭ �Լ��� ��͵�...
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

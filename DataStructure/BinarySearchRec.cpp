/*
* 이진탐색 재귀적으로 구현하기
* 대신 함수는 정렬되어있어야한다.
*/
#if 0
#include <iostream>
using namespace std;
int BSearchRecur(int arr[], int first, int last, int target) {
	if (first > last)
		return -1;

	int mid = (first + last) / 2;

	if (arr[mid] == target)
		return mid;
	else if (arr[mid] > target)
		return BSearchRecur(arr, first, mid -1, target);
	else
		return BSearchRecur(arr, mid+1, last, target);
}

int main(void) {
	int arr[] = { 1, 3, 3, 7 ,9 };
	int target = 7;
	int idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, target);

	if (idx == -1) cout << "배열에 값이 없습니다." << endl;
	else cout << target << "이 " << idx + 1 << "번째 인덱스에 있습니다." << endl;

	return 0;
}

#endif
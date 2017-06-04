#if 0
#include <iostream>
using namespace std;

int BinarySearchRep(int arr[], int s, int r, int k) {
	while (s <= r) {
		int mid = (s + r) / 2;
		if (arr[mid] == k)
			return mid;
		else {
			if (arr[mid] < k)
				s = mid + 1;
			else
				r = mid - 1;
		}
	}
	return -1;
}

int main(void) {
	int arr[] = { 1, 3, 3, 7 ,9 };
	int target = 7;
	int idx = BinarySearchRep(arr, 0, sizeof(arr) / sizeof(int) - 1, target);

	if (idx == -1) cout << "배열에 값이 없습니다." << endl;
	else cout << target << "이 " << idx + 1 << "번째 인덱스에 있습니다." << endl;
	return 0;
}

#endif
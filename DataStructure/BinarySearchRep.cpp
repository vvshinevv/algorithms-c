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

	if (idx == -1) cout << "�迭�� ���� �����ϴ�." << endl;
	else cout << target << "�� " << idx + 1 << "��° �ε����� �ֽ��ϴ�." << endl;
	return 0;
}

#endif
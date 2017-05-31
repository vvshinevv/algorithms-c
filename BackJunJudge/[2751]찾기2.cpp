/**
* [Ã£±â2]https://www.acmicpc.net/problem/2751
* MergeSort
*/
#if 0
#include <iostream>

using namespace std;

void MergeArray(int arr[], int left, int mid, int right) {
	int leftIdx = left, midIdx = mid + 1;

	int len = right + 1;

	int * tmpArr = (int *)malloc(sizeof(int) * len);
	int tmpIdx = left;

	while (leftIdx <= mid && midIdx <= right) {
		if (arr[leftIdx] < arr[midIdx]) {
			tmpArr[tmpIdx] = arr[leftIdx++];
		}
		else {
			tmpArr[tmpIdx] = arr[midIdx++];
		}
		tmpIdx++;
	}

	if (leftIdx > mid) {
		for (int i = midIdx; i <= right; i++, tmpIdx++)
			tmpArr[tmpIdx] = arr[i];
	}
	else {
		for (int i = leftIdx; i <= mid; i++, tmpIdx++)
			tmpArr[tmpIdx] = arr[i];
	}

	for (int i = left; i <= right; i++) {
		arr[i] = tmpArr[i];
	}

	free(tmpArr);
}

void MergeSort(int arr[], int left, int right) {

	if (left < right) {
		int mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeArray(arr, left, mid, right);
	}
}

int main(void) {
	int num;
	cin >> num;
	int * arr = new int[num];

	for (int i = 0; i < num; i++)
		cin >> arr[i];

	MergeSort(arr, 0, num - 1);
	for (int i = 0; i < num; i++)
		cout << arr[i] << "\n";


	return 0;
}

#endif
/**
* [Ä«µå]https://www.acmicpc.net/problem/11652
*/
#if 0
#include <iostream>

using namespace std;

void MergeTwoArea(long long arr[], int left, int mid, int right) {
	int leftIdx = left, midIdx = mid + 1;
	int len = right + 1;
	long long * tmpArr = (long long *)malloc(sizeof(long long)*len);
	int tmpIdx = left;

	while (leftIdx <= mid && midIdx <= right) {
		if (arr[leftIdx] <= arr[midIdx])
			tmpArr[tmpIdx] = arr[leftIdx++];
		else
			tmpArr[tmpIdx] = arr[midIdx++];

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

	for (int i = left; i <= right; i++)
		arr[i] = tmpArr[i];

	free(tmpArr);
}

void MergeSort(long long arr[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}

long long CountMax(long long arr[], int len) {
	int i = 0, count = 0; long long result; int tmpCount = 1;
	while (i < len) {
		if (arr[i] == arr[i + 1]) {
			tmpCount++;
		}
		else {
			if (count < tmpCount) {
				count = tmpCount;
				result = arr[i];
			}
			tmpCount = 1;
		}

		i++;
	}
	return result;
}

int main(void) {
	int num;
	cin >> num;

	long long * numArr = new long long[num];
	for (int i = 0; i < num; i++)
		cin >> numArr[i];

	MergeSort(numArr, 0, num - 1);

	cout << CountMax(numArr, num);

	delete(numArr);
}
#endif
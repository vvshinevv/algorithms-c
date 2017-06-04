#if 0
#include <iostream>
using namespace std;

void MergeTwoArr(int arr[], int left, int mid, int right) {
	int fIdx = left;
	int rIdx = mid + 1;
	int sIdx = left;

	int * sortArr = (int *)malloc(sizeof(int) * (right + 1));

	while ((fIdx <= mid) && (rIdx <= right)) {
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if (fIdx > mid) {
		while(rIdx <= right)
			sortArr[sIdx++] = arr[rIdx++];
	} else {
		while(fIdx <= mid)
			sortArr[sIdx++] = arr[fIdx++];
	}

	for (int i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArr(arr, left, mid, right);
	}
}

int main(void) {
	int arr[7] = { 3, 3, 4, 1, 7, 6, 5 };

	MergeSort(arr, 0, 6);

	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";

	cout << endl;
	return 0;
}
#endif
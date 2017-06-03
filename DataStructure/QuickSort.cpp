#if 0
#include <iostream>
using namespace std;

int Partition(int arr[], int left, int right) {
	int pivot = left;
	int low = pivot + 1;
	int high = right;

	while (low <= high) {
		while ((arr[pivot] >= arr[low]) && (low <= right))
			low++;

		while ((arr[pivot] <= arr[high]) && (high >= left+1))
			high--;

		if(low <= high)
			swap(arr[low], arr[high]);
	}

	swap(arr[pivot], arr[high]);
	
	return high;
}

void QuickSort(int arr[], int left, int right) {
	if (left <= right) {
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
	
}

int main(void) {
	int arr[] = { 3, 3, 4, 1, 7, 6, 5 };
	QuickSort(arr, 0, 6);

	for (int i = 0; i < 6; i++)
		cout << arr[i];
	return 0;
}
#endif
#if 0
#include <iostream>
using namespace std;

void BubbleSort(int arr[], int arrLen) {
	for (int i = 0; i < arrLen - 1; i++)
		for (int j = 0; j < (arrLen - i) - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

void SelectionSort(int arr[], int arrLen) {
	for (int i = 0; i < arrLen - 1; i++) {
		int minIdx = i;
		for (int j = i + 1; j < arrLen; j++) {
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}
		swap(arr[i], arr[minIdx]);
	}
}

void InsertSort(int arr[], int arrLen) {
	int j, insData;
	for (int i = 1; i < arrLen; i++) {
		insData = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = insData;
	}
}

int main(void) {
	int arr[] = { 3, 2, 3, 7, 6, 3 };
	SelectionSort(arr, 6);
	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	return 0;
}

#endif
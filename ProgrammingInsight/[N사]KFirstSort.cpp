#if 1
#include <iostream>
#include <queue>
using namespace std;

typedef struct _cOmp {
	bool operator() (int a, int b) {
		return a > b;
	}
} Comp;

void KFirstSort(int * arr, int k, int arrLen) {

	priority_queue<int, vector<int>, Comp> setL;
	int * sortLen = (int *)malloc(sizeof(int)*(arrLen + 1));

	for (int i = 0; i < arrLen; i++) {
		if (arr[i] == k)
			sortLen[0] = k;
		else
			setL.push(arr[i]);
	}

	for (int i = 1; i < arrLen; i++) {
		sortLen[i] = setL.top();
		setL.pop();
	}
	
	for (int i = 0; i < arrLen; i++) {
		arr[i] = sortLen[i];
	}
	free(sortLen);
}

int main(void) {
	int arr[] = { 3, 4, 5, 1, 2 };
	int arrLen = sizeof(arr) / sizeof(arr[0]);

	KFirstSort(arr, 4, arrLen);

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
#endif
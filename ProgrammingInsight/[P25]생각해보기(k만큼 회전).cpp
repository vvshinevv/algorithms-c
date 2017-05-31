/**
p.25 생각해보기(인터넷)
*/
#if 0
#include <stdio.h>

const int MAX_ELEM = 10;

void rotate(int *array, int s, int t, int k)
{
	int range = (t - s + 1);
	int idx = s, cycle = s;
	int insert, save;

	if (k % range == 0) return;
	if (k > range) k %= range;

	insert = save = array[s];

	for (int i = 0; i < range; i++)
	{
		insert = save;

		int nextIdx = idx + k;

		// invalid range check
		if (nextIdx > t) {
			nextIdx = (nextIdx % (t + 1)) + s;
		}

		save = array[nextIdx];
		array[nextIdx] = insert;

		idx = nextIdx;

		// avoid cycle
		if (idx == cycle) {
			idx++; cycle++;
			save = array[idx];
		}
	}
}

int main()
{
	int array[MAX_ELEM];

	// make test set
	for (int i = 1; i <= MAX_ELEM; i++) {
		array[i - 1] = i;
	}

	rotate(array, 0, 7, 3);

	// print result
	for (int i = 0; i < MAX_ELEM; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}
#endif

/**
p.25 생각해보기(내가 푼 것)
*/
#if 0
#include <iostream>
using namespace std;

void RoatateByK(int arr[], int s, int t, int k) {
	int range = t - s + 1;
	int idx, cycle;
	int save, insert;

	if (k >= range) k %= range;
	if (k == 0) return;

	idx = cycle = s;
	insert = arr[idx];
	for (int i = 0; i < range; i++) {
		idx += k;
		if (idx > t) idx = idx % (t + 1) + s;
		save = arr[idx];
		arr[idx] = insert;
		insert = save;

		if (idx == cycle) {
			idx++; cycle++;
			insert = arr[idx];
		}
	}
}


int main(void) {
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	RoatateByK(arr, 0, 3, 2);

	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
#endif
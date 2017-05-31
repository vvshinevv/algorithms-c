/**
* [K번째 수]https://www.acmicpc.net/problem/11004
*/
#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Swap(vector<long long> & vec, int idx1, int idx2) {
	long long temp = vec[idx1];
	vec[idx1] = vec[idx2];
	vec[idx2] = temp;
}

int Partition(vector<long long> & vec, int left, int right) {
	long long pivot = vec[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (pivot > vec[low] && low <= right)
			low++;
		while (pivot < vec[high] && high >= (left + 1))
			high--;

		if (low <= high)
			Swap(vec, low, high);
	}
	Swap(vec, left, high);
	return high;
}
void QuickSort(vector<long long> & vec, int left, int right) {
	if (left <= right) {
		int pivot = Partition(vec, left, right);
		QuickSort(vec, left, pivot - 1);
		QuickSort(vec, pivot + 1, right);
	}
}

int main(void) {

	int num, k;
	cin >> num >> k;
	vector<long long> vec(num);

	for (int i = 0; i < num; i++)
		cin >> vec[i];

	QuickSort(vec, 0, num - 1);
	cout << vec[k - 1];

	return 0;
}
#endif

/**
* [k 번째 수]https://www.acmicpc.net/problem/11004
*/
#if 0
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int N, K;
	scanf_s("%d%d", &N, &K);
	vector<long long int> vecArr(N, 0);

	for (int i = 0; i < N; i++) {
		long long int in; scanf_s("%lld", &in);
		vecArr[i] = in;
	}
	//sort(vecArr.begin(), vecArr.end());
	nth_element(vecArr.begin(), vecArr.begin() + (K - 1), vecArr.end());
	printf("%lld", vecArr[K - 1]);

	return 0;
}
#endif 
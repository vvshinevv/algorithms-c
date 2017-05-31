/**
p.25 풀이가 있는 생각해보기
*/
#if 0
#include <iostream>
using namespace std;

void left_rotate(int arr[], int s, int t) {
	int fir = arr[s];
	for (int i = s + 1; i <= t; i++)
		arr[i - 1] = arr[i];
	arr[t] = fir;
}

void right_rotate(int arr[], int s, int t) {
	int i, last;
	last = arr[t];
	for (int i = t; i > s; i--)
		arr[i] = arr[i - 1];
	arr[s] = last;
}

int main(void) {
	int arr[] = { 1,2,3,4,5 };
	left_rotate(arr, 2, 4);
	right_rotate(arr, 2, 4);
	for (int i = 0; i < 5; i++)
		cout << arr[i];
	return 0;
}
#endif
/**
*[ATM]https://www.acmicpc.net/problem/11399
*/

#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int in; int sum = 0;
	cin >> in;
	vector<int> vec(in, 0);
	for (int i = 0; i < in; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < in; i++) {
		for (int j = 0; j <= i; j++) {
			sum += vec[j];
		}
	}

	cout << sum;
	return 0;
}
#endif
/*
* ����Ž�� ��������� �����ϱ�
* ��� �Լ��� ���ĵǾ��־���Ѵ�.
*/
#if 0
#include <iostream>
using namespace std;
int BSearchRecur(int arr[], int first, int last, int target) {
	
	if (first > last) return -1;

	int mid = (first + last) / 2;
	if (arr[mid] == target)
		return mid;
	else if (target < arr[mid])
		return BSearchRecur(arr, first, mid - 1, target); // target�� �� �����ϱ� ���� �ʿ��� ã�ƾ���!
	else
		return BSearchRecur(arr, mid + 1, last, target);
}

int main(void) {
	int arr[] = { 1, 3, 5, 7 ,9 };
	int target = 7;
	int idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, target);

	if (idx == -1) cout << "�迭�� ���� �����ϴ�." << endl;
	else cout << target << "�� " << idx << "��° �ε����� �ֽ��ϴ�." << endl;

	return 0;
}

#endif
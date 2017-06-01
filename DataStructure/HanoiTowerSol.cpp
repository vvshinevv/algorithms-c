#if 0
/**
* ��� A���� N���� ������ ��� B�� �̿��Ͽ� ��� C�� �ű�� �˰���
* 1. ��� A���� N-1���� ������ ��� C�� �̿��Ͽ� ��� B�� �ű��.
* 2. ��� A���� 1���� ������ ��� C�� �ű��.
* 3. ��� B���� N-1���� ������ ��� A�� �̿��ؼ� ��� C�� �ű��.
*/
#include <iostream>
using namespace std;
static int cnt;
void HanoiTowerSol(int n, char from, char by, char to) {
	cnt++;
	if (n > 1) {
		HanoiTowerSol(n - 1, from, to, by);
		cout << from << "���� " << to << "�� �̵�" << endl;
		HanoiTowerSol(n - 1, by, from, to);
	}
	else {
		cout << from << "���� " << to << "�� �̵�" << endl;
	}
}

int main(void) {
	HanoiTowerSol(6, 'A', 'B', 'C');
	cout << cnt << "��" << endl;
	return 0;
}
#endif
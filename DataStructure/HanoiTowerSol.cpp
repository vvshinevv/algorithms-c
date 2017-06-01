#if 0
/**
* 기둥 A에서 N개의 원반을 기둥 B를 이용하여 기둥 C로 옮기는 알고리즘
* 1. 기둥 A에서 N-1개의 원반을 기둥 C를 이용하여 기둥 B로 옮긴다.
* 2. 기둥 A에서 1개의 원반을 기둥 C로 옮긴다.
* 3. 기둥 B에서 N-1개의 원반을 기둥 A를 이용해서 기둥 C로 옮긴다.
*/
#include <iostream>
using namespace std;
static int cnt;
void HanoiTowerSol(int n, char from, char by, char to) {
	cnt++;
	if (n > 1) {
		HanoiTowerSol(n - 1, from, to, by);
		cout << from << "에서 " << to << "로 이동" << endl;
		HanoiTowerSol(n - 1, by, from, to);
	}
	else {
		cout << from << "에서 " << to << "로 이동" << endl;
	}
}

int main(void) {
	HanoiTowerSol(6, 'A', 'B', 'C');
	cout << cnt << "개" << endl;
	return 0;
}
#endif
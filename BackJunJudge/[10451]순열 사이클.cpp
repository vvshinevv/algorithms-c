/**
* [순열 사이클]https://www.acmicpc.net/problem/10451
*/
#if 0
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		int cnt; int cycleCnt = 0;
		cin >> cnt;

		vector<int> vec(cnt + 1, 0);
		bool * visitArr = (bool *)malloc(sizeof(bool)*(cnt + 1));

		for (int j = 1; j < cnt + 1; j++) {
			cin >> vec[j];
			visitArr[j] = false;
		}

		for (int j = 1; j < cnt + 1; j++) {

			if (visitArr[j] != true) {
				int visit = j;
				while (1) {
					visitArr[visit] = true;
					if (j == vec[visit]) {
						cycleCnt++;
						break;
					}
					else {
						visit = vec[visit];
					}
				}
			}
		}
		cout << cycleCnt << endl;
		free(visitArr);
	}


	return 0;
}
#endif

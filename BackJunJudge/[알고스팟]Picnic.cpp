/**
* [¼ÒÇ³]https://algospot.com/judge/problem/read/PICNIC
*/
#if 0
#include <iostream>
#include <stack>

using namespace std;

typedef struct _sZZac {
	int left, right;
	bool check;
} ZZac;

void ZArrInit(ZZac * zArr, int cnt) {
	for (int i = 0; i < cnt; i++)
		zArr[i].check = true;
}

int main(void) {
	int sCnt, inCnt, res = 0;
	cin >> sCnt >> inCnt;
	stack<int> stack;

	ZZac * zArr = (ZZac *)malloc(sizeof(ZZac) * inCnt);

	for (int i = 0; i < inCnt; i++) {
		int in1, in2;
		cin >> in1 >> in2;

		zArr[i].left = in1;
		zArr[i].right = in2;
		zArr[i].check = true;
	}
	for (int k = 0; k < inCnt; k++) {
		for (int i = k; ; ) {
			if (zArr[i].check == true) {
				stack.push(zArr[i].left);
				stack.push(zArr[i].right);
				if (stack.size() == sCnt) {
					res++; break;
				}
				for (int j = 0; j < inCnt; j++) {
					if (i != j && zArr[j].check == true) {
						if (zArr[i].left == zArr[j].left ||
							zArr[i].left == zArr[j].right ||
							zArr[i].right == zArr[j].left ||
							zArr[i].right == zArr[j].right) {
							zArr[j].check = false;
						}
					}
				}
			}
			i = (i + 1) % inCnt;
			if (i == k)
				break;
		}
		ZArrInit(zArr, inCnt);
		while (!stack.empty()) stack.pop();
	}

	cout << res << endl;

	free(zArr);
	return 0;
}
#endif
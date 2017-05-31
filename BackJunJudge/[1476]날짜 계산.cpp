/**
*[날짜계산]https://www.acmicpc.net/problem/1476
*/

#if 0
#include <iostream>
using namespace std;
int main(void) {
	int E, S, M;
	int tE = 1, tS = 1, tM = 1, ans = 1;
	cin >> E >> S >> M;

	while (1) {
		if ((tE == E) && (tS == S) && (tM == M))
			break;

		tE++; tS++; tM++; ans++;
		if (tE == 16) tE = 1;
		if (tS == 29) tS = 1;
		if (tM == 20) tM = 1;
	}
	cout << ans;
	return 0;
}

#endif
/**
* [³× ¼ö]https://www.acmicpc.net/problem/10824
*/
#if 0
#include <iostream>
using namespace std;
int main(void) {
	long long a, b, c, d, tmp;
	cin >> a >> b >> c >> d;
	tmp = b;
	do {
		a *= 10;
	} while (tmp /= 10);
	tmp = d;
	do {
		c *= 10;
	} while (tmp /= 10);
	cout << a + b + c + d;
	return 0;
}
#endif

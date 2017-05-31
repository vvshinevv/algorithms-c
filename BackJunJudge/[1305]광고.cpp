/**
* [±¤°í]https://www.acmicpc.net/problem/1305
*/
#if 0

#include <iostream>
#include <string>

using namespace std;

int * getPi(string p) {
	int * pi = new int[(int)p.size()];
	pi[0] = 0; int j = 0;
	for (int i = 1; i < (int)p.size(); i++) {
		while (p[i] != p[j]) {
			if (j == 0) {
				pi[i] = j;
				break;
			}
			j = pi[j - 1];
		}
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

int main(void) {
	int in;
	cin >> in;

	string p;
	cin >> p;


	int * pi = getPi(p);

	cout << in - pi[in - 1] << endl;

	delete(pi);
	return 0;
}
#endif 

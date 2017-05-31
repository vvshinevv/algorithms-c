/**
* [찾기]https://www.acmicpc.net/problem/1786
* queue version
*/
#if 0

#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int * getPi(string p) {
	int * pi = new int[(int)p.size()];
	int j = 0;
	memset(pi, 0, (int)p.size() * sizeof(int));
	for (int i = 1; i < (int)p.size(); i++) {
		while (p[i] != p[j]) {
			if (j == 0) {
				break;
			}
			j = pi[j - 1];
		}
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

queue<int> kmp(string t, string p, int * pi) {
	queue<int> que;
	int j = 0, len_p = (int)p.size(), len_t = (int)t.size();
	for (int i = 0; i < len_t; i++) {
		while (t[i] != p[j]) {
			if (j == 0)
				break;
			j = pi[j - 1];
		}
		if (t[i] == p[j]) {
			if (j == len_p - 1) {
				que.push(i - len_p + 2);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return que;
}

int main(void) {

	string text;
	string pattern;
	queue<int> que;

	getline(cin, text); // 공백 포함 문자열 입력
	cin >> pattern;

	int * pi = getPi(pattern);
	que = kmp(text, pattern, pi);

	cout << (int)que.size() << endl;
	while (!que.empty()) {
		cout << que.front() << endl;
		que.pop();
	}
	delete(pi);
	return 0;
}
#endif

/**
* [찾기]https://www.acmicpc.net/problem/1786
* vector version
*/
#if 0
/**
* https://www.acmicpc.net/problem/1786
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int * getPi(string p) {
	int len_p = (int)p.size();
	int * pi = new int[len_p];
	pi[0] = 0;
	int j = 0;
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

vector<int> kmp(string t, string p, int * pi) {
	vector<int> v;
	int j = 0, len_p = (int)p.size(), len_t = (int)t.size();
	for (int i = 0; i < len_t; i++) {
		while (t[i] != p[j]) {
			if (j == 0)
				break;
			j = pi[j - 1];
		}
		if (t[i] == p[j]) {
			j++;
			if (j == len_p) {
				v.push_back(i - len_p + 2);
				j = pi[j - 1];
			}
		}
	}
	return v;
}

int main(void) {

	string text;
	string pattern;
	vector<int> v;

	getline(cin, text);
	getline(cin, pattern);

	int * pi = getPi(pattern);

	v = kmp(text, pattern, pi);

	cout << (int)v.size() << endl;
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}
#endif
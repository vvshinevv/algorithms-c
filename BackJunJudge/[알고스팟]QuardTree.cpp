/**
* [QUADTREE]https://algospot.com/judge/problem/read/QUADTREE
*/
#if 0
#include<iostream>
#include<string>
using namespace std;

string FuncQuard(string::iterator& it) {
	string::iterator head = it;
	++it;
	if (*head == 'b' || *head == 'w')
		return string(1, *head);

	string one = FuncQuard(it);
	string two = FuncQuard(it);
	string three = FuncQuard(it);
	string four = FuncQuard(it);

	return string("x") + three + four + one + two;
}

int main() {
	int c;
	string str;
	cin >> c;
	while (c--) {
		cin >> str;
		if (str[0] != 'x') {
			cout << str;
		}
		else {
			cout << FuncQuard(str.begin());
		}
		cout << endl;
	}
	return 0;
}
#endif
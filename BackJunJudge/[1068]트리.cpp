/**
* [Æ®¸®]https://www.acmicpc.net/problem/1068
*/
#if 0
#include <iostream>
#include <list>

using namespace std;

void removeNode(list<int> listArr[], int num) {
	if (listArr[num].empty())
		listArr[num].push_back(-1);
	else {
		while (!listArr[num].empty()) {
			int tmp = listArr[num].front();
			listArr[num].pop_front();
			removeNode(listArr, tmp);
		}
		listArr[num].push_back(-1);
	}
}

int main(void) {

	list<int> listArr[51];
	int cnt = 0, delNode;
	int num; cin >> num;

	for (int i = 0; i < num; i++) {
		int in; cin >> in;
		if (in != -1)
			listArr[in].push_back(i);
	}
	cin >> delNode;

	for (int i = 0; i < num; i++)
		listArr[i].remove(delNode);

	removeNode(listArr, delNode);

	for (int i = 0; i < num; i++) {
		if (listArr[i].empty())
			cnt++;
	}
	cout << cnt;

	return 0;
}

#endif
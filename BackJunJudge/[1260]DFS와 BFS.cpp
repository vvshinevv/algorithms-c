/**
* [DFS�� BFS]https://www.acmicpc.net/problem/1260
*/
#if 0
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

/**
* @brief: ���� ����� ����ϴ� �Լ�
* @param: bool visitArr[], int ver
*
* visitArr: ������ ���� �湮 ���θ� ��Ÿ���� �迭
* ver: �湮�� ���� ����
*/
void VisitVertex(bool visitArr[], int ver) {
	cout << ver << " ";
	visitArr[ver] = true;
}

/**
* @brief: ���� �켱 Ž��
* @param: vector<int> vecArr[], bool visitArr[], int num, int fir
*
* vecArr: �׷��� ��Ÿ���� �迭(by ���� ����Ʈ)
* visitArr: ī�� ���� �� �ߺ��� �����ϴ� ���� �迭
* num: ������ ����
* fir: ó�� �湮�� ���� ����
*/
void ShowDFS(vector<int> vecArr[], bool visitArr[], int num, int fir) {
	stack<int> stack;
	int visit = fir; // �湮 ���� ����

	for (int i = 0; i <= num; i++) // �湮 ���� ���� false
		visitArr[i] = false;

	stack.push(fir);
	VisitVertex(visitArr, fir);

	while (!stack.empty()) {

		bool visitFlag = false; // true: ������ ������ �湮, false: ������ ������ ��� �湮�� ���

		for (int i = 0; i < (int)vecArr[visit].size(); i++) {
			int next = vecArr[visit][i];
			if (visitArr[next] == false) {
				stack.push(next);
				VisitVertex(visitArr, next);
				visit = next;
				visitFlag = true;
				break;
			}
		}

		if (visitFlag == false) { // ������ ������ ��� �湮�� ������ ���� ����� ������ ����!
			stack.pop();
			if (!stack.empty()) {
				visit = stack.top();
			}
		}
	}
}

/**
* @brief: ���� �켱 Ž��
* @param: vector<int> vecArr[], bool visitArr[], int num, int fir
*
* vecArr: �׷��� ��Ÿ���� �迭(by ���� ����Ʈ)
* visitArr: ī�� ���� �� �ߺ��� �����ϴ� ���� �迭
* num: ������ ����
* fir: ó�� �湮�� ���� ����
*/
void ShowBFS(vector<int> vecArr[], bool visitArr[], int num, int fir) {
	queue<int> queue;
	int visit = fir;

	for (int i = 0; i <= num; i++)
		visitArr[i] = false;

	queue.push(fir);
	VisitVertex(visitArr, fir);
	while (!vecArr[visit].empty()) {
		for (int i = 0; i < (int)vecArr[visit].size(); i++) {
			int next = vecArr[visit][i];
			if (visitArr[next] == false) {
				queue.push(next);
				VisitVertex(visitArr, next);
			}
		}
		queue.pop();
		if (!queue.empty()) {
			visit = queue.front();
		}
		else {
			break;
		}
	}
}

int main(void) {

	int num[3];
	vector<int> vecArr[1001];

	for (int i = 0; i < 3; i++)
		cin >> num[i];

	bool * visitArr = (bool *)malloc(sizeof(bool) * (num[0] + 1)); // �湮 ���θ� �˻�

	for (int i = 0; i < num[1]; i++) {
		int one, two;
		cin >> one >> two;

		vecArr[one].push_back(two);
		vecArr[two].push_back(one);
	}

	for (int i = 1; i <= num[0]; i++)
		sort(vecArr[i].begin(), vecArr[i].end());

	ShowDFS(vecArr, visitArr, num[0], num[2]);
	cout << endl;
	ShowBFS(vecArr, visitArr, num[0], num[2]);
	cout << endl;
	free(visitArr);
	return 0;
}
#endif
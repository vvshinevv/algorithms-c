/**
* [DFS와 BFS]https://www.acmicpc.net/problem/1260
*/
#if 0
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

/**
* @brief: 정점 출력을 담당하는 함수
* @param: bool visitArr[], int ver
*
* visitArr: 정점에 대해 방문 여부를 나타내는 배열
* ver: 방문할 정점 변수
*/
void VisitVertex(bool visitArr[], int ver) {
	cout << ver << " ";
	visitArr[ver] = true;
}

/**
* @brief: 깊이 우선 탐색
* @param: vector<int> vecArr[], bool visitArr[], int num, int fir
*
* vecArr: 그래프 나타내는 배열(by 인접 리스트)
* visitArr: 카드 섞을 때 중복을 방지하는 기준 배열
* num: 정점의 개수
* fir: 처음 방문할 정점 변수
*/
void ShowDFS(vector<int> vecArr[], bool visitArr[], int num, int fir) {
	stack<int> stack;
	int visit = fir; // 방문 변수 선언

	for (int i = 0; i <= num; i++) // 방문 여부 전부 false
		visitArr[i] = false;

	stack.push(fir);
	VisitVertex(visitArr, fir);

	while (!stack.empty()) {

		bool visitFlag = false; // true: 인접한 정점에 방문, false: 인접한 정점을 모두 방문한 경우

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

		if (visitFlag == false) { // 인접한 정점에 모두 방문을 했으니 가장 가까운 곳으로 가자!
			stack.pop();
			if (!stack.empty()) {
				visit = stack.top();
			}
		}
	}
}

/**
* @brief: 넓이 우선 탐색
* @param: vector<int> vecArr[], bool visitArr[], int num, int fir
*
* vecArr: 그래프 나타내는 배열(by 인접 리스트)
* visitArr: 카드 섞을 때 중복을 방지하는 기준 배열
* num: 정점의 개수
* fir: 처음 방문할 정점 변수
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

	bool * visitArr = (bool *)malloc(sizeof(bool) * (num[0] + 1)); // 방문 여부를 검사

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
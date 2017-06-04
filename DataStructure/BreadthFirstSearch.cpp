#if 1
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void VisitVertex(bool visitArr[], int visit) {
	visitArr[visit] = true;
	cout << visit << " ";
}

void BreadthFirstSearch(vector<int> graph[], bool visitArr[], int fir, int cnt) {
	queue<int> queue;
	int visit = fir;

	for (int i = 1; i <= cnt; i++)
		visitArr[i] = false;

	queue.push(visit);
	VisitVertex(visitArr, visit);

	while (!queue.empty()) {
		
		for (int i = 0; i < (int)graph[visit].size(); i++) {
			int next = graph[visit][i];
			if (visitArr[next] == false) {
				VisitVertex(visitArr, next);
				queue.push(next);
			}
		}

		queue.pop();
		if (!queue.empty())
			visit = queue.front();

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

	DepthFirstSearch(vecArr, visitArr, num[2], num[0]);
	cout << endl;
	BreadthFirstSearch(vecArr, visitArr, num[2], num[0]);
	cout << endl;
	free(visitArr);
	return 0;
}

#endif
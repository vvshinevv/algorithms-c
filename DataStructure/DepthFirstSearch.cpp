#if 0
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void VisitVertex(bool visitArr[], int visit) {
	visitArr[visit] = true;
	cout << visit << " ";
}

void DepthFirstSearch(vector<int> graph[], bool visitArr[], int fir, int cnt) {
	stack<int> stack;
	int visit = fir;
	for (int i = 1; i <= cnt; i++)
		visitArr[i] = false;

	stack.push(visit);
	VisitVertex(visitArr, visit);

	while (!stack.empty()) {
		bool visitFlag = false;
		for (int i = 0; i < (int)graph[visit].size(); i++) {
			int next = graph[visit][i];
			if (visitArr[next] == false) {
				visit = next;
				stack.push(visit);
				visitFlag = true;
				VisitVertex(visitArr, visit);
			}
		}

		if (visitFlag == false) {
			stack.pop();
			if (!stack.empty())
				visit = stack.top();
		}
	}
}

int main(void) {
	vector<int> graph[1001];
	int num[3];
	for (int i = 0; i < 3; i++)
		cin >> num[i];

	bool * visitArr = (bool *)malloc(sizeof(bool) * (num[0] + 1));

	for (int i = 0; i < num[1]; i++) {
		int one, two;
		cin >> one >> two;

		graph[one].push_back(two);
		graph[two].push_back(one);
	}

	for (int i = 1; i <= num[0]; i++)
		sort(graph[i].begin(), graph[i].end());

	DepthFirstSearch(graph, visitArr, num[2], num[0]);
	return 0;
}
#endif
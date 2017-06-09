#include <queue>
#include <stack>
#include "Dijkstra.h"

using namespace std;

void InsertIntoMap(Adj * adj, string vertex, Weight weight) {
	Vertex * newVertex = new Vertex(vertex, weight, adj->head);
	adj->head = newVertex;
}

void ShowPath(unordered_map<string, string> path, unordered_map<string, int> distance, string sVer, string eVer) {
	stack<string> stack;
	cout << sVer << "에서 " << eVer << "까지 최단거리는 " << distance.find(eVer)->second << "입니다." << endl;
	while (path.find(eVer)->second != "NULL") {
		stack.push(eVer);
		eVer = path.find(eVer)->second;
	}
	stack.push(sVer);

	while (!stack.empty()) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;
}

Graph * MakeGraph() {
	int vertexCnt, edgeCnt;
	cout << "정점의 개수: "; cin >> vertexCnt;
	cout << "간선의 개수: "; cin >> edgeCnt;

	Graph * graph = new Graph(vertexCnt, edgeCnt);

	for (int i = 0; i < edgeCnt; i++) {
		string from, to; Weight weight;

		cout << "From: "; cin >> from;
		cout << "To: "; cin >> to;
		cout << "weight: "; cin >> weight;

		if (!graph->map.count(from)) { // map에 from이 없다면 추가
			Adj * adj = new Adj();
			graph->map.insert(pair<string, Adj *>(from, adj));
		}
		InsertIntoMap(graph->map.find(from)->second, to, weight);

		if (!graph->map.count(to)) {
			Adj * adj = new Adj();
			graph->map.insert(pair<string, Adj *>(to, adj));
		}
	}

	return graph;
}

void DijkstraAlgorithm(Graph * graph) {
	string sVertex, eVertex;

	cout << "출발 점: "; cin >> sVertex;
	cout << "도착 점: "; cin >> eVertex;
	priority_queue<Vertex *, vector<Vertex *>, Comp> pQ;

	unordered_map<string, string> path;
	unordered_map<string, int> distance;

	Vertex * startVertex = new Vertex(sVertex, 0, NULL);

	path.insert(pair<string, string>(startVertex->name, "NULL")); // 시작 점
	distance.insert(pair<string, int>(startVertex->name, 0));

	pQ.push(startVertex);

	while (!pQ.empty()) {
		Vertex * saveVertex = new Vertex(pQ.top()->name, pQ.top()->weight, pQ.top()->next);
		Vertex * nextVertex = graph->map.find(saveVertex->name)->second->head; // saveVertex와 인접한 vertex를 가르키는 포인터
		pQ.pop();

		while (nextVertex != NULL) {
			Weight minWeight = distance.find(saveVertex->name)->second + nextVertex->weight;

			if (!distance.count(nextVertex->name)) {
				// 방문하지 않은 vertex라면
				path.insert(pair<string, string>(nextVertex->name, saveVertex->name));
				distance.insert(pair<string, int>(nextVertex->name, minWeight));
				pQ.push(nextVertex);
			}
			else {
				if (distance.find(nextVertex->name)->second > minWeight) {
					path.find(nextVertex->name)->second = saveVertex->name;
					distance.find(nextVertex->name)->second = minWeight;
				}
			}
			nextVertex = nextVertex->next;
		}
	}
	ShowPath(path, distance, sVertex, eVertex);
}

int main(void) {
	Graph * graph = MakeGraph();
	DijkstraAlgorithm(graph);

	return 0;
}
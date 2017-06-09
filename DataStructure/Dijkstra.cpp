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
	cout << sVer << "���� " << eVer << "���� �ִܰŸ��� " << distance.find(eVer)->second << "�Դϴ�." << endl;
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
	cout << "������ ����: "; cin >> vertexCnt;
	cout << "������ ����: "; cin >> edgeCnt;

	Graph * graph = new Graph(vertexCnt, edgeCnt);

	for (int i = 0; i < edgeCnt; i++) {
		string from, to; Weight weight;

		cout << "From: "; cin >> from;
		cout << "To: "; cin >> to;
		cout << "weight: "; cin >> weight;

		if (!graph->map.count(from)) { // map�� from�� ���ٸ� �߰�
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

	cout << "��� ��: "; cin >> sVertex;
	cout << "���� ��: "; cin >> eVertex;
	priority_queue<Vertex *, vector<Vertex *>, Comp> pQ;

	unordered_map<string, string> path;
	unordered_map<string, int> distance;

	Vertex * startVertex = new Vertex(sVertex, 0, NULL);

	path.insert(pair<string, string>(startVertex->name, "NULL")); // ���� ��
	distance.insert(pair<string, int>(startVertex->name, 0));

	pQ.push(startVertex);

	while (!pQ.empty()) {
		Vertex * saveVertex = new Vertex(pQ.top()->name, pQ.top()->weight, pQ.top()->next);
		Vertex * nextVertex = graph->map.find(saveVertex->name)->second->head; // saveVertex�� ������ vertex�� ����Ű�� ������
		pQ.pop();

		while (nextVertex != NULL) {
			Weight minWeight = distance.find(saveVertex->name)->second + nextVertex->weight;

			if (!distance.count(nextVertex->name)) {
				// �湮���� ���� vertex���
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
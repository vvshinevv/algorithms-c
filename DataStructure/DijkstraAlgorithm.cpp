#if 1
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

typedef int Weight;

typedef struct _vErtex {
	string name;
	Weight weight;
	struct _vErtex * next;
	void MakeVertex(string _name, Weight _weight) { name = _name;  weight = _weight; next = NULL; }
} Vertex;

typedef struct _aDj {
	Vertex * head;
	Vertex * cur;
	_aDj() { head = cur = NULL; }
} Adj;

typedef struct _gRaph {
	int vertexCnt;
	int edgeCnt;
	unordered_map<string, Adj *> adj;
	_gRaph(int _vertexCnt, int _edgeCnt) : vertexCnt(_vertexCnt), edgeCnt(_edgeCnt) {}
} Graph;

typedef struct _cOmp {
	bool operator() (Vertex vertex1, Vertex vertex2) {
		return vertex1.weight > vertex2.weight;
	}
} Comp;

void InsertIntoAdj(Adj * adj, string vertex, Weight weight) {
	Vertex * newVertex = new Vertex();
	newVertex->name = vertex;
	newVertex->weight = weight;

	newVertex->next = adj->head;
	adj->head = newVertex;
}

void ShowPath(unordered_map<string, string> path, string end) {
	stack<string> stack;

	if (!path.count(end)) {
		cout << "��ΰ� �����ϴ�." << endl;
	}
	else {
		while (path.find(end)->second != "NULL") {
			stack.push(end);
			end = path.find(end)->second;
		}
		stack.push(end);
	}

	while (!stack.empty()) {
		cout << stack.top() << " " << endl;
		stack.pop();
	}
}

Graph * makeGraph() {
	int vertexCnt, edgeCnt;
	cout << "������ ����: "; cin >> vertexCnt;
	cout << "������ ����: "; cin >> edgeCnt;

	Graph * graph = new Graph(vertexCnt, edgeCnt);
	for (int i = 0; i < edgeCnt; i++) {
		string from, to; Weight weight;

		cout << "From: "; cin >> from;
		cout << "To: "; cin >> to;
		cout << "Weight: "; cin >> weight;

		if (!graph->adj.count(from)) {
			// vertex�� graph�� ���ٸ�...
			Adj * adj = new Adj();
			graph->adj.insert(pair<string, Adj *>(from, adj));
		}
		InsertIntoAdj((graph->adj.find(from))->second, to, weight);

		if (!graph->adj.count(to)) {
			Adj * adj = new Adj();
			graph->adj.insert(pair<string, Adj *>(to, adj));
		}
	}
	return graph;
}

void DijkstraAlgorith(Graph * graph) {
	string startVertex, endVertex;
	cout << "������ �Է�: "; cin >> startVertex;
	cout << "������ �Է�: "; cin >> endVertex;
	unordered_map<string, string> path;
	unordered_map<string, Weight> distance;
	priority_queue < Vertex, vector<Vertex>, Comp > pQ;

	Vertex vertex;
	vertex.MakeVertex(startVertex, 0);

	distance.insert(pair<string, Weight>(startVertex, 0));
	path.insert(pair<string, string>(startVertex, "NULL"));

	pQ.push(vertex);

	while (!pQ.empty()) {
		vertex.name = pQ.top().name; pQ.pop();

		Vertex * cur = graph->adj.find(vertex.name)->second->head;

		while (cur != NULL) {
			int minWeight = distance.find(vertex.name)->second + cur->weight;

			if (!distance.count(cur->name)) {
				Vertex curVertex;
				curVertex.MakeVertex(cur->name, cur->weight);

				distance.insert(pair<string, Weight>(cur->name, minWeight));
				path.insert(pair<string, string>(cur->name, vertex.name));

				pQ.push(curVertex);
			}
			else {
				if (minWeight < distance.find(cur->name)->second)
					distance.find(cur->name)->second = minWeight;

				path.find(cur->name)->second = vertex.name;
			}
			cur = cur->next;
		}
	}
	cout << startVertex << "���� " << endVertex << "���� �ִܰŸ�: " << distance.find(endVertex)->second << endl;
	ShowPath(path, endVertex);
}



int main(void) {
	Graph * graph = makeGraph();
	DijkstraAlgorith(graph);
	return 0;
}
#endif
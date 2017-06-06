#if 0
#include <iostream>
#include <queue>

using namespace std;

typedef char SetData;
typedef int wData;

typedef struct _gRaph {
	int vertexCnt;
	int edgeCnt;
} Graph;

typedef struct _eDge {
	SetData ver1;
	SetData ver2;
	wData weight;
} Edge;

typedef struct _dIsJointSet {
	SetData data;
	int rank;
	struct _dIsJointSet * parent;
} DisJointSet;

typedef struct _cOmp {
	bool operator() (Edge edge1, Edge edge2) {
		return edge1.weight > edge2.weight;
		// 참 : edge2의 우선순위가 높다.(=edge2의 값이 더 낮다)
		// 거짓: edge1의 우선순위가 높다.(=edge1의 값이 더 낮다)
	}
} Comp;

static int totalWeight = 0;

priority_queue<Edge, vector<Edge>, Comp> pQ;
DisJointSet ** dJs;


DisJointSet * MakeDisJointSet(SetData data) {
	DisJointSet * dJs = (DisJointSet *)malloc(sizeof(DisJointSet));
	dJs->parent = dJs;
	dJs->rank = 0;
	dJs->data = data;

	return dJs;
}

DisJointSet * FindDisJointSet(DisJointSet * dJs) {
	if (dJs->parent == dJs)
		return dJs;

	return dJs->parent = FindDisJointSet(dJs->parent);
}

void UnionDisJointSet(DisJointSet * dJs1, DisJointSet * dJs2) {
	DisJointSet * parent1 = FindDisJointSet(dJs1);
	DisJointSet * parent2 = FindDisJointSet(dJs2);

	if (parent1 != parent2) {
		if (parent1->rank >= parent2->rank) {
			if (parent1->rank == parent2->rank)
				parent1->rank++;

			parent2->parent = parent1;
		}
		else {
			parent1->parent = parent2;
		}
	}
}

void PrintDisJointSet(DisJointSet * dJs[]) {
	for (int i = 0; i < 10; i++)
		cout << i << "의 부모: " << dJs[i]->parent->data << endl;
}

Graph * CreateGraph() {

	Graph * graph = (Graph *)malloc(sizeof(Graph));
	cout << "정점의 개수: "; cin >> graph->vertexCnt;
	cout << "간선의 개수: "; cin >> graph->edgeCnt;

	dJs = (DisJointSet **)malloc(sizeof(DisJointSet*) * (graph->vertexCnt));
	for (int i = 0; i < graph->vertexCnt; i++) {
		dJs[i] = (DisJointSet *)malloc(sizeof(DisJointSet));
		dJs[i] = MakeDisJointSet((char)i + 'A');
	}

	for (int i = 0; i < graph->edgeCnt; i++) {
		Edge edge;
		cin >> edge.ver1; cin >> edge.ver2; cin >> edge.weight;

		pQ.push(edge);
	}
	return graph;
}

void Kruscal(Graph * graph) {
	while (!pQ.empty()) {
		Edge edge = pQ.top();
		if (FindDisJointSet(dJs[(int)edge.ver1 - 'A']) != FindDisJointSet(dJs[(int)edge.ver2 - 'A'])) {
			UnionDisJointSet(dJs[(int)edge.ver1 - 'A'], dJs[(int)edge.ver2 - 'A']);
			totalWeight += edge.weight;
		}
		pQ.pop();
	}
}



int main(void) {
	Graph * graph = CreateGraph();
	Kruscal(graph);
	cout << "Total Weight: " << totalWeight << endl;
	return 0;
}
#endif
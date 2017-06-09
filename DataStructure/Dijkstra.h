#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__
#include <iostream>
#include <string>
#include <unordered_map>

typedef int Weight;

typedef struct _vErtex {
	string name;
	Weight weight;
	struct _vErtex * next;

	_vErtex(string _n, Weight _w, struct _vErtex * _nt) : name(_n), weight(_w), next(_nt) {}
} Vertex;

typedef struct _aDj {
	Vertex * head;
	Vertex * cur;

	struct _aDj() { head = cur = NULL; }
} Adj;

typedef struct _gRaph {
	int vertexCnt;
	int edgeCnt;
	unordered_map<string, Adj *> map;

	struct _gRaph(int _v, int _e) : vertexCnt(_v), edgeCnt(_e) {}
}Graph;

typedef struct _cOmp {
	bool operator() (Vertex * vertex1, Vertex * vertex2) {
		return vertex1->weight > vertex2->weight;
	}
} Comp;

void InsertIntoMap(Adj * adj, string vertex, Weight weight);
void ShowPath(unordered_map<string, string> path, unordered_map<string, int> distance, string sVer, string eVer);
Graph * MakeGraph();
void DijkstraAlgorithm(Graph * graph);

#endif

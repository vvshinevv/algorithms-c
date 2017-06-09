#include "Dijkstra.h"

int main(void) {
	Graph * graph = MakeGraph();
	DijkstraAlgorithm(graph);

	return 0;
}
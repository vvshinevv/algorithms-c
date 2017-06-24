#if 0
#include <iostream>

using namespace std;

typedef int Data;

typedef struct _dIsJointSet {
	int data;
	int rank;
	struct _dIsJointSet * parent;
} DisJointSet;

DisJointSet * MakeDisJointSet(Data data) {
	DisJointSet * dJs = (DisJointSet *)malloc(sizeof(DisJointSet));
	dJs->data = data;
	dJs->parent = dJs;
	dJs->rank = 0;

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
		cout << i << "ÀÇ ºÎ¸ð: " << dJs[i]->parent->data << endl;
}


int main(void) {
	DisJointSet * dJs[10];

	for (int i = 0; i < 10; i++)
		dJs[i] = MakeDisJointSet(i);

	UnionDisJointSet(dJs[1], dJs[2]);

	PrintDisJointSet(dJs);

	return 0;
}
#endif
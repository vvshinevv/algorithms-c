/**
* [트리 순회]https://www.acmicpc.net/problem/1991
*/
#if 0

#include <iostream>
#include "BinaryTree.h"

using namespace std;

void PrintTraversal(BTData data);

int main(void) {

	int num;
	cin >> num;

	BTreeNode ** bt = (BTreeNode **)malloc(sizeof(BTreeNode*) * num);

	bt[0] = MakeBTreeNode();
	SetData(bt[0], 'A');

	for (int i = 0; i < num; i++) {
		char one, two, three;
		cin >> one >> two >> three;

		if (two != '.') {
			bt[two - 'A'] = MakeBTreeNode();
			SetData(bt[two - 'A'], two);
			MakeLeftBTreeNode(bt[one - 'A'], bt[two - 'A']);
		}

		if (three != '.') {
			bt[three - 'A'] = MakeBTreeNode();
			SetData(bt[three - 'A'], three);
			MakeRightBTreeNode(bt[one - 'A'], bt[three - 'A']);
		}
	}

	PreOrderTraversal(bt[0], PrintTraversal); cout << endl;
	InOrderTraversal(bt[0], PrintTraversal); cout << endl;
	PostOrderTraversal(bt[0], PrintTraversal); cout << endl;

	free(bt);
	return 0;
}

void PrintTraversal(BTData data) {
	cout << data << " ";
}

#endif

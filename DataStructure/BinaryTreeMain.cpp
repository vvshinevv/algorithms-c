#if 0
#include <iostream>
#include "BinaryTree.h"

using namespace std;
void PrintData(BTData data) {
	cout << data << " ";
}
int main(void) {
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();

	SetData(bt1, 1); SetData(bt2, 2);
	SetData(bt3, 3); SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	PreOrderTraverse(bt1, PrintData); cout << endl;
	InOrderTraverse(bt1, PrintData); cout << endl;
	PostOrderTravese(bt1, PrintData); cout << endl;


	return 0;
}
#endif
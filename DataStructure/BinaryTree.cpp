#include <iostream>
#include "BinaryTree.h"
using namespace std;
BTreeNode * MakeBTreeNode(void) {
	BTreeNode * newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
	newNode->left = newNode->right = NULL;

	return newNode;
}
BTData GetData(BTreeNode * bt) {
	return bt->data;
}
void SetData(BTreeNode * bt, BTData data) {
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt) {
	return bt->left;
}
BTreeNode * GetRightSubTree(BTreeNode * bt) {
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub) {
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub) {
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}

void PreOrderTraverse(BTreeNode * root, VisitFuncPtr action) {
	if (root == NULL)
		return;

	action(root->data);
	PreOrderTraverse(root->left, action);
	PreOrderTraverse(root->right, action);
}
void InOrderTraverse(BTreeNode * root, VisitFuncPtr action) {
	if (root == NULL)
		return;

	InOrderTraverse(root->left, action);
	action(root->data);
	InOrderTraverse(root->right, action);
}
void PostOrderTravese(BTreeNode * root, VisitFuncPtr action) {
	if (root == NULL)
		return;

	PostOrderTravese(root->left, action);
	PostOrderTravese(root->right, action);
	action(root->data);
}
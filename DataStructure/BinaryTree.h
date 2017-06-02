#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef char BTData;

typedef struct _bTreeNode {
	struct _bTreeNode * left;
	BTData data;
	struct _bTreeNode * right;
} BTreeNode;

BTreeNode * MakeBTreeNode(void);
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);

typedef void VisitFuncPtr(BTData data);

void PreOrderTraverse(BTreeNode * root, VisitFuncPtr action);
void InOrderTraverse(BTreeNode * root, VisitFuncPtr action);
void PostOrderTravese(BTreeNode * root, VisitFuncPtr action);
#endif
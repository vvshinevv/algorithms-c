#ifndef __MAKE_EXP_TREE_H__
#define __MAKE_EXP_TREE_H__

#include "BinaryTree.h"

BTreeNode * MakeExpTree(char exp[]);

int EvaluateExpTree(BTreeNode * bt);

void ShowPrefixTypeExp(BTreeNode * bt);
void ShowPostifxTypeExp(BTreeNode * bt);
void ShowInfixTypeExp(BTreeNode * bt);

#endif
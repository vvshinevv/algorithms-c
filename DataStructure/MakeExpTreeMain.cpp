#if 0
#include <iostream>
#include "MakeExpTree.h"
using namespace std;
int main(void) {
	char exp[] = "12+7*";
	BTreeNode * eTree = MakeExpTree(exp);

	ShowInfixTypeExp(eTree); cout << endl;
	ShowPostifxTypeExp(eTree); cout << endl;
	ShowPrefixTypeExp(eTree); cout << endl;

	cout << EvaluateExpTree(eTree);
	return 0;
}
#endif